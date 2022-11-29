cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)
project(pico-INMP441)
set(target_name pico-INMP441)

pico_sdk_init()

add_subdirectory(pico-I2S)

add_executable(${target_name})

target_sources(${target_name} PRIVATE
    main.c
)

target_link_libraries(${target_name} PRIVATE
    pico_stdlib
    hardware_pio
    hardware_irq
    pico_multicore
    i2s
)

# enable usb output, disable uart output
pico_enable_stdio_usb(${target_name} 1)
pico_enable_stdio_uart(${target_name} 0)

pico_add_extra_outputs(${target_name})
