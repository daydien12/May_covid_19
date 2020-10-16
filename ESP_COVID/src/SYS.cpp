#include "SYS.h"


void Sys_Init(void)
{
    Serial.begin(9600);
    SENSORCT_Init(); 
    DISPLAY_Init();
}

char Sys_Check_ReadTemp(unsigned char vruc_Up, unsigned char vruc_Down)
{
    if((SENSORCT_ReadSRF04(DF_TRIG_SENSOR, DF_ECHO_SENSOR) >= vruc_Down) && (SENSORCT_ReadSRF04(DF_TRIG_SENSOR, DF_ECHO_SENSOR)<= vruc_Up))
        return 1;
    return 0;
}

void Sys_DisplayTemperature(void)
{
   tft.drawFloat(SENSORCT_ReadMLX906(50),2, 30, 30, 7);
}
