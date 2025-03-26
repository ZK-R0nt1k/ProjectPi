uint64_t start_time;
uint32_t wait_time = 0;
uint8_t wait_hours = 8;
uint8_t wait_minutes = 10;

void set_timer_hours(uint8_t hours){
    wait_hours = hours;
}

void set_timer_minutes(uint8_t minutes){
    while(minutes >= 60){
        wait_hours++;
        minutes -= 60;
    }
    wait_minutes = minutes;
}

bool start_timer_flag = false;
void start_timer(){
    if(!start_timer_flag){
    wait_time = wait_hours * 3600 + wait_minutes * 60;
    start_timer_flag = true;
    start_time = time_us_64();
    layers[2].add_shape(new Line (0,63,123,63));
    }
    if(start_time + 1000000 < time_us_64()){
        SSD1306_send_cmd(0xAE);
    }
}

bool last_hour = false;
bool check_time(){
    if (wait_time * 1000 + start_time - 3600000 < time_us_64() && start_timer_flag){
        last_hour = true;
        return true;
    }
    return false;
}

void update_light_level(){
    if (last_hour){
        pwm_set_gpio_level(0, (time_us_64()/(wait_time * 10000 + start_time) * 65535));
    }
}

void draw_wait_time(){
    clear_layer(3);
    //draw_roman_number(wait_hours, 48, 28, 3);
    //draw_roman_number(wait_minutes, 70, 28, 3);
    //if (start_timer_flag) icon_draw_play(112, 8, 3, 0);
    //else icon_draw_stop(112, 8, 3, 0);
    draw_layers();
}