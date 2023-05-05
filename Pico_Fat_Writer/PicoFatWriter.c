#include <stdio.h>
#include "pico/stdlib.h"
#include "ff.h"
#include "f_util.h"
#include "hw_config.h"

int main() {
    // See FatFs - Generic FAT Filesystem Module, "Application Interface",
    // http://elm-chan.org/fsw/ff/00index_e.html
    sd_card_t *pSD = sd_get_by_num(0);

    // Register the work area of the volume.
    FRESULT fr = f_mount(&pSD->fatfs, pSD->pcName, 1);
    if (FR_OK != fr) panic("f_mount error: %s (%d)\n", FRESULT_str(fr), fr);

    // Open.
    FIL fil;
    const char* const filename = "test.txt";
    fr = f_open(&fil, filename, FA_OPEN_APPEND | FA_WRITE);
    if (FR_OK != fr && FR_EXIST != fr) { panic("f_open(%s) error: %s (%d)\n", filename, FRESULT_str(fr), fr); }
    
    // Write to the file.
    if (f_printf(&fil, "Hello, pico!\n") < 0) { printf("f_printf failed\n");}

    // Close the file.
    fr = f_close(&fil);
    if (FR_OK != fr) { printf("f_close error: %s (%d)\n", FRESULT_str(fr), fr); }

    // Deregister the workspace.
    f_unmount(pSD->pcName);

    for(;;);
}