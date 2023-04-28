#include "pico/stdlib.h"


const uint decrementButton = 21;
const uint incrementButton = 22;
const uint resetButton = 20;

const uint bitLedOne= 5;
const uint bitLedTwo = 4;
const uint bitLedThree = 3;
const uint bitLedFour = 2;




int main() {

    //Initialise your IO

    int counter = 0;



    while (true) {
        if((counter % 2) > 0) {gpio_put(bitLedOne,1);} else {gpio_put(bitLedOne,0);}
        //Add for the other LED's

        if(gpio_get(incrementButton) == 0){}
        //Make the buttons do something




    }
}

