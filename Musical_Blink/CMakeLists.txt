# Lists all local c files needed for the program #
add_executable(Musical_Blink
        Blink.c
        )

# Pulls in common dependencies #
target_link_libraries(Musical_Blink pico_stdlib)

# Creates the map/bin/hex file etc #
pico_add_extra_outputs(Musical_Blink)