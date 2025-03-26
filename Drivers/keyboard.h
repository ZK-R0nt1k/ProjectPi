
uint8_t button_status[12] = {0};
char SHIFT_REG_B;
char SHIFT_REG_CLK;
char SHIFT_REG_COL_A;
char SHIFT_REG_COL_B;
char SHIFT_REG_COL_C;

void init_keyboar_shift_register(uint8_t shift_reg_B, uint8_t shift_reg_CLK){
    SHIFT_REG_B = shift_reg_B;
    SHIFT_REG_CLK = shift_reg_CLK;
    gpio_init(shift_reg_CLK);
    gpio_init(shift_reg_B); 
    gpio_set_dir(shift_reg_CLK, GPIO_OUT);
    gpio_set_dir(shift_reg_B, GPIO_OUT);
    gpio_pull_down(shift_reg_CLK);
    gpio_pull_down(shift_reg_B);
}

void init_button_collums(uint8_t A, uint8_t B, uint8_t C){
    SHIFT_REG_COL_A = A;
    SHIFT_REG_COL_B = B;
    SHIFT_REG_COL_C = C;
    gpio_init(A);
    gpio_init(B);
    gpio_init(C);
    gpio_set_dir(A, GPIO_IN);
    gpio_set_dir(B, GPIO_IN);
    gpio_set_dir(C, GPIO_IN);
    gpio_pull_up(A);
    gpio_pull_up(B);
    gpio_pull_up(C);
}

void send_status_shift_reg(bool shift_reg_status){
    gpio_put(SHIFT_REG_B, shift_reg_status);
    gpio_put(SHIFT_REG_CLK, false);
    gpio_put(SHIFT_REG_CLK, true);
    gpio_put(SHIFT_REG_CLK, false);
    gpio_put(SHIFT_REG_B, false);
}

void buttons_check(uint8_t row){
    uint8_t col_value = (!gpio_get(SHIFT_REG_COL_A) ? 1 : 0) 
                      | (!gpio_get(SHIFT_REG_COL_B) ? 2 : 0) 
                      | (!gpio_get(SHIFT_REG_COL_C) ? 4 : 0);
    for (uint8_t i = 0; i < 3; i++) {
        button_status[row * 3 + i] = col_value & (1 << i);
    }
}

void get_keyboard_stautus(){
    for (uint8_t i = 0; i < 12; i++){
        button_status[i] = 0;
    }
    send_status_shift_reg(true);
    for(uint8_t i = 0; i < 4; i++){
        sleep_us(1);
        buttons_check(i);
        send_status_shift_reg(false);
        sleep_us(1);
    }
}

void keyboard_set_all(bool status){
    for (uint8_t i; i < 12; i++){
        button_status[i] = status;
    }
}

bool key_is_pressed(uint8_t key){
    if (button_status[key - 1]){
        return true;
    }
    else{
        return false;
    }
}

bool key_is_unpressed(uint8_t key){
    if (button_status[key - 1]){
        return false;
    }
    else{
        return true;
    }
}

bool key_click_on(uint8_t check_clicked_key){
    if(key_is_pressed(check_clicked_key) && (button_status[check_clicked_key] & 0b11) == 0b01){
        button_status[check_clicked_key] |= (1 << 1);
        button_status[check_clicked_key] |= (0 << 0);
        return true;
    }
    else if(!key_is_pressed(check_clicked_key) && (check_clicked_key & 0b11) == 0b10){
        button_status[check_clicked_key] |= (0 << 1);
        return false;
    }   
    return false;
} 