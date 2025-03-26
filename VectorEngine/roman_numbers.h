
// Примеры функций для разных римских символов
void roman_numbers_1(int x0, int y0, uint8_t layer) {
    layers[layer].add_shape(new Line(1 + x0, 0 + y0, 1 + x0, 6 + y0)); // I
}

void roman_numbers_4(int x0, int y0, uint8_t layer) {
    layers[layer].add_shape(new Line(1 + x0, y0, 1 + x0, 6 + y0)); // I
    layers[layer].add_shape(new Line(3 + x0, 6 + y0, 5 + x0, y0)); // V часть
    layers[layer].add_shape(new Line(5 + x0, y0, 7 + x0, 6 + y0));
}

void roman_numbers_5(int x0, int y0, uint8_t layer) {
    layers[layer].add_shape(new Line(0 + x0, 6 + y0, 2 + x0, y0)); // V
    layers[layer].add_shape(new Line(2 + x0, y0, 4 + x0, 6 + y0));
}

void roman_numbers_9(int x0, int y0, uint8_t layer) {
    layers[layer].add_shape(new Line(1 + x0, y0, 1 + x0, 6 + y0)); // I
    layers[layer].add_shape(new Line(3 + x0, 6 + y0, 7 + x0, y0)); // X часть
    layers[layer].add_shape(new Line(3 + x0, y0, 7 + x0, 6 + y0));
}

void roman_numbers_10(int x0, int y0, uint8_t layer) {
    layers[layer].add_shape(new Line(1 + x0, 0 + y0, 5 + x0, 6 + y0)); // X
    layers[layer].add_shape(new Line(1 + x0, 6 + y0, 5 + x0, 0 + y0));
}

void roman_numbers_40(int x0, int y0, uint8_t layer) {
    layers[layer].add_shape(new Line(1 + x0, 0 + y0, 5 + x0, 6 + y0)); // X
    layers[layer].add_shape(new Line(1 + x0, 6 + y0, 5 + x0, 0 + y0));   
    layers[layer].add_shape(new Line(6 + x0, 0 + y0, 6 + x0, 6 + y0)); // L
    layers[layer].add_shape(new Line(6 + x0, 0 + y0, 10 + x0, 0 + y0)); 
}

void roman_numbers_50(int x0, int y0, uint8_t layer) {
    layers[layer].add_shape(new Line(1 + x0, 0 + y0, 1 + x0, 6 + y0)); // L
    layers[layer].add_shape(new Line(1 + x0, 0 + y0, 5 + x0, 0 + y0));
}

void draw_roman_number(int number, int x0, int y0, uint8_t layer) {
    while (number >= 50) { // L
        roman_numbers_50(x0, y0, layer);
        x0 += 6; // Смещение после L
        number -= 50;
    }
    while (number >= 40) { // XL
        roman_numbers_40(x0, y0, layer);
        x0 += 10; // Смещение после XL
        number -= 40;
    }
    while (number >= 10) { // X
        roman_numbers_10(x0, y0, layer);
        x0 += 6; // Смещение после X
        number -= 10;
    }
    if (number >= 9) { // IX
        roman_numbers_9(x0, y0, layer);
        x0 += 6; // Смещение после IX
        number -= 9;
    }
    if (number >= 5) { // V
        roman_numbers_5(x0, y0, layer);
        x0 += 6; // Смещение после V
        number -= 5;
    }
    if (number >= 4) { // IV
        roman_numbers_4(x0, y0, layer);
        x0 += 8; // Смещение после IV
        number -= 4;
    }
    while (number >= 1) { // I
        roman_numbers_1(x0, y0, layer);
        x0 += 2; // Смещение после I
        number -= 1;
    }
}
