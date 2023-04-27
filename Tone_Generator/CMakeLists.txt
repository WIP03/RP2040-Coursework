# Lists all local c and h files needed for the program #
add_executable(Tone_Generator
        Tones.c
        )

# Pulls in common dependencies #
target_link_libraries(Tone_Generator pico_stdlib hardware_pwm hardware_clocks)

# Creates the map/bin/hex file etc #
pico_add_extra_outputs(Tone_Generator)