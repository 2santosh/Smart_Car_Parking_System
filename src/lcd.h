#ifndef __LCD_H
#define __LCD_H
#include"delay.h"// Define LCD pins

sfr lcd_data_port = 0x90; // P1 port as data port
sbit rs = P2^0;  // Register select pin
sbit rw = P2^1;  // Read and Write pin
sbit en = P2^2;  // Enable pin

void LCD_command(char cmd);
void LCD_char(char char_data);
void LCD_String(char*str);
void LCD_String_xy(char row, char pos,char*str);
void LCD_init(void);

void LCD_command(char cmd)  //LCD command funtion
{
    lcd_data_port = cmd;
    rs = 0;
    rw = 0;
    en = 1;
    delay(1);
    en = 0;
    //delay(3);
}

void LCD_char(char char_data) // LCD data write function
{
    lcd_data_port = char_data; 
    rs = 1;
    rw = 0;
    en = 1;
    delay(1);
    en = 0;
    //delay(4);
}

void LCD_String(char*str) // Send string to LCD function
{
   while(*str){
    LCD_char(*str++);
   }
}

void LCD_String_xy(char row, char pos,char*str) // Send string to LCD function
{
    if(row == 0)
    LCD_command((pos & 0x0F) | 0x80);
    else if(row == 1)
    LCD_command((pos & 0x0F)|0xC0);
    LCD_String(str);
}

void LCD_init(void) // LCD initialize function
{
    LCD_command (0x38);  // initialization of 16X2 LCD in 4bit mode
    LCD_command (0x0e);  // Display on cursor off
    LCD_command (0x06);  // auto incement cursor 
    LCD_command (0x01); // clear display
    LCD_command (0xc0); // cursor at home position
}

#endif