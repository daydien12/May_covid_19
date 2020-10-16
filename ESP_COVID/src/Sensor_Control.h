
#ifndef CONTROL_H
#define CONTROL_H
#include "Define.h"
#ifdef __cplusplus
extern "C" {
#endif
extern unsigned int vrui_CountMotoStep;
void SENSORCT_Init(void);
int  SENSORCT_ReadSRF04(unsigned char vruc_Trig, unsigned char vruc_ECHO);
char SENSORCT_ContrLED(void);
void SENSORCT_ContrBUZZ(unsigned char vruc_stt);
double SENSORCT_ReadMLX906(int vrui_Count);
void SENSORCT_MotoStep(unsigned char vruc_Stt, unsigned char vruc_Stop);

#ifdef __cplusplus
}
#endif

#endif