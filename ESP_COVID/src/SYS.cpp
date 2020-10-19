#include "SYS.h"

AccelStepper stepper = AccelStepper(1, DF_MOTOR_STEP, DF_MOTOR_DIR);
double vrud_TempReadMLX906 = 0;
unsigned char vruc_ModeStep = 1, vruc_StartStopStep = 0, vruc_RunStart = 0;
unsigned int vruc_CountRunStart = 0 ;
void Sys_Init(void)
{
    Serial.begin(9600);
    stepper.setMaxSpeed(1000);
    SENSORCT_Init(); 
    DISPLAY_Init();
}

void Sys_Run()
{
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
    {
        while(1)
        {
            if(digitalRead(DF_SWITCHITI))
            {
                stepper.setSpeed(0);
                stepper.stop();
                break;
            }
            else
            {
                stepper.setSpeed(400);
                stepper.runSpeed();
            }
        }
       
        if(vrui_StartWashHand)
        {
            Display_2Image(0,0,0);
            vrui_StartWashHand = 0;
            vrui_CountStepWashHand = 0;
            vrui_CountTimeWashHand = 0;
            vrui_NumberDisplay = 0;
        }
       
        vruc_CountRunStart = 0;
        vruc_RunStart = 0;
        vruc_ModeStep = 1;
    }

    if(vruc_RunStart)
    {
        SENSORCT_StartWash();
        DISPLAY_DisWashingHand(10,210);
        //DISPLAY_PlotPointer(((40 - 36.4) * ((float)rand() / RAND_MAX)) + 36.4);
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
    }
}



