#ifndef __DELAY_H
#define __DELAY_H
void delay(unsigned int count){
    int i,j;
    for(i=0; i<count;i++)
        for(j=0; j<112; j++);
}
#endif