
bool menu_figure_flag;
void menu_figure_show(){
    menu_figure_flag = true;
    layers[4].add_shape(new Rectangle(1,1,128,32));
    layers[4].add_shape(new Rectangle(3,17,17,31));
}

void menu_figure_hide(){
    menu_figure_flag = false;
    clear_layer_and_redraw(4);
}

/*uint8_t check_cursor_figur(){
/*    switch(cursor_position_x){
        case 
    }
}*/