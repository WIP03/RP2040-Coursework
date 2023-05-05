# Lists all local c files needed for the program #
add_executable(Pico_Fat_Writer
        PicoFatWriter.c
        hw_config.c
        )

pico_enable_stdio_uart(Pico_Fat_Writer 1)
pico_enable_stdio_usb(Pico_Fat_Writer 0)

# Adds the subdirectory for this particular library #
add_subdirectory(no-OS-FatFS-SD-SPI-RPi-Pico/FatFs_SPI build)

# Pulls in common dependencies #
target_link_libraries(Pico_Fat_Writer pico_stdlib FatFs_SPI hardware_clocks hardware_adc hardware_spi hardware_dma hardware_pio hardware_clocks)

# Creates the map/bin/hex file etc #
pico_add_extra_outputs(Pico_Fat_Writer)
pico_enable_stdio_uart(Pico_Fat_Writer 1)
pico_enable_stdio_usb(Pico_Fat_Writer 1)