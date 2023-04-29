# include "pico/stdlib.h"

void tone(float freq, float length); // freq in Hz, length in ms

int main() {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
# else
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    const uint LED_PIN_TWO = 2;
    gpio_init(LED_PIN_TWO);
    gpio_set_dir(LED_PIN_TWO, GPIO_OUT);
    const uint LED_PIN_THREE = 3;
    gpio_init(LED_PIN_THREE);
    gpio_set_dir(LED_PIN_THREE, GPIO_OUT);
    const uint LED_PIN_FOUR = 4;
    gpio_init(LED_PIN_FOUR);
    gpio_set_dir(LED_PIN_FOUR, GPIO_OUT);
    const uint LED_PIN_FIVE = 5;
    gpio_init(LED_PIN_FIVE);
    gpio_set_dir(LED_PIN_FIVE, GPIO_OUT);
    const uint LED_PIN_SIX = 6;
    gpio_init(LED_PIN_SIX);
    gpio_set_dir(LED_PIN_SIX, GPIO_OUT);
    const uint LED_PIN_SEVEN = 7;
    gpio_init(LED_PIN_SEVEN);
    gpio_set_dir(LED_PIN_SEVEN, GPIO_OUT);
    const uint LED_PIN_EIGHT = 8;
    gpio_init(LED_PIN_EIGHT);
    gpio_set_dir(LED_PIN_EIGHT, GPIO_OUT);
    const uint LED_PIN_NINE = 9;
    gpio_init(LED_PIN_NINE);
    gpio_set_dir(LED_PIN_NINE, GPIO_OUT);
    // There is a missing pin, fill in the blank so that all the MakerBoard's LEDs will light up


    const uint LED_PIN_ELEVEN = 11;
    gpio_init(LED_PIN_ELEVEN);
    gpio_set_dir(LED_PIN_ELEVEN, GPIO_OUT);
    const uint LED_PIN_TWELVE = 12;
    gpio_init(LED_PIN_TWELVE);
    gpio_set_dir(LED_PIN_TWELVE, GPIO_OUT);
    const uint LED_PIN_THIRTEEN = 13;
    gpio_init(LED_PIN_THIRTEEN);
    gpio_set_dir(LED_PIN_THIRTEEN, GPIO_OUT);
    const uint BUZZER; // Have a look at the Maker board to find out which pin the buzzer uses. Put that pin's number here.
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);

    while (true) {
        gpio_put(LED_PIN_TWO, 1);
        tone(261.63, 600);
        gpio_put(LED_PIN_TWO, 0);
        gpio_put(LED_PIN_THREE, 1);
        tone(277.18, 600);
        gpio_put(LED_PIN_THREE, 0);
        gpio_put(LED_PIN_FOUR, 1);
        tone(293.66, 600);
        gpio_put(LED_PIN_FOUR, 0);
        gpio_put(LED_PIN_FIVE, 1);
        tone(311.13, 600);
        gpio_put(LED_PIN_FIVE, 0);
        gpio_put(LED_PIN_SIX, 1);
        tone(329.63, 600);
        gpio_put(LED_PIN_SIX, 0);
        gpio_put(LED_PIN_SEVEN, 1);
        tone(349.23, 600);
        gpio_put(LED_PIN_SEVEN, 0);
        gpio_put(LED_PIN_EIGHT, 1);
        tone(369.99, 600);
        gpio_put(LED_PIN_EIGHT, 0);
        gpio_put(LED_PIN_NINE, 1);
        tone(392.00, 600);
        gpio_put(LED_PIN_NINE, 0);
        gpio_put(LED_PIN_TEN, 1);
        tone(415.30, 600);
        gpio_put(LED_PIN_TEN, 0);
        gpio_put(LED_PIN_ELEVEN, 1);
        tone(440.00, 600);
        gpio_put(LED_PIN_ELEVEN, 0);
        gpio_put(LED_PIN_TWELVE, 1);
        tone(466.16, 600);     
        gpio_put(LED_PIN_TWELVE, 0);
        gpio_put(LED_PIN_THIRTEEN, 1);
        tone(493.88, 600);
        gpio_put(LED_PIN_THIRTEEN, 0);        
    }
#endif
}
void tone (float freq, float length) {
    int cycles = 0;
    while (cycles * (1/freq) < length / 1000)
    {
        gpio_put(18, 1);
        sleep_us((int) 1000000/(2*freq));
        gpio_put(18, 0);
        // Which line is missing here? Hint: think of the shape of the wave that we are creating.
        cycles = cycles + 1;
    }
    
}