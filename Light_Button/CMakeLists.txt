# Lists all local c files needed for the program #
add_executable(Light_Button
        Buttons.c
        )

# Pulls in common dependencies #
target_link_libraries(Light_Button pico_stdlib)

# Creates the map/bin/hex file etc #
pico_add_extra_outputs(Light_Button)