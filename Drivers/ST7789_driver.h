
void ST7789_reset(){gpio_put(RST_PIN, false);sleep_ms(100);gpio_put(RST_PIN, true);sleep_ms(100);}

//#if defined(spi_default) && defined(PICO_DEFAULT_SPI_CSN_PIN)
void ST7789_init_SPI(){
        spi_init(SPI_PORT, 100000);  
        
        gpio_set_function(SPI_SCK_PIN, GPIO_FUNC_SPI);  // Настройка SCK
        gpio_set_function(SPI_MOSI_PIN, GPIO_FUNC_SPI); // Настройка MOSI
    
        gpio_init(DC_PIN);
        gpio_set_dir(DC_PIN, GPIO_OUT);  

        gpio_init(RST_PIN);
        gpio_set_dir(RST_PIN, GPIO_OUT);
}

void ST7789_send_data_byte(uint16_t byte) {
    gpio_put(DC_PIN, true);  // DC = 1 (данные)
    uint8_t buf[3] = {ST7789_RAMWR,0xFa,0xaF};
    spi_write_blocking(spi0, buf, 3);
}

void ST7789_send_cmd(uint8_t cmd) {
    gpio_put(DC_PIN, false);  // DC = 0 (команда)
    uint8_t buf[1] = {cmd};
    spi_write_blocking(spi0, buf, 1);
}

void ST7789_send_data(uint8_t *data, int length) {
    gpio_put(DC_PIN, true);  // DC = 1 (данные)
    spi_write_blocking(spi0, data, length);
}

void ST7789_send_cmd_list(uint8_t *cmds, int num) {
    for (int i = 0; i < num; i++) {
        ST7789_send_cmd(cmds[i]);
    }
}

void ST7789_init() {
    
    ST7789_reset(); 
    sleep_ms(500);
    ST7789_send_cmd(ST7789_SWRESET);  // Программный сброс
    sleep_ms(150);
    
    ST7789_send_cmd(ST7789_SLPOUT);   // Выход из режима сна
    sleep_ms(500);
    
    ST7789_send_cmd(ST7789_COLMOD);   // Формат пикселя
    uint8_t colmod_data[] = {0x55};   // 16 бит (RGB565)
    //ST7789_send_data(colmod_data, 1);
    ST7789_send_cmd(0x55);
    sleep_ms(150);
    
    ST7789_send_cmd(ST7789_MADCTL);   // Ориентация изображения
    uint8_t madctl_data[] = {0x08};   // 0x00 - стандартная
    //ST7789_send_data(madctl_data, 1);
    ST7789_send_cmd(0x08);
    sleep_ms(150);
    
    ST7789_send_cmd(ST7789_CASET);    // Установка области по X (0-239)
    uint8_t caseset_data[] = {0x00, 0x00, 0x00, 0xEF};
    //ST7789_send_data(caseset_data, 4);
    ST7789_send_cmd(0);
    ST7789_send_cmd(0);
    ST7789_send_cmd(0);
    ST7789_send_cmd(0xEF);
    sleep_ms(150);
    
    ST7789_send_cmd(ST7789_RASET);    // Установка области по Y (0-239)
    uint8_t raseset_data[] = {0x00, 0x00, 0x00, 0xEF};
    //ST7789_send_data(raseset_data, 4);
    ST7789_send_cmd(0);
    ST7789_send_cmd(0);
    ST7789_send_cmd(0);
    ST7789_send_cmd(0xEF);
    sleep_ms(150);

    /*ST7789_send_cmd(ST7789_RAMWR);
    sleep_ms(150);
    ST7789_send_cmd(ST7789_VDVVRHEN);
    uint8_t vdvvrhen_data [1] = {0x01};
    ST7789_send_data(vdvvrhen_data,1);
    sleep_ms(150);

    ST7789_send_cmd(ST7789_VRHS);
    uint8_t vrhs_data [1] = {0x0B};
    ST7789_send_data(vrhs_data,1);
    sleep_ms(150);

    ST7789_send_cmd(ST7789_VCOMS);    // Настройка VCOM
    uint8_t vcoms_data[] = {0x20};    // Напряжение VCOM = 1.625V
    ST7789_send_data(vcoms_data, 1);
    sleep_ms(150);

    ST7789_send_cmd(ST7789_PORCTRL);  // Porch control
    uint8_t porch_data[] = {0x0C, 0x0C, 0x00, 0x33, 0x33};
    ST7789_send_data(porch_data, 5);
    sleep_ms(150);
    
    ST7789_send_cmd(ST7789_FRCTRL2);  // Frame rate control
    uint8_t frctrl_data[] = {0x0F};
    ST7789_send_data(frctrl_data, 1);
    sleep_ms(150);

    ST7789_send_cmd(ST7789_GCTRL);    // Gate control
    uint8_t gctrl_data[] = {0x35};    // VGH=13.26V, VGL=-10.43V
    ST7789_send_data(gctrl_data, 1);
    sleep_ms(150);
*/  ST7789_send_cmd(ST7789_INVON);    // Нормальный режим дисплея
    sleep_ms(10);
    ST7789_send_cmd(ST7789_NORON);    // Нормальный режим дисплея
    sleep_ms(10);
    
    ST7789_send_cmd(ST7789_DISPON);   // Включение дисплея
    sleep_ms(100);

 /*   ST7789_send_cmd(0x51);  // Команда для настройки яркости (CTRLD)
uint8_t brightness = 0x80; // Уровень яркости (0x00 - минимальная яркость, 0xFF - максимальная яркость)
ST7789_send_data(&brightness, 1); // Передаем данные яркости

ST7789_send_cmd(0x53);  // Команда для настройки яркости подсветки 
ST7789_send_data(&brightness, 1); // Передаем данные яркости подсветки
*/
    ST7789_send_cmd(ST7789_RAMWR);
}

void ST7789_get_status(){
    ST7789_send_cmd(ST7789_RDDST);
}


void ST7789_fill_screen(uint16_t color) {
    uint8_t color_hi = (color >> 8) & 0xFF;  // старший байт цвета
    uint8_t color_lo = color & 0xFF;         // младший байт цвета
    printf("ST7789_fill_screen младший байт цвета correct\n");
    // Устанавливаем команду для записи в память
    ST7789_send_cmd(ST7789_RAMWR);
    printf("sleep_ms(5000) correct\n");
    sleep_ms(5000);
    printf("ST7789_send_cmd(ST7789_RAMWR) correct\n");
    // Заполняем экран цветом
    uint16_t num_pixels = 240 * 240;  // Размер экрана, например 240x240
    uint8_t pixel_data[2] = {color_hi, color_lo}; // данные пикселя в формате RGB565
    for (int i = 0; i < num_pixels; i++) {
        ST7789_send_data(pixel_data, 2); // Отправляем пиксель
        printf("%d", i);
    }
}