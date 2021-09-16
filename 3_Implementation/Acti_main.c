/**
 * @file Acti_main.c
 * @author Vijaymahantesh (vijaymkb03@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "Acti_1.h"
#include "Acti_2.h"
#include "Acti_3.h"



int main(void)
{
    uint16_t temp;

    while(1)
    {
        if(LED()==1) //Check if both the switches are pressed
        {
            LED_ON();          //Turn LED ON
            temp=GetADC();     //To Get the ADC value
            PWM(temp);         //this is to PWM output based on temperature
		        USARTWrite(temp); //this is for Serial monitor to display Temperature
        }
        else  // other cases
        {
            LED_OFF();     //Turn LED OFF
	    _delay_ms(200);
        }
    }
    return 0;
}
