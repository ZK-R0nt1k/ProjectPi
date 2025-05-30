#include <stdint.h>
#include <climits>
#include <vector>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <malloc.h>
#include <map>
#include "lwipopts.h"
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "hardware/pll.h"
#include "pico/malloc.h"
/*//Bluetooth
#include "pico/cyw43_arch.h"
#include "btstack_config.h"
#include "btstack.h"
#include "btstack_run_loop_embedded.c"
#include "hci_dump_embedded_stdout.c"
#include "hci_transport_h4.c"*/


//#include "btstack_run_loop.h"
//#include "ble/hids_device.c"
//#include "gap.h"
//#include "ble/gatt-service/device_information_service_server.h"
//#include "ble/gatt-service/hids_device.h"
//#include "Bluetoothh.h"

#include "hardware/i2c.h"
#include "hardware/spi.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"

//
#include "ST7789_driver_commands.h"
#include "ST7789_driver.h"

#include "keyboard.h"
#include "include_vector.h"

#include "timer.h"
#include "ping_pong.h"


