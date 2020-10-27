#include "SYS.h"
unsigned int vrui_CountMotoStep = 0;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void SENSORCT_Init(void)
{
    mlx.begin();
    pinMode(DF_LED, INPUT);
    pinMode(DF_BUZZ, OUTPUT);
    pinMode(DF_MOTOR_DIR, OUTPUT);
    pinMode(DF_MOTOR_STEP, OUTPUT);
    pinMode(DF_TIMCANCHECKSENSOR, INPUT); 
    pinMode(DF_SWITCHITI, INPUT_PULLDOWN);
    pinMode(DF_RELAY, OUTPUT);
    pinMode(DF_UV, INPUT);
    pinMode(DF_START, INPUT);
}

double SENSORCT_ReadMLX906(int vrui_Count)
{
    double vrul_Sum = 0, vrui_Temp = 0;
    for(int i=0; i < vrui_Count; i++)
    {
        vrul_Sum +=  mlx.readObjectTempC();
    }
    vrui_Temp = (vrul_Sum/vrui_Count)+2;
    if(vrui_Temp < 45 && vrui_Temp > 20)
        return vrui_Temp;
    return 0;
}


char SENSORCT_StartWash(void)
{
    if(digitalRead(DF_LED))
    {
        vrui_StartWashHand = 1;
    }
}

void SENSORCT_ContrBUZZ(unsigned char vruc_stt)
{
    digitalWrite(DF_BUZZ, vruc_stt);
}
