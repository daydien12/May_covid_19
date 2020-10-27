
#ifndef CONTROL_H
#define CONTROL_H
#include "Define.h"
#ifdef __cplusplus
extern "C" {
#endif
extern unsigned int vrui_CountMotoStep;
void SENSORCT_Init(void);
char SENSORCT_StartWash(void);
void SENSORCT_ContrBUZZ(unsigned char vruc_stt);
double SENSORCT_ReadMLX906(int vrui_Count);

#ifdef __cplusplus
}
#endif

#endif