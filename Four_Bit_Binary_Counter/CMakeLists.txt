# Lists all local c files needed for the program #
add_executable(Four_Bit_Binary_Counter
        Counter.c
        )

# Pulls in common dependencies #
target_link_libraries(Four_Bit_Binary_Counter pico_stdlib)

# Creates the map/bin/hex file etc #
pico_add_extra_outputs(Four_Bit_Binary_Counter)