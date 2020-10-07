#include "SYS.h"

void setup() {
  Sys_Init();
}

void loop() {
  Sys_ContrLED();
  DISPLAY_DisWashingHand(10,210);
  //DISPLAY_PlotPointer(((40 - 36.4) * ((float)rand() / RAND_MAX)) + 36.4);
  DISPLAY_PlotPointer(1);
}