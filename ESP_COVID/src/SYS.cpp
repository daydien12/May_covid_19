#include "SYS.h"

<<<<<<< Updated upstream
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
=======
AccelStepper stepper = AccelStepper(1, DF_MOTOR_STEP, DF_MOTOR_DIR);
double vrud_TempReadMLX906 = 0;
unsigned char vruc_ModeStep = 1, vruc_StartStopStep = 0, vruc_RunStart = 0;
unsigned int vruc_CountRunStart = 0 ;
unsigned int  vrui_CountUv = 0 ;
>>>>>>> Stashed changes

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

<<<<<<< Updated upstream
double Sys_ReadMLX906(int vrui_Count)
{
    double vrul_Sum = 0;
    for(int i=0; i < vrui_Count; i++)
=======
void Sys_Run(void)
{
//--------------------------------------------------------------------------   
    if(digitalRead(DF_UV))
    {
        if(vrui_CountUv <= 10000)
        {   
            digitalWrite(DF_RELAY,0);
        }
        else if(vrui_CountUv > 250000 && vrui_CountUv <= 450000)
        {
            digitalWrite(DF_RELAY,1);
        }
        else
        {
            digitalWrite(DF_RELAY,0);
        }
            vrui_CountUv++;
        delayMicroseconds(1);
    }
    else
    {
        digitalWrite(DF_RELAY,0);
        vrui_CountUv = 0;
    }
//--------------------------------------------------------------------------

    if(digitalRead(DF_START))
    {
        if((vruc_CountRunStart >= 500))
        {
            vruc_RunStart = 1;
            vruc_CountRunStart = 0;
            vruc_StartStopStep = 1;
        }
        if((vruc_RunStart == 0))
        {
            vruc_CountRunStart++;
            Serial.println(vruc_CountRunStart);
             delay(1);
        }
    }
    else
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
        vrui_StartWashHand = 1;
        vrui_StartBodyTemperature = 1;
=======
        SENSORCT_StartWash();
        DISPLAY_DisWashingHand(10,210);
        if(vruc_StartStopStep)
        {
             if(vruc_ModeStep)
            {
                if(digitalRead(DF_TIMCANCHECKSENSOR) == 1)
                {
                    stepper.setSpeed(0);
                    stepper.stop();
                    vrud_TempReadMLX906 = SENSORCT_ReadMLX906(50);
                    if(vrud_TempReadMLX906 >= 34)
                    {
                       vrui_StartBodyTemperature = 1;
                       DISPLAY_PlotPointer(vrud_TempReadMLX906);
                        vruc_ModeStep = 0;
                    }
                }
                else
                {
                    stepper.setSpeed(-400);
                    stepper.runSpeed();
                }
            }
            else
            {
                if(digitalRead(DF_SWITCHITI))
                {
                    vruc_ModeStep = 1;
                    vruc_StartStopStep = 0;
                    stepper.setSpeed(0);
                    stepper.stop();
                }
                else
                {
                    stepper.setSpeed(400);
                    stepper.runSpeed();
                }
            }
        }
>>>>>>> Stashed changes
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
