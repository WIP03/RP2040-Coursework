# Lists all local c files needed for the program #
add_executable(Light_Button
        Buttons.c
        PicoType.c
        )

# Pulls in common dependencies #
target_link_libraries(Light_Button pico_stdlib hardware_adc)

# Creates the map/bin/hex file etc #
pico_add_extra_outputs(Light_Button)