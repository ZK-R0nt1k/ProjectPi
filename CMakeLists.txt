cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BTSTACK_ROOT ${PICO_SDK_PATH}/lib/btstack)
set(BTSTACK_EXAMPLE_PATH ${BTSTACK_ROOT}/example)
set(BTSTACK_3RD_PARTY_PATH ${BTSTACK_ROOT}/3rd-party)

include(pico_sdk_import.cmake)

set (PICO_BOARD pico_w)
project(main)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(Drivers)
include_directories(VectorEngine)
include_directories(Bluetooth)
include_directories(VexDraw)
include_directories(
    ${PICO_SDK_PATH}/lib/btstack
    ${PICO_SDK_PATH}/lib/lwip/src/include
    ${PICO_SDK_PATH}/lib/lwip/contrib/ports/win32/include
    #${PICO_SDK_PATH}/lib/btstack/platform/embedded
   
)

pico_sdk_init()


set(BTSTACK_ROOT "C:/Program Files/Raspberry Pi/Pico SDK v1.5.1/pico-sdk/lib/btstack")


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
pico_btstack_classic
    )

# enable usb output, disable uart output
pico_enable_stdio_usb(template 1)
pico_enable_stdio_uart(template 1)

# Need to generate UF2 file for upload to RP2040
pico_add_extra_outputs(template)

