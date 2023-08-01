#ifndef __SERVO_H
#define __SERVO_H
#include"delay.h"
// Define Servo pins
sbit servo_pin = P2^3; 
void servo_control(unsigned int degree){
    unsigned int i;
    for(i=1;i<3;i++){
        servo_pin = 1;
        delay(degree);
        servo_pin = 0;
        delay(1500-degree);
    }
}
#endif