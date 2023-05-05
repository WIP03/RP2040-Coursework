# Sets minimum version for the CMaker#
cmake_minimum_required(VERSION 3.13)

# Pulls in the pico sdk #
include(pico_sdk_import.cmake)

# Sets the name of are project #
project(RP2040-Coursework)

# Checks the SDK version meets are minimum requirements #
if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

# Initialize the SDK #
pico_sdk_init()

# Adds directories for original projects made by me #
add_subdirectory(Fading_LED)
#add_subdirectory(Binary_Buzzer)

# Adds directories for projects made by others that I completed the stubs for #
add_subdirectory(Light_Button)
add_subdirectory(Tone_Generator)
add_subdirectory(Four_Bit_Binary_Counter)
add_subdirectory(Musical_Blink)
add_subdirectory(Pico_Fat_Writer)
#add_subdirectory()
