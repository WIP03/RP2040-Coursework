# include "pico/stdlib.h"

// Sets up needed information for both the buttons or buzzers.
const uint buzzerId = 18;
const uint buttonOneId = 20;
const uint buttonTwoId = 21;
const uint buttonThreeId = 22;

// Defines the values used for the binary sequence.
char binarySequence[8] = "00000000";
uint binaryPosition = 0;
bool binaryPlay = false;

/**
 * @brief Plays a musical note via the maker boards buzzer.
 */
void playTone() {
    // Sets up values needed for generating a tone.
    uint cycles = 0;
    float freq = 261.63;

    // Switches on the GPIO for the buzzer for a particular tile in given intervals giving it a unique sound.
    while (cycles * (1/freq) < 0.6)
    {
        gpio_put(buzzerId, 1);
        sleep_us((int) 1000000/(2*freq));
        gpio_put(buzzerId, 0);
        sleep_us((int) 1000000/(2*freq));
        cycles = cycles + 1;
    }
}

/**
 * @brief Pauses the program between a buzz.
 */
void pauseTone() { sleep_ms(600); }

/**
 * @brief Plays the currently recorded sequence.
 */
void playSequence() {
    for (uint pos = 0; pos < binaryPosition; pos++) {
        if (binarySequence[pos] == '0') {pauseTone();}
        else {playTone();}
    }
    binaryPosition = 0;
    binaryPlay = false;
}

/**
 * @brief Event which occurs when a button is pressed, updates the sequence or plays the sequence.
 * @param buttonId The button which was just pressed.
 */
void buttonPress (uint buttonId) {
    if ((binaryPosition == 8) || (buttonId == buttonThreeId)) {binaryPlay = true; return;} // Plays sequence ones maxed or button is pressed, returns to stop holddown check.
    else if (buttonId == buttonOneId) {binarySequence[binaryPosition] = '0'; binaryPosition++;} // Adds a pause to the sequence.
    else if (buttonId == buttonTwoId) {binarySequence[binaryPosition] = '1'; binaryPosition++;} // Adds a buzz to the sequence.
    while (gpio_get(buttonId) == 0) {} // Used to prevent holding down for counter of multiple values.
}

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

    // Checks for button presses and play's the sequence once its full or the button is pressed.
    while(1) {
        if (binaryPlay) {playSequence();}
        else if (gpio_get(buttonOneId) == 0) {buttonPress(buttonOneId);}
        else if (gpio_get(buttonTwoId) == 0) {buttonPress(buttonTwoId);}
        else if (gpio_get(buttonThreeId) == 0) {buttonPress(buttonThreeId);}
    }
}