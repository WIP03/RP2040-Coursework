#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "Tones.h"

// Sets up local information about freqs.
const uint freqsListSize = (sizeof(freqs)/sizeof(freqs[0])); // Element count in freqs array.
uint frequencyId;   // Store index of the current frequency stored in the freqs array.
uint pwmFreqSlice;  // Stores the slice number of the buzzer.

// Stores ID's for needed GPIO.
const uint buttonOnePin = 20;    // Lowers tone
const uint buttonTwoPin = 21;    // Resets tone
const uint buttonThreePin = 22;  // Raises tone

/**
 * @brief Updates the buzzer to to create a sound equivalent of the given frequency.
 * @param frequency 
 */
void updateBuzzer(float frequency) {

    // Converts the frequency into the correct divider and wrap to generate the desired PWM signal.
    float clockDivider = 1.0f;
    uint32_t sys_clk_freq = clock_get_hz(clk_sys);
    uint32_t counterWrap = sys_clk_freq / (clockDivider * frequency);
    while (counterWrap > 65535) {
        clockDivider *= 2.0f;
        counterWrap = sys_clk_freq / (clockDivider * frequency);
    }

    // Generates the PWM signal by setting the correct divider, wrapper and channel level.
    pwm_set_clkdiv(pwmFreqSlice, clockDivider);
    pwm_set_wrap(pwmFreqSlice, counterWrap);
    pwm_set_chan_level(pwmFreqSlice, PWM_CHAN_A, (counterWrap / 2));
}

/**
 * @brief Updates the frequency of the buzzer based on the button pressed.
 * @param buttonId 
 * @param event_mask 
 */
void updateFrequency(uint buttonId, uint32_t event_mask) {

    // A switch which is used to assign the new frequency used by the button pressed.
    switch (buttonId){
        case buttonOnePin: // Reduces the frequency of the buzzer when button one is pressed.
            if (frequencyId > 0) { frequencyId--; }
            break;
        case buttonTwoPin: // Resets the frequency of the buzzer when button two is pressed.
            frequencyId = (freqsListSize / 2);
            break;
        case buttonThreePin: // Ups the frequency of the buzzer when button three is pressed.
            if (frequencyId < (freqsListSize-1)) { frequencyId++; }
            break;
    }

    // Updates the buzzer to use the new frequency.
    updateBuzzer(freqs[frequencyId]);
}

/**
 * @brief Main function of program, handles the program loop and sets up its functionality.
 * @return int 
 */
int main() {

    // Sets up the PWM functionality of the buzzer.
    gpio_set_function(buzzerPin, GPIO_FUNC_PWM);
    pwmFreqSlice = pwm_gpio_to_slice_num(buzzerPin);
    pwm_set_enabled(pwmFreqSlice, true);

    // Sets up the buzzer with its default frequency.
    frequencyId = (freqsListSize / 2);
    updateBuzzer(freqs[frequencyId]);

    // Creates events for when a button is initially pressed which updates buzzer frequency. 
    gpio_set_irq_enabled_with_callback(buttonOnePin, GPIO_IRQ_EDGE_FALL, true, &updateFrequency);   // Lowers the frequency if button one is pressed.
    gpio_set_irq_enabled_with_callback(buttonTwoPin, GPIO_IRQ_EDGE_FALL, true, &updateFrequency);   // Resets the frequency if button two is pressed.
    gpio_set_irq_enabled_with_callback(buttonThreePin, GPIO_IRQ_EDGE_FALL, true, &updateFrequency); // Ups the frequency if button three is pressed.

    // Loop which checks for the events, if any occur then there corresponding function is called.
    while (true) { tight_loop_contents(); }
}

