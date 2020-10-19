#include "Display.h"
#include "SYS.h"
int value[6] = {0, 0, 0, 0, 0, 0};
int old_value[6] = { -1, -1, -1, -1, -1, -1};
int d = 0;
TFT_eSPI tft = TFT_eSPI(); 
unsigned int vrui_TimeWashHand = 0, vrui_CountTimeWashHand = 0, vrui_StartWashHand = 0, vrui_CountStepWashHand = 0, vrui_NumberDisplay = 0;
unsigned char vrui_CheckDoneWashHand = 0, vrui_StartBodyTemperature = 0, vrui_CountBodyTemperature = 0;


void DISPLAY_Init(void)
{
    tft.init();
    tft.fillScreen(TFT_WHITE);
    tft.setRotation(2);

    tft.fillRect(0, 0, 240, 145, TFT_GREY);
    tft.fillRect(5, 3, 230, 137, TFT_WHITE);

    tft.fillRect(0, 160, 240, 160, TFT_GREY);
    tft.fillRect(5, 165, 230, 150, TFT_WHITE);

    Display_2Image(0,0,0);
  
    for(int i=1; i<7;i++)
        tft.drawLine(180+i,3,180+i,139,TFT_GREY);
    for(int i=1; i<7;i++)
        tft.drawLine(0,75+i,180,75+i,TFT_GREY);
  
    DISPLAY_PlotLinear("A0", 188, 3);
}

void DISPLAY_PlotLinear(char *label, int x, int y)
{
    int k = 43;
    tft.fillRect(187, 3, 49, 136, TFT_WHITE);
    tft.setFreeFont(FF21);  
    tft.setTextColor(TFT_RED, TFT_WHITE);
    tft.drawCircle(210,10,3,TFT_RED);
    tft.drawCircle(210,10,2,TFT_RED);
    tft.drawString("C",200 + 36 / 2, 3 + 2, 1);
    tft.setFreeFont(TT1);   
    tft.setTextColor(TFT_BLACK, TFT_WHITE); 
    for (int i = 0; i < 110; i += 10)
    {
       
       if(i>=40 && i <70)
        {
            tft.drawFastHLine(x + 20, y + 27 + i, 6, TFT_RED);
        }
        else if(i >= 70 && i<=80)
        {
            tft.drawFastHLine(x + 20, y + 27 + i, 6, TFT_GREEN);
        }
        else
        {
            tft.drawFastHLine(x + 20, y + 27 + i, 6, TFT_BLACK);
        }
        char buf[8]; 
        dtostrf(k, 4, 0, buf);
        tft.drawString(buf, x + 30, y + 27 + i, 1);   
        k--;     
    }
    

    for (int i = 0; i < 110; i += 50)
    {
        if(i>=0 && i <40)
        {
            tft.drawFastHLine(x + 20, y + 27 + i, 10, TFT_BLACK);
        }
        else if(i>=40 && i <70)
        {
             tft.drawFastHLine(x + 20, y + 27 + i, 10, TFT_RED);
        }
        else
        {    
             tft.drawFastHLine(x + 20, y + 27 + i, 10, TFT_BLACK);
        }        
    }
}

void DISPLAY_PlotPointer(float number1)
{
    if(vrui_StartBodyTemperature)
    {
       float number = number1;//SENSORCT_ReadMLX906(50);
        int dy = 50;
        byte pw = 16;
        value[0] = map(number+4,33,53,0,100);
        int dx = 190;

        tft.fillRect(5, 82, 176, 58, TFT_WHITE);
        tft.setTextColor(TFT_BLACK, TFT_WHITE);
        tft.drawFloat(number, 2, 10, 85, 7);
        tft.setFreeFont(FF22);  
        tft.drawString("C", 158, 85, 1);
        tft.drawCircle(152, 88, 3,TFT_BLACK); 
        tft.drawCircle(152, 88, 2,TFT_BLACK); 

        if (value[0] < 0) value[0] = 0; 
        if (value[0] > 100) value[0] = 100;

        while (!(value[0] == old_value[0])) 
        {
            dy = 30 + 100 - old_value[0];
            if (old_value[0] > value[0])
            {
                tft.drawLine(dx, dy - 5, dx + pw, dy, TFT_WHITE);
                old_value[0]--;
                tft.drawLine(dx, dy + 6, dx + pw, dy + 1, TFT_RED);
            }
            else
            {
                tft.drawLine(dx, dy + 5, dx + pw, dy, TFT_WHITE);
                old_value[0]++;
                tft.drawLine(dx, dy - 6, dx + pw, dy - 1, TFT_RED);
            }
        }
        vrui_StartBodyTemperature = 0;
    }
}

