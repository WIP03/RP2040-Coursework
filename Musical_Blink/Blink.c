# include "pico/stdlib.h"

// Sets up needed information for boths pins and frequency.
const uint BUZZER = 18;
uint ledPins[] = {2,3,4,5,6,7,8,9,10,11,12,13};
float freqs[] = {261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88};

/**
 * @brief Functions which generates a tone given its frequency, displaying which tone it is by its LED.
 * @param freq 
 * @param length 
 * @param ledPin 
 */
void tone (float freq, float length, uint ledPin) {
    int cycles = 0; // Number of times the buzzer is turned on during a particular tone.
    gpio_put(ledPin, 1); // Turns on LED before sound is played.

    // Switches on the GPIO for the buzzer for a particular tile in given intervals giving it a unique sound.
    while (cycles * (1/freq) < length / 1000)
    {
        gpio_put(BUZZER, 1);
        sleep_us((int) 1000000/(2*freq));
        gpio_put(BUZZER, 0);
        sleep_us((int) 1000000/(2*freq));
        cycles = cycles + 1;
    }
    gpio_put(ledPin, 0); // Turns off LED after sound is played.
}

/**
 * @brief Main function of program, handles the program loop and sets up its functionality.
 * @return int 
 */
int main() {
    // Sets up the GPIO for the maker boards BUZZER.
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
    
    // Initialises all the LED pins which show the current sound being played.
    for (uint i = 0; i < 12; i++){
        gpio_init(ledPins[i]);
        gpio_set_dir(ledPins[i], GPIO_OUT);
    }

    // Plays the tones in a loop, playing each sound for 600 milliseconds.
    while (true) {
        for (uint j = 0; j < 12; j++){
            tone(freqs[j], 600, ledPins[j]);   
        } 
    }
}