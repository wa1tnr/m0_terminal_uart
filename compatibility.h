// Wed Jan 31 00:39:34 UTC 2018
// 4737-a0e-03a-

// previous timestamp:
// Tue Jan 16 02:30:09 UTC 2018
// 4737-a0d-05j-

// packages/adafruit/hardware/samd/1.0.18/boards.txt:173:adafruit_gemma_m0.build.extra_flags=-DCRYSTALLESS -DADAFRUIT_GEMMA_M0 -D__SAMD21E18A__ {build.usb_flags}

// In July 2017, all boards were SAMD21G18A except Gemma M0, which is SAMD21E18A (similar inside, fewer pins brought out?)

#ifdef ADAFRUIT_FEATHER_M0_EXPRESS
  #define HAS_SPI_FLASH_DEMO
#endif // #ifdef ADAFRUIT_FEATHER_M0_EXPRESS

#ifdef ADAFRUIT_CIRCUITPLAYGROUND_M0
  #define HAS_SPI_FLASH_DEMO
#endif // #ifdef ADAFRUIT_CIRCUITPLAYGROUND_M0

#ifdef ADAFRUIT_METRO_M0_EXPRESS
  #define HAS_SPI_FLASH_DEMO
#endif // #ifdef ADAFRUIT_METRO_M0_EXPRESS


// Six targets for January, 2018:
// ADAFRUIT_FEATHER_M0_EXPRESS
// ADAFRUIT_METRO_M0_EXPRESS
// ADAFRUIT_CIRCUITPLAYGROUND_M0
// ADAFRUIT_GEMMA_M0
// ADAFRUIT_TRINKET_M0
// ADAFRUIT_ITSYBITSY_M0
