# Lists all local c files needed for the program #
add_executable(Binary_Buzzer
        BinBuzz.c
        )

# Pulls in common dependencies #
target_link_libraries(Binary_Buzzer pico_stdlib)

# Creates the map/bin/hex file etc #
pico_add_extra_outputs(Binary_Buzzer)