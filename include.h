#include <stdint.h>
#include <climits>
#include <vector>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <malloc.h>
#include <map>
#include "lwipopts.h"
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "hardware/pll.h"
//Bluetooth
#include "pico/cyw43_arch.h"
#include "btstack_event.h"
#include "btstack.h"
#include "hal_led.h"
#include "hal_tick.h"
#include "hal_cpu.h"
#include "btstack_config.h"
#include "lwiperf.h"
//#include "sm_pairing_central.h"
//#include "Bluetoothh.h"

#include "hardware/i2c.h"
#include "hardware/spi.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "pico/malloc.h"
//
#include "ST7789_driver_commands.h"
#include "ST7789_driver.h"

#include "keyboard.h"
#include "vector_engine.h"
#include "SSD1306_driver.h"
#include "shapes.h"
#include "layers.h"
#include "icons.h"
#include "main_menu.h"
#include "start_screen.h"
#include "drawer_UI.h"
#include "drawer.h"
#include "roman_numbers.h"

#include "timer.h"
#include "ping_pong.h"


