#include<reg51.h>
#include<stdio.h>
#include<math.h>
#include<intrins.h>
#include"src/delay.h"
#include"src/lcd.h"
#include"src/servo.h"
#include"src/led.h"
#include"src/mes.h"
#include"src/ir.h"
void main()
{
    green = 0;
    red = 0;
    green1 = 0;
    red1 = 0;  
    while(1){
        dis();  
        LCD_command(0x00);      
     
        if(ir == 1 && ir1 == 0){
            red = 1;
            red1 = 1;
            if(car != 0){
                red = 0;
                green = 1;
                LCD_init();
                LCD_String("        SPS         ");
                LCD_String_xy(1,0,"WELL COME TO SPS");
                servo_control(90);
                delay(2);
                car--;
                green = 0;
                LCD_command(0x01);//Clear the screen
                dis();
                red1 = 0;
                servo_control(0);
							
            }
            else{
                red = 1;
                LCD_init();
                LCD_String("        SPS         ");
                LCD_String_xy(1,1," SORRY !! ");
                LCD_String_xy(1,0,"NO PARKING SPACE !!!");
                delay(1500);
                red = 0;
            }
        }
        else if(ir == 0 && ir1 == 1){
            if(car <= 3){
                red = 1;
                red1 = 0;
                green1 = 1;
                car ++;
                LCD_init();
                LCD_String("        SPS         ");
                LCD_String_xy(1,3," THANK YOU !!");
                servo_control(90);
                delay(2);
                LCD_command(0x01);
                dis();
                green1 = 0;
                red = 0;
                servo_control(0);
                }
            else{
                red1 = 1;
                LCD_init();
                LCD_String("        SPS         ");
                LCD_String_xy(1,1," SORRY !! ");
                LCD_String_xy(1,0," This isn't car !!!");
                delay(1500);
                red1 = 0;
            }		
        }
        else if(ir == 1 && ir1 == 1){
            red1 = 1;
            green = 1;
            LCD_init();
            LCD_String("        SPS         ");
            LCD_String_xy(1,1,"WELL COME TO SPS");
            servo_control(90);
            delay(500);
            green = 0;
            red = 1;
            red1 = 0;
            green1 = 1;
            LCD_init();
            LCD_String("        SPS         ");
            LCD_String_xy(1,1,"THANK YOU !!");
            delay(4000);
            green1 = 0;
            LCD_command(0x01);
            dis();
            red = 0;
            servo_control(0);
        }
    }
}