void DISPLAY_Displaybodyteamp(void)
{
    delay(100);
}

void DISPLAY_DisWashingHand(unsigned char vruc_X, unsigned char vruc_Y)
{
    if(vrui_StartWashHand)
    {
         if(vrui_CountTimeWashHand >= 1000)
        {
            vrui_NumberDisplay++;
            DISPLAY_TimeWashHands(50,180,vrui_NumberDisplay);
            vrui_CountTimeWashHand = 0;
        }
        switch (vrui_CountStepWashHand)
        {
            case 0:
                tft.fillRect(5, 165, 230, 150, TFT_WHITE);
                //tft.fillRect(5, 165, 230, 52, TFT_WHITE);
                DISPLAY_TimeWashHands(50,180,vrui_NumberDisplay);
                Display_2Image(vruc_X, vruc_Y, 1);
            break;

            case 10000:
                Display_2Image(vruc_X, vruc_Y, 2);
            break;

            case 20000:
                Display_2Image(vruc_X, vruc_Y, 3);
            break;

            case 30000:
                Display_2Image(0,0,0);
                vrui_StartWashHand = 0;
                vrui_CheckDoneWashHand = 0;
                vruc_RunStart = 0;
            break;
        }
        vrui_CountStepWashHand++;
        vrui_CountTimeWashHand++; 
        delay(1);
    }
    else
    {
        vrui_CountStepWashHand = 0;
        vrui_CountTimeWashHand = 0;
        vrui_NumberDisplay = 0;
    }
   
}

void Display_2Image(unsigned char X, unsigned char Y, unsigned char select)
{
    unsigned offset = 120;
    tft.setSwapBytes(true);
    switch(select)
    {
        case 0:
            tft.fillRect(5, 165, 230, 150, TFT_WHITE);
            tft.pushImage(10, 170, DF_XBM_WaitHand_W, DF_XBM_WaitHand_H, XBM_WaitHand);
            tft.setFreeFont(FF9);            
            tft.setTextColor(TFT_WHITE, TFT_RED);
            tft.drawString("Hand sanitizer below", 9, 295, 1);
        break;

        case 1:
            tft.fillRect(5, 210, 230, 105, TFT_WHITE);
            tft.pushImage(X, Y, DF_XBM_STEPWASH_W, DF_XBM_STEPWASH_H, XBM_B1);
            tft.pushImage(offset+X, Y, DF_XBM_STEPWASH_W, DF_XBM_STEPWASH_H, XBM_B2);
        break;
        
        case 2:
            tft.fillRect(5, 210, 230, 105, TFT_WHITE);
            tft.pushImage(X, Y, DF_XBM_STEPWASH_W, DF_XBM_STEPWASH_H, XBM_B3);
            tft.pushImage(offset+X, Y, DF_XBM_STEPWASH_W, DF_XBM_STEPWASH_H, XBM_B4);
        break;
        
        case 3:
            tft.fillRect(5, 210, 230, 105, TFT_WHITE);
            tft.pushImage(X, Y, DF_XBM_STEPWASH_W, DF_XBM_STEPWASH_H, XBM_B5);
            tft.pushImage(offset+X, Y, DF_XBM_STEPWASH_W, DF_XBM_STEPWASH_H, XBM_B6);
        break;
    }
}

void DISPLAY_TimeWashHands(unsigned char X, unsigned char Y, unsigned char Number)
{
    int offset = 80;
    tft.setFreeFont(FF10);            
    tft.setTextColor(TFT_WHITE, TFT_RED);
    if(Number == 0)
    {
        tft.fillRect(5, 165, 230, 52, TFT_WHITE);
        tft.pushImage(10, 170, DF_XBM_CLOCK_W, DF_XBM_CLOCK_H, XBM_CLOCK);
        tft.drawString("TIME: ", X, Y, 1);
    }
    tft.drawNumber(Number,X+offset, Y,1);
}