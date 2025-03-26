int cursor_position_x = 64;
int cursor_position_y = 32;

void create_cursor(){
    layers[0].add_shape(new Cursor(cursor_position_x, cursor_position_y));
}

void move_cursor_up(){
    cursor_position_y++;
    if (auto it = layers[1].shapes.find(0); it != layers[1].shapes.end()) {
        it->second->move_to(cursor_position_x, cursor_position_y);
    }
}

void move_cursor_down(){
    cursor_position_y--;
    if (auto it = layers[1].shapes.find(0); it != layers[1].shapes.end()) {
        it->second->move_to(cursor_position_x, cursor_position_y);
    }
}

void move_cursor_right(){
    cursor_position_x++;
    if (auto it = layers[1].shapes.find(0); it != layers[1].shapes.end()) {
        it->second->move_to(cursor_position_x, cursor_position_y);
    }
}

void move_cursor_left(){
    cursor_position_x--;
    if (auto it = layers[1].shapes.find(0); it != layers[1].shapes.end()) {
        it->second->move_to(cursor_position_x, cursor_position_y);
    }
}

bool rectangle_flag = false;
    static int x0_rectangle;
    static int y0_rectangle;
    static int x1_rectangle;
    static int y1_rectangle;
    uint32_t timer_f;
void set_rectangle(){
    if (!rectangle_flag){
        x0_rectangle = cursor_position_x;
        y0_rectangle = cursor_position_y;
        rectangle_flag = true;
        timer_f = time_us_32();
    }
    if(rectangle_flag && time_us_32() > timer_f + 1000000){
        x1_rectangle = cursor_position_x;
        y1_rectangle = cursor_position_y;
        timer_f = time_us_32();
        rectangle_flag = false;
        //layers[2].add_shape(new Rectangle(x0_rectangle ,y0_rectangle ,x1_rectangle ,y1_rectangle));
    }
}

bool circle_flag;
static uint16_t x_circle;
static uint16_t y_circle;
static uint16_t R_circle;
void set_circle(){
    if (!circle_flag){
        circle_flag = false;
        x_circle = cursor_position_x;
        y_circle = cursor_position_y;
        timer_f = time_us_32();
    }
    if(circle_flag && time_us_32() > timer_f + 1000000){
        R_circle = sqrt(pow(x_circle - cursor_position_x, 2) + pow(y_circle - cursor_position_y, 2));
        timer_f = time_us_32();
    }
}

static uint16_t x0_triangle;
static uint16_t y0_triangle;
static uint16_t x1_triangle;
static uint16_t y1_triangle;
static uint16_t x2_triangle;
static uint16_t y2_triangle;
static uint8_t step = 0;
void set_triangle(){
    if (step == 0){
        x0_triangle = cursor_position_x;
        y0_triangle = cursor_position_y;
        step++;
    }
    if (step == 1){
        x1_triangle = cursor_position_x;
        y1_triangle = cursor_position_y;
        step++;
    }
    if(step == 2){
        x2_triangle = cursor_position_x;
        y2_triangle = cursor_position_y;
        step = 0;
        //layers[2].add_shape(new Triangle(x0_triangle, y0_triangle, x1_triangle, y1_triangle, x2_triangle, y2_triangle));
    }
}

void buttons_poll(){
    if (key_is_pressed(1)){
    }
    if (key_is_pressed(2)){
        move_cursor_up();
    }
    if (key_is_pressed(3)){

    }
    if (key_is_pressed(4)){
        move_cursor_left();
    }
    if (key_is_pressed(5)){

    }
    if (key_is_pressed(6)){
        move_cursor_right();
    }
    if (key_is_pressed(7)){

    }
    if (key_is_pressed(8)){
        move_cursor_down();
    }
    if (key_is_pressed(9)){

    }
    if (key_is_pressed(10)){

    }
    if (key_is_pressed(11)){

    }
    if (key_is_pressed(12)){

    }
}
/*uint8_t check_UI_figure(){
    if(menu_figure_flag){
        
    }
}*/