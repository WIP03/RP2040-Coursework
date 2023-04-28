#include "pico/stdlib.h"


const uint buttonOnePin = 20;
const uint buttonTwoPin = 21;
const uint buttonThreePin = 22;

const uint bitLedOne= 9;
const uint bitLedTwo = 8;
const uint bitLedThree = 7;
const uint bitLedFour = 6;

const uint bitLedFive= 5;
const uint bitLedSix = 4;
const uint bitLedSeven = 3;
const uint bitLedEight = 2;


uint counter = 0;


void updateDisplay(void){
    //
    if((counter % 2) > 0) {gpio_put(bitLedOne,1);} else {gpio_put(bitLedOne,0);}          //
    if((counter % 4) > 1) {gpio_put(bitLedTwo,1);} else {gpio_put(bitLedTwo,0);}          //
    if((counter % 8) > 3) {gpio_put(bitLedThree,1);} else {gpio_put(bitLedThree,0);}      //
    if((counter % 16) > 7) {gpio_put(bitLedFour,1);} else {gpio_put(bitLedFour,0);}       //
    if((counter % 32) > 15) {gpio_put(bitLedFive,1);} else {gpio_put(bitLedFive,0);}      //
    if((counter % 64) > 31) {gpio_put(bitLedSix,1);} else {gpio_put(bitLedSix,0);}        //
    if((counter % 128) > 63) {gpio_put(bitLedSeven,1);} else {gpio_put(bitLedSeven,0);}   //
    if((counter % 256) > 127) {gpio_put(bitLedEight,1);} else {gpio_put(bitLedEight,0);}  //
}

void updateCounter(uint buttonId, uint32_t event_mask){
    switch (buttonId){
        case buttonOnePin: if (counter > 0) { counter--; } break;       //
        case buttonTwoPin: (counter = 0); break;                        //
        case buttonThreePin: if (counter < 255) { counter++; } break;   //
    }
    updateDisplay();
}


int main() {

    // It initialises the GPIO used for the LED's on the maker board.
    gpio_init(bitLedOne);
    gpio_init(bitLedTwo);
    gpio_init(bitLedThree);
    gpio_init(bitLedFour);
    gpio_init(bitLedFive);
    gpio_init(bitLedSix);
    gpio_init(bitLedSeven);
    gpio_init(bitLedEight);

    // Sets the directions for the maker board LED's as outputs.
    gpio_set_dir(bitLedOne, GPIO_OUT);
    gpio_set_dir(bitLedTwo, GPIO_OUT);
    gpio_set_dir(bitLedThree, GPIO_OUT);
    gpio_set_dir(bitLedFour, GPIO_OUT);
    gpio_set_dir(bitLedFive, GPIO_OUT);
    gpio_set_dir(bitLedSix, GPIO_OUT);
    gpio_set_dir(bitLedSeven, GPIO_OUT);
    gpio_set_dir(bitLedEight, GPIO_OUT);

    // Creates events for when a button is initially pressed which updates buzzer frequency. 
    gpio_set_irq_enabled_with_callback(buttonOnePin, GPIO_IRQ_EDGE_FALL, true, &updateCounter);   // Lowers the counter if button one is pressed.
    gpio_set_irq_enabled_with_callback(buttonTwoPin, GPIO_IRQ_EDGE_FALL, true, &updateCounter);   // Resets the counter if button two is pressed.
    gpio_set_irq_enabled_with_callback(buttonThreePin, GPIO_IRQ_EDGE_FALL, true, &updateCounter); // Ups the counter if button three is pressed.

    // Loop which checks for the events, if any occur then there corresponding function is called.
    while (true) { tight_loop_contents(); }
}

