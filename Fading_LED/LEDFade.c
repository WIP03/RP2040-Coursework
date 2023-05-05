#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "hardware/adc.h"
#include "PicoType.h"

int main() {
    // Initialises the IO.
    stdio_init_all();

    // Stores ID's for needed GPIO.
    const uint buttonOne = 20;
    const uint buttonTwo = 21;
    uint ledOne;

    // Initialises said GPIO then sets there direction.
    gpio_init(buttonOne);
    gpio_init(buttonTwo);
    gpio_set_dir(buttonOne, GPIO_IN);
    gpio_set_dir(buttonTwo, GPIO_IN);

    // Code for when the program is ran on a Pico with Wifi (Pico W and Pico WH). 
    if (IsPicoW() == 1 ) { 
        ledOne = 0; // Pico W GPIO is 0 for the led on the Wifi chip.
    }

    // Code for when the program is ran on a Pico without Wifi (Pico and Pico H).
    else { 
        ledOne = 25; // Pico GPIO is 25 for led.
    }
}