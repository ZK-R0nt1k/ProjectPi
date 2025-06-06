#include "include.h"
//Выводы клавиатуры
#define SHIFT_REG_B 6
#define SHIFT_REG_CLK 7
#define BUTTON_COLLUM_A 8
#define BUTTON_COLLUM_B 9
#define BUTTON_COLLUM_C 10

#define TPS 60

//I2C интерфейс
#define I2C_SPEED 1600
#define BLUE_LED_PIN 11


#define STACK_SIZE 4096  


uint16_t tick_time;
uint64_t up_time;
uint64_t up_time_1;


static void packet_handler (uint8_t packet_type, uint16_t channel, const uint8_t *packet, uint16_t size);

void free_memory(){
    struct mallinfo info = mallinfo();
    
    printf("🔹 Свободная RAM (Heap): %d байт\n", info.fordblks);
    printf("🔹 Используемая Heap: %d байт\n", info.uordblks);
    printf("🔹 Всего выделено Heap: %d байт\n", info.arena);
}

void Update(){

}

float load;
void FixedUpdate(){
        get_keyboard_stautus(); 
        game();
        if (time_us_64() - up_time_1 >= 1000000){
            printf("🔹 up_time: %d s\n", (up_time_1 / 1000000));
            printf("Clock speed: %d Hz\n", clock_get_hz(clk_sys));
            printf("🔹 CPU load: %.2f%%\n", load);
            free_memory();
            for (const auto& [id, layer] : layers){
                printf("Layers id: %d\n", id);
                for (const auto& [shape_id, shape_prefab] : layer.shapes_prefabs){
                    printf("Shape id: %d Name: %s\n", shape_id, shape_prefab->get_name());
                }
                for (const auto& [shape_id, shape] : layer.shapes){
                    printf("Shape id: %d Name: %s\n", shape_id, shape->get_name());
                }
            }
        }
        up_time_1 = time_us_64();
}

//static void hci_packet_handler(uint8_t packet_type, uint16_t channel, uint8_t *packet, uint16_t size);
//static void sm_packet_handler(uint8_t packet_type, uint16_t channel, uint8_t *packet, uint16_t size);

int main(){
    up_time = time_us_64();
    up_time_1 = time_us_64();
    tick_time = 1000000 / TPS;
    stdio_init_all();
    SSD1306_init_i2c(I2C_SPEED);
    SSD1306_init();
    init_keyboar_shift_register(SHIFT_REG_B, SHIFT_REG_CLK);
    init_button_collums(BUTTON_COLLUM_A, BUTTON_COLLUM_B, BUTTON_COLLUM_C);
    matrix_init();
    init_layers(5);
    //ST7789_init_SPI();
    //ST7789_init();
    //ST7789_fill_screen(0xfaaa);
    start_screen();
    init_ping_pong();
    sleep_ms(1000);
/*
    cyw43_arch_init();
    btstack_memory_init();

    // select embedded run loop
    btstack_run_loop_init(btstack_run_loop_embedded_get_instance());
  
    // enable logging
    hci_dump_init(hci_dump_embedded_stdout_get_instance());
  
  
    // init HCI
    const btstack_uart_block_t * uart_driver = btstack_uart_block_embedded_instance();
    const hci_transport_t * transport = hci_transport_h4_instance(uart_driver);
    hci_init(transport, NULL);
  
    // setup example    
    printf("Bluetooth init 0\n");
    btstack_main(0, NULL);
    printf("Bluetooth init\n");
  
    // go
    btstack_run_loop_execute(); 
   
    //l2cap_init();
    //sm_init();

    // setup ATT server
    //att_server_init(profile_data, NULL, NULL);
  
    // setup GATT Client
    //gatt_client_init();
  
    // register handler
    //hci_event_callback_registration.callback = &hci_packet_handler;
    //hci_add_event_handler(&hci_event_callback_registration);
    //hci_power_control(HCI_POWER_ON);
   // sm_event_callback_registration.callback = &sm_packet_handler;
   // sm_add_event_handler(&sm_event_callback_registration);
    //BluetoothInit();*/

    while (true) {
        Update();
        if (time_us_64() - up_time >= tick_time) {
            uint64_t start_time = time_us_64(); 
            FixedUpdate();
            uint64_t end_time = time_us_64(); 
            uint64_t execution_time = end_time - start_time;
            load = ((float)execution_time / tick_time) * 100.0f;
            up_time = time_us_64();
        }
    }
    return 0;
}
