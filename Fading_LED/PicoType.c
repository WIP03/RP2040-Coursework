/*
Library created by William Percy (wip1g21)
Code and concepts adapted from this rp forum post: https://forums.raspberrypi.com/viewtopic.php?t=336775
*/

#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "PicoType.h"

/**
 * @brief Internal cache value for storing if the pico the code is running on is a Pico W or not.
 */
int32_t isPicoW_Cached = -1;

/**
 * @brief Uses the VSYS_ADC to check if the given Pico board is a Pico W.
 * @return int32_t 
 */
int32_t IsPicoW(void) {

    // Checks if the check hasn't already been done,
    // if so its calculated, if not the cached value is just returned.
    if (isPicoW_Cached < 0) {

        // Defines the needed values for the check, so no hardcoding.
        // This includes both ADC and control Id's for the VSYS and the checked voltage value.
        #define VSYS_ADC_GPIO  29   // Internal GPIO pin which is used for reading the VSYS_ADC
        #define VSYS_ADC_CHAN   3   // The channel number which we use to get info from the VSYS_ADC
        #define HALF_VOLT     204   // Check for voltage reading, 0.5V divide by 3, as 12-bit with 3V3 Vref
        #define VSYS_CTL_GPIO  25   // Internal GPIO pin which enables VSYS_ADC on Pico-W
        
        // Initialises the ADC and selects the channel which is connected to the FET.
        // It also initialises its GPIO pin which is internal to the RP2040.
        adc_init();                         // Init
        adc_gpio_init(VSYS_ADC_GPIO);       // GPIO
        adc_select_input(VSYS_ADC_CHAN);    // Channel

        // It initialises the GPIO channel which controls the FET.
        // This makes sure that the ADC channel is low if the board is a Pico W.
        // (If the board is a normal Pico this will disable the boards LED if running)
        gpio_init(VSYS_CTL_GPIO);              // GPIO
        gpio_set_dir(VSYS_CTL_GPIO, GPIO_IN);  // Input

        // Checks if the ADC voltage is bellow 0.5v, if so its a Pico-W else just a Pico.
        // This is because when the VSYS_ADC is read on a Pico it will always be > 0.5V
        // On a Pico-W it will be < 0.5V when GPIO25 is low
        if (adc_read() < HALF_VOLT) { isPicoW_Cached = 1; } // Pico-W
        else                        { isPicoW_Cached = 0; } // Pico
    }
    return isPicoW_Cached;
}