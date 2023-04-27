#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "PicoType.h"

int main() {

  //Stores ID's for needed GPIO.
  const uint buttonOne = 20;
  const uint buttonTwo = 21;
  uint ledOne;

  if (isPicoW()){ ledOne = 0;  } // Pico W GPIO is 0 for led.
  else          { ledOne = 25; } // Pico GPIO is 25 for led.

  //Initialises said GPIO.
  gpio_init(buttonOne);
  gpio_init(buttonTwo);
  gpio_init(ledOne);

  //Sets the direction of the different GPIO for use.
  gpio_set_dir(buttonOne, GPIO_IN);
  gpio_set_dir(buttonTwo, GPIO_IN);
  gpio_set_dir(ledOne, GPIO_OUT);

  //Turns on led when button one is pressed, else its off. Stops looping when button two is pressed.
  //According to the pinout diagram buttons are "ACTIVE LOW" so we turn of led when button is 1.
  while (gpio_get(buttonTwo)) {
    if (gpio_get(buttonOne)){ gpio_put(ledOne,0); }
    else { gpio_put(ledOne,1); }
  }
}