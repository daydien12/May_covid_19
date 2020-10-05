#include "SYS.h"

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void Sys_Init(void)
{
    Serial.begin(9600); 
    mlx.begin();
    DISPLAY_Init();
    pinMode(DF_TRIG, OUTPUT); 
    pinMode(DF_ECHO, INPUT);
    pinMode(DF_LED, INPUT);
    pinMode(DF_BUZZ, OUTPUT);
}

double Sys_ReadMLX906(int vrui_Count)
{
    double vrul_Sum = 0;
    for(int i=0; i < vrui_Count; i++)
    {
        vrul_Sum +=  mlx.readObjectTempC();
    }
    return (vrul_Sum/vrui_Count)+2;
}

int Sys_ReadSRF04(void)
{
    long duration;
    int distance;
    digitalWrite(DF_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(DF_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(DF_TRIG, LOW);
    duration = pulseIn(DF_ECHO, HIGH);
    distance = duration*0.034/2; 
    return distance;
}

char Sys_ContrLED(void)
{
    if(!digitalRead(DF_LED))
    {
        vrui_StartWashHand = 1;
        vrui_StartBodyTemperature = 1;
    }
        
}

void Sys_ContrBUZZ(unsigned char vruc_stt)
{
    digitalWrite(DF_BUZZ, vruc_stt);
}

char Sys_Check_ReadTemp(unsigned char vruc_Up, unsigned char vruc_Down)
{
    if((Sys_ReadSRF04() >= vruc_Down) && (Sys_ReadSRF04() <= vruc_Up))
        return 1;
    return 0;
}

void Sys_DisplayTemperature(void)
{
   tft.drawFloat(Sys_ReadMLX906(50),2, 30, 30, 7);
}
