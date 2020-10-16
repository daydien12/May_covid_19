
#ifndef SYS_H
#define SYS_H
#include "Define.h"
#ifdef __cplusplus
extern "C" {
#endif

void Sys_Init(void);

char Sys_Check_ReadTemp(unsigned char vruc_Up, unsigned char vruc_Down);
void Sys_DisplayTemperature(void);
#ifdef __cplusplus
}
#endif

#endif