
#ifndef DEFINE_H
#define DEFINE_H


#include <Arduino.h>
#include <TFT_eSPI.h> 
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include "Free_Fonts.h"
#include "xbm.h" 
#include "Display.h"
#ifdef __cplusplus
extern "C" {
#endif

#define DF_LED 25
#define DF_BUZZ 33
#define DF_TRIG 26
#define DF_ECHO 27
#define DF_SERVO1 14
#define DF_SERVO2 12
#define TFT_GREY 0x5AEB
#define DF_TIMERESETVALUE 30000
#ifdef __cplusplus
}
#endif

#endif