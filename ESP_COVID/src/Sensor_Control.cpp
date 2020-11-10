#include "SYS.h"
unsigned int vrui_CountMotoStep = 0;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void SENSORCT_Init(void)
{
    mlx.begin();
    pinMode(DF_LED, INPUT);
    pinMode(DF_BUZZ, INPUT);
    pinMode(DF_MOTOR_DIR, OUTPUT);
    pinMode(DF_MOTOR_STEP, OUTPUT);
    pinMode(DF_TIMCANCHECKSENSOR, INPUT_PULLUP); 
    pinMode(DF_SWITCHITI, INPUT_PULLDOWN);
    pinMode(DF_RELAY, OUTPUT);
    pinMode(DF_UV, INPUT);
    pinMode(DF_START, INPUT);
    pinMode(DF_LEDSTART, OUTPUT);
}

double SENSORCT_ReadMLX906(int vrui_Count)
{
    double vrul_Sum = 0;
    for(int i=0; i < vrui_Count; i++)
    {
        vrul_Sum +=  mlx.readObjectTempC();
    }
    return (vrul_Sum/vrui_Count)+2;
}


char SENSORCT_StartWash(void)
{
    if(digitalRead(DF_LED))
    {
        vrui_StartWashHand = 1;
       // vrui_StartBodyTemperature = 1;
    }
}

void SENSORCT_ContrBUZZ(unsigned char vruc_stt)
{
    digitalWrite(DF_BUZZ, vruc_stt);
}

void SENSORCT_MotoStep(unsigned char vruc_Stt, unsigned char vruc_Stop)
{
  if(vruc_Stop)
  {
    if(vruc_Stt)
    {
        digitalWrite(DF_MOTOR_DIR, LOW);
    }
    else
    {
        digitalWrite(DF_MOTOR_DIR, HIGH);
    }
    if (vrui_CountMotoStep <= stepsPerRevolution) {
        digitalWrite(DF_MOTOR_STEP, HIGH);
        delayMicroseconds(500);
        digitalWrite(DF_MOTOR_STEP, LOW);
        delayMicroseconds(500);
        vrui_CountMotoStep ++;
    }
     // Serial.println(vrui_CountMotoStep);
  }
}