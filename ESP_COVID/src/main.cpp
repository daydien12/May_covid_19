#include "SYS.h"
int  stt = 0, temp = 0;
void setup() 
{
  Sys_Init();
}

void loop() 
{
 // Sys_ContrLED();
  //DISPLAY_DisWashingHand(10,210);
  //DISPLAY_PlotPointer(((40 - 36.4) * ((float)rand() / RAND_MAX)) + 36.4);
  //DISPLAY_PlotPointer(1);
  //stt =! stt;
  //SENSORCT_MotoStep(stt, 0);
 // temp = SENSORCT_ReadSRF04(DF_TRIG_SENSOR, DF_ECHO_SENSOR);
//  temp = digitalRead(DF_TIMCANCHECKSENSOR);
//   if(digitalRead(DF_TIMCANCHECKSENSOR) == 1)
//   {
//     SENSORCT_MotoStep(1, 0);
//   }
//   else
//   {
//     SENSORCT_MotoStep(1, 1);
//   }
   Serial.print("SR1: ");
  Serial.println(SENSORCT_ReadSRF04(DF_TRIG_CHECK1, DF_ECHO_CHECK1));
   Serial.print("SR2: ");
  Serial.println(SENSORCT_ReadSRF04(DF_TRIG_CHECK2, DF_ECHO_CHECK2));
  delay(50);
}