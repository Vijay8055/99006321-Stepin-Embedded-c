/**
 * @file Acti_1.c
 * @author Vijaymahantesh (vijaymkb03@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Acti_1.h"


void init_peripheral(void)
{
    DDRD |= (1<<PD2); // set PD2=1 for LED
    DDRD &= ~(1<<PD0); //clear bit
    PORTD |= (1<<PD0); //set bit PD0 for SeatSwitch
    DDRD &= ~(1<<PD1); //clear bit
    PORTD |= (1<<PD1); //set bit PD0 for HeaterSwitch
}

void LED_ON(){
    LED_PORT |= (1<<LED_PIN);
}

void LED_OFF(){
    LED_PORT &= ~(1<<LED_PIN);
}

int FLAG=0;
int LED(void)
{
       init_peripheral();
        if(!(PIND&(1<<BUTTON_SENSOR )) && !(PIND&(1<<TEMP_SENSOR))) //if both the switches are pressed
        {
            FLAG=1;
        }
        else  // other cases
        {
            FLAG=0;
        }
    return FLAG;
}

