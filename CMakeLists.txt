# Sets minimum version for the CMaker#
cmake_minimum_required(VERSION 3.12)

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
add_subdirectory(TCP_Math_Parser)
add_subdirectory(Image_Display)

# Adds directories for projects made by others that I completed the stubs for #
#add_subdirectory()
