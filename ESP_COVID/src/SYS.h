
#ifndef SYS_H
#define SYS_H
#include "Define.h"
#ifdef __cplusplus
extern "C" {
#endif
extern unsigned char vruc_ModeStep, vruc_StartStopStep, vruc_RunStart;
void Sys_Init(void);
void Sys_Run();
#ifdef __cplusplus
}
#endif

#endif