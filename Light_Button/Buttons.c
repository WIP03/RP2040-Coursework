#include "pico/stdlib.h"

int main() {

  //Stores ID's for needed GPIO.
  const int buttonOne = 20;
  const int ledOne = 0; //Its 0 for Pico W and 25 for Pico (maybe find way to get difference)

  //Initialises said GPIO.
  gpio_init(buttonOne);
  gpio_init(ledOne);

  //Sets the direction of the different GPIO for use.
  gpio_set_dir(buttonOne, GPIO_IN);
  gpio_set_dir(ledOne, GPIO_OUT);

  //Write your own code to turn a LED on when button is pressed
}