/*
Library created by William Percy (wip1g21)
Code and concepts adapted from this rp forum post: https://forums.raspberrypi.com/viewtopic.php?t=336775
*/

#ifndef _PicoType_h
#define _PicoType_h

// Needed libraries
#include "pico/stdlib.h"
#include "hardware/adc.h"

// Defines the cache value for the library.
int32_t isPicoW_Cached;

// Defines the libraries main funtion.
int32_t IsPicoW(void);

#endif