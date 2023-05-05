#include "pico/stdlib.h"
#include <stdio.h>
#include "pico/time.h"
#include "hardware/irq.h"
#include "hardware/pwm.h"
#include "PicoType.h"

// Creates the needed variables for the program
uint led;
uint brightness = 0;
bool increasing = true;

// Updates the brightness value for the boards LED.
void updateBrightness(void) {
    pwm_clear_irq(pwm_gpio_to_slice_num(led)); // Clears the LED's PWM.
    
    // Changes the brightness value.
    if (increasing) {
        if (brightness >= 255) {increasing = false;}
        else{brightness += 1;}
    }

    else {
        if (brightness <= 0) {increasing = true;}
        else{brightness -= 1;}
    }

    pwm_set_gpio_level(led, brightness); // Updates the PWM of the brightness.
}


int main() {

    // Sets led ID based on if the board has a Wifi chip or not.
    if (IsPicoW() == 1 ) { led = 0; }  // Pico W and Pico W H
    else                 { led = 25; } // Pico and Pico H

    // Initialises the IO.
    gpio_set_function(led, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(led);

    pwm_clear_irq(slice_num);
    pwm_set_irq_enabled(slice_num, true);
    irq_set_exclusive_handler(PWM_IRQ_WRAP, updateBrightness);
    irq_set_enabled(PWM_IRQ_WRAP, true);


    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.f);
    pwm_init(slice_num, &config, true);

    while (1) { tight_loop_contents(); }
}