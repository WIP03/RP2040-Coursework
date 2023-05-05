# include "pico/stdlib.h"

// Sets up needed information for boths pins and frequency.
const uint BUZZER = 18;

/**
 * @brief Plays a musical note via the maker boards BUZZER.
 */
void playTone () {
    // Sets up values needed for generating a tone.
    uint cycles = 0;
    float freq = 261.63;

    // Switches on the GPIO for the buzzer for a particular tile in given intervals giving it a unique sound.
    while (cycles * (1/freq) < 0.6)
    {
        gpio_put(BUZZER, 1);
        sleep_us((int) 1000000/(2*freq));
        gpio_put(BUZZER, 0);
        sleep_us((int) 1000000/(2*freq));
        cycles = cycles + 1;
    }
}

/**
 * @brief Main function of program, handles the program loop and sets up its functionality.
 * @return int 
 */
int main() {
    // Sets up the GPIO for the maker boards BUZZER.
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
    
    // Plays a tone.
    playTone();
}