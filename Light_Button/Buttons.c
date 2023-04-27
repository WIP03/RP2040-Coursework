#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "hardware/adc.h"
#include "PicoType.h"

int main() {
    // Stores ID's for needed GPIO.
    const uint buttonOne = 20;
    const uint buttonTwo = 21;
    uint ledOne;

    // Initialises said GPIO.
    gpio_init(buttonOne);
    gpio_init(buttonTwo);

    // Sets the direction of the different GPIO for use.
    gpio_set_dir(buttonOne, GPIO_IN);
    gpio_set_dir(buttonTwo, GPIO_IN);

    // Code for when the program is ran on a Pico with Wifi (Pico W and Pico WH). 
    if (IsPicoW() == 1 ) { 
        ledOne = 0; // Pico W GPIO is 0 for the led on the Wifi chip.
        
        // Initialises the IO, then trys to initialise the Wifi chip as its required for using the LED on the Pico W.
        stdio_init_all();
        if (cyw43_arch_init()) { return -1; }

        // Turns on led when button one is pressed, else its off. Stops looping when button two is pressed.
        // According to the pinout diagram buttons are "ACTIVE LOW" so we turn of led when button is 1.
        while (gpio_get(buttonTwo)) {
            if (gpio_get(buttonOne)){ cyw43_arch_gpio_put(ledOne, 0); }
            else { cyw43_arch_gpio_put(ledOne, 1); }
        }
    }

    // Code for when the program is ran on a Pico without Wifi (Pico and Pico H).
    else { 
        ledOne = 25; // Pico GPIO is 25 for led.

        // Initialises and set the direction the GPIO for the Pico's led.
        gpio_init(ledOne);
        gpio_set_dir(ledOne, GPIO_OUT);

        // Turns on led when button one is pressed, else its off. Stops looping when button two is pressed.
        // According to the pinout diagram buttons are "ACTIVE LOW" so we turn of led when button is 1.
        while (gpio_get(buttonTwo)) {
          if (gpio_get(buttonOne)){ gpio_put(ledOne,0); }
          else { gpio_put(ledOne,1); }
        }
    }
}