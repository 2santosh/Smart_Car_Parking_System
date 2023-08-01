#ifndef __MES_H
#define __MES_H
#include"lcd.h"
#include"delay.h"
unsigned int car = 4;
void dis(){
	unsigned char set[10];
    LCD_init();
    LCD_String(" PARKING SYSTEM  ");
    LCD_String_xy(1,1,"T_SPACE:   4");  
    delay(500); 
    LCD_String_xy(1,1,"AB_SPACE:  ");
    sprintf(set,"%d",car);
    LCD_String_xy(2,1,set);
    delay(500);
}
#endif