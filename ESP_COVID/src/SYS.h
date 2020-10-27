
#ifndef SYS_H
#define SYS_H
#include "Define.h"
#ifdef __cplusplus
extern "C" {
#endif

void Sys_Init(void);
<<<<<<< Updated upstream
int  Sys_ReadSRF04(void);
char Sys_ContrLED(void);
void Sys_ContrBUZZ(unsigned char vruc_stt);
double Sys_ReadMLX906(int vrui_Count);
char Sys_Check_ReadTemp(unsigned char vruc_Up, unsigned char vruc_Down);
void Sys_DisplayTemperature(void);
=======
void Sys_Run(void);
>>>>>>> Stashed changes
#ifdef __cplusplus
}
#endif

#endif