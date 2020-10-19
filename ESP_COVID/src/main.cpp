#include "SYS.h"

void setup() 
{
  Sys_Init();
}

void loop() 
{
  Sys_Run();
  
 // Serial.println(digitalRead(DF_START));
}