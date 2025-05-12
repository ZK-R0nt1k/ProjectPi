void ST7789_reset(){gpio_put(RST_PIN, false);sleep_ms(100);gpio_put(RST_PIN, true);sleep_ms(100);}

//#if defined(spi_default) && defined(PICO_DEFAULT_SPI_CSN_PIN)
void ST7789_init_SPI(){
        spi_init(SPI_PORT, 10000000);  
        
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
    sleep_ms(150);

    ST7789_send_cmd(ST7789_SLPOUT);   // Выход из режима сна
    sleep_ms(500);

    ST7789_send_cmd(ST7789_COLMOD);   // Формат пикселя
    uint8_t colmod_data[] = {0x55};   // 16 бит (RGB565)
    ST7789_send_data(colmod_data, 1);
    sleep_ms(10);

    ST7789_send_cmd(ST7789_MADCTL);   // Ориентация изображения
    uint8_t madctl_data[] = {0x00};   // Стандартная ориентация
    ST7789_send_data(madctl_data, 1);
    sleep_ms(10);

    ST7789_send_cmd(ST7789_CASET);    // Установка области по X (0-239)
    uint8_t caseset_data[] = {0x00, 0x00, 0x00, 0xEF};
    ST7789_send_data(caseset_data, 4);

    ST7789_send_cmd(ST7789_RASET);    // Установка области по Y (0-239)
    uint8_t raseset_data[] = {0x00, 0x00, 0x00, 0xEF};
    ST7789_send_data(raseset_data, 4);

    ST7789_send_cmd(ST7789_INVON);    // Включение инверсии цвета
    sleep_ms(10);

    ST7789_send_cmd(ST7789_DISPON);   // Включение дисплея
    sleep_ms(100);
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