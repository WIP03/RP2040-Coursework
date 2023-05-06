# include "pico/stdlib.h"

// Sets up needed information for both the buttons or buzzers.
const uint buzzerId = 18;
const uint buttonOneId = 20;
const uint buttonTwoId = 21;
const uint buttonThreeId = 22;


// Bellow are some dummy functions you may want to use as a guide, or not, you choose how you complete this problem.

/**
 * @brief Pauses the program between a buzz.
 */
void pauseTone() { }

/**
 * @brief Plays a musical note via the maker boards buzzer.
 */
void playTone() { }

/**
 * @brief Plays the currently recorded binary sequence.
 */
void playSequence() { }

/**
 * @brief Event which occurs when a button is pressed.
 * @param buttonId The button which was just pressed.
 */
void buttonPress (uint buttonId) { }

/**
 * @brief Main function of program, handles the program loop and sets up its functionality.
 * @return int 
 */
int main() {
    // Initialises the GPIO of the buttons and buzzers.
    gpio_init(buzzerId);
    gpio_init(buttonOneId);
    gpio_init(buttonTwoId);
    gpio_init(buttonThreeId);
    gpio_set_dir(buzzerId, GPIO_OUT);
    gpio_set_dir(buttonOneId, GPIO_IN);
    gpio_set_dir(buttonTwoId, GPIO_IN);
    gpio_set_dir(buttonThreeId, GPIO_IN);

    // Add main loop here, how should it work, how do you want store and update the sequence?
}