# Lists all local c files needed for the program #
add_executable(Fading_LED
        LEDFade.c
        PicoType.c
        )

# Pulls in common dependencies #
target_link_libraries(Fading_LED pico_stdlib pico_cyw43_arch_none hardware_adc)

# Creates the map/bin/hex file etc #
pico_add_extra_outputs(Fading_LED)