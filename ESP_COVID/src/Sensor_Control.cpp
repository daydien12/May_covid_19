#include "SYS.h"
unsigned int vrui_CountMotoStep = 0;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void SENSORCT_Init(void)
{
    mlx.begin();
    pinMode(DF_TRIG_CHECK1, OUTPUT); 
    pinMode(DF_ECHO_CHECK1, INPUT);
    
    pinMode(DF_TRIG_CHECK2, OUTPUT); 
    pinMode(DF_ECHO_CHECK2, INPUT);
    pinMode(DF_LED, INPUT);
    pinMode(DF_BUZZ, OUTPUT);
    pinMode(DF_MOTOR_DIR, OUTPUT);
    pinMode(DF_MOTOR_STEP, OUTPUT);

   pinMode(26, INPUT_PULLUP); 
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

int SENSORCT_ReadSRF04(unsigned char vruc_Trig, unsigned char vruc_ECHO)
{
    long duration;
    int distance;
    digitalWrite(vruc_Trig, LOW);
    delayMicroseconds(2);
    digitalWrite(vruc_Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(vruc_Trig, LOW);
    duration = pulseIn(vruc_ECHO, HIGH);
    distance = duration*0.034/2; 
    if(distance <= 150 && distance > 5)
        return distance;
    else
        return 0;
}

char SENSORCT_ContrLED(void)
{
    if(!digitalRead(DF_LED))
    {
        vrui_StartWashHand = 1;
        vrui_StartBodyTemperature = 1;
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
    //delay(200);  
  }
}