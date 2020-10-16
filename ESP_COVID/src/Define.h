
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
#include "Sensor_Control.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DF_LED 25
#define DF_BUZZ 33

#define DF_TIMCANCHECKSENSOR 26
#define DF_TRIG_SENSOR 26
#define DF_ECHO_SENSOR 27

#define DF_TRIG_CHECK1 35
#define DF_ECHO_CHECK1 32

#define DF_TRIG_CHECK2 39
#define DF_ECHO_CHECK2 34

#define DF_SERVO1 14
#define DF_SERVO2 12


#define DF_MOTOR_STEP 16
#define DF_MOTOR_DIR 17


#define TFT_GREY 0x5AEB
#define DF_TIMERESETVALUE 30000
#define stepsPerRevolution 500*15

#ifdef __cplusplus
}
#endif

#endif