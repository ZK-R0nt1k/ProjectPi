uint8_t ball_size = 3;
uint8_t ball_speed = 2;
uint8_t bot_desk_speed = 1;
uint8_t player_desk_speed = 2; 

int ball_speed_x = 1;
int ball_speed_y = -1;
bool bot_move_flag;

uint8_t bot_count = 0;
uint8_t player_count = 0;

bool pause = false;
bool special_pause = false;

Point ball[1] = {64, 32};

uint32_t get_rand_32() {
    return static_cast<uint32_t>(std::rand());
}

void init_ping_pong(){
    clear_all_layers();
    layers[1].add_shape_prefab(new Square_Prefab(2, 32, 2, 22 - ball_size));
    layers[1].add_shape_prefab(new Square_Prefab(121, 32, 2, 16));
    layers[1].add_shape_prefab(new Square_Prefab(ball[0].x, ball[0].y, ball_size, ball_size));
}

void win_screen(){
    layers[4].add_shape_prefab(new Triangle_Prefab(63, 31, 1, 1));
    for (uint8_t i = 4; i < 60; i++){
        layers[4].shapes_prefabs[0]->change_size(i, i);
        draw_layer(4);
        SSD1306_send_screen();
        sleep_ms(10);
    }
    clear_layer(4);
    special_pause = false;
    ball_size = 2;
    layers[1].shapes_prefabs[0]->change_size(2, 22);
}

void control(){
    if (key_is_pressed(2) && layers[1].shapes_prefabs[1]->get_position().y < 56){
        layers[1].shapes_prefabs[1]->move(0, player_desk_speed);
    }
    if (key_is_pressed(8) && layers[1].shapes_prefabs[1]->get_position().y > 10){
        layers[1].shapes_prefabs[1]->move(0, -player_desk_speed);
    }
}

void restart_game(){
    layers[1].shapes_prefabs[2]->move_to(64, 32);
    if((get_rand_32() % 2) >= 1){
        ball_speed_x = 1;
    }
    else{
        ball_speed_x = -1;
    }
    if((get_rand_32() % 2) >= 1){
        ball_speed_y = (uint8_t)(1 + (get_rand_32() % 2));
    }
    else{
        ball_speed_y = -(uint8_t)(1 + (get_rand_32() % 2));
    }
}

void ball_game(){
    ball[0] = layers[1].shapes_prefabs[2]->get_position();
    if(layers[1].shapes_prefabs[0]->is_inside(ball[0].x, ball[0].y)){
        ball_speed_x = (uint8_t)(1 + (get_rand_32() % 2));
    }
    if(layers[1].shapes_prefabs[1]->is_inside(ball[0].x, ball[0].y)){
        ball_speed_x = -(uint8_t)(1 + (get_rand_32() % 2));
    }
    if (ball[0].y > 61){
        ball_speed_y = -(uint8_t)(1 + (get_rand_32() % ball_speed));
    }
    if(ball[0].y < 4 + ball_size * 0.5){
        ball_speed_y = (uint8_t)(1 + (get_rand_32() % ball_speed));
    }
    if (ball[0].x > 121){
        bot_count++;
        restart_game();
    }
    if (ball[0].x < 2){
        if (player_count == 9 && !special_pause){
            special_pause = true;
            win_screen();
        }
        player_count++;
        restart_game();
    }
    layers[1].shapes_prefabs[2]->move(ball_speed_x, ball_speed_y);
}

void bot(){
    if (layers[1].shapes_prefabs[0]->get_position().y > 53){
        bot_move_flag = false;
    }
    if (layers[1].shapes_prefabs[0]->get_position().y < 12){
        bot_move_flag = true;
    }
    if (bot_move_flag){
        layers[1].shapes_prefabs[0]->move(0, bot_desk_speed);
    }
    else{
        layers[1].shapes_prefabs[0]->move(0, -bot_desk_speed);
    }
}
void count(){
    clear_layer(3);
    draw_roman_number(player_count, 110, 56, 3);
    draw_roman_number(bot_count, 4, 56, 3);
}

void game(){
    if(key_is_pressed(1)){
        pause = !pause;
    }
    if(!pause && !special_pause){
    control();
    ball_game();
    bot();
    count();
    draw_layer(1);
    draw_layer(3);
    SSD1306_send_screen();
    buffer_clear();
    }
}