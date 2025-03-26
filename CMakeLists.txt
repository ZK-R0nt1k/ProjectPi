cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(pico_sdk_import.cmake)

set (PICO_BOARD pico_w)
project(main)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(Drivers)
include_directories(VectorEngine)
include_directories(
    ${PICO_SDK_PATH}/lib/btstack/src
    ${PICO_SDK_PATH}/lib/btstack/src/ble
)

pico_sdk_init()

add_executable(template
    main.cpp 
)

# Add pico_stdlib library, add more if used
target_link_libraries(template
    pico_stdlib
    hardware_i2c
    hardware_spi
    hardware_pwm
    hardware_adc
    pico_cyw43_arch_none
    pico_lwip_iperf
    pico_btstack_ble 
    pico_btstack_cyw43 
    )

# enable usb output, disable uart output
pico_enable_stdio_usb(template 1)
pico_enable_stdio_uart(template 0)

# Need to generate UF2 file for upload to RP2040
pico_add_extra_outputs(template)

