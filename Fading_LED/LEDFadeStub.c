#include "pico/stdlib.h"
#include <stdio.h>
#include "pico/time.h"
#include "hardware/irq.h"
#include "hardware/pwm.h"
#include "PicoType.h"

// Creates the needed variables for the program
uint led; // The ID is different between boards, use the PICO board pinout to find the GPIO ID you need.
uint brightness = 0;
bool increasing = true;

// Bellow are some dummy functions you may want to use as a guide, or not, you choose how you complete this problem.

/**
 * @brief Updates the brightness value for the boards LED. 
 */
void updateBrightness(void) { }

/**
 * @brief Main function of the program. You may want to add any initialisation or update calls here.
 * @return int 
 */
int main() { }