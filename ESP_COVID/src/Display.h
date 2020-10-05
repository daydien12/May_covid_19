
#ifndef DISPLAY_H
#define DISPLAY_H
#include "Define.h"
#ifdef __cplusplus
extern "C" {
#endif
extern TFT_eSPI tft;
extern unsigned int vrui_TimeWashHand, vrui_CountTimeWashHand, vrui_StartWashHand, vrui_CountStepWashHand, vrui_NumberDisplay;
extern unsigned char vrui_CheckDoneWashHand;

extern unsigned char vrui_StartBodyTemperature, vrui_CountBodyTemperature;

void DISPLAY_Init(void);
void DISPLAY_Displaybodyteamp(void);
void DISPLAY_DisWashingHand(unsigned char vruc_X, unsigned char vruc_Y);
void DISPLAY_TimeWashHands(unsigned char X, unsigned char Y, unsigned char Number);
void DISPLAY_PlotLinear(char *label, int x, int y);
void DISPLAY_PlotPointer(float number);
#ifdef __cplusplus
}
#endif

#endif