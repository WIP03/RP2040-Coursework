#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "Tones.h"

int main() {

    //Stores ID's for needed GPIO.
    const uint buttonOnePin = 20;    //lowers tone
    const uint buttonTwoPin = 21;    //resets tone
    const uint buttonThreePin = 22;  //raises tone

    //Initialises said GPIO.
    gpio_init(buttonOnePin);
    gpio_init(buttonTwoPin);
    gpio_init(buttonThreePin);
    gpio_init(buzzerPin);

    //Sets the direction of the different GPIO for use.
    gpio_set_dir(buttonOnePin, GPIO_IN);
    gpio_set_dir(buttonTwoPin, GPIO_IN);
    gpio_set_dir(buttonThreePin, GPIO_IN);
    gpio_set_dir(buzzerPin, GPIO_OUT);
}
