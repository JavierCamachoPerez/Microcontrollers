/*
 * File:   main.c
 * Author: Javier
 *
 * Created on 15 de febrero de 2019, 02:17 PM
 */

#include "xc.h"

#include "config.h"
#define FOSC 79227500
#define FCY (FOSC/2)
#include <libpic30.h>

#include "Init.h"
#include "Start.h"
#include "Controller.h"
#include "Tune.h"
#include "LEDs.h"
#include "Buttons.h"
#include "MPU6050.h"
#include "TB6612FNG.h"


/*Timer1 ISR */
void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void){
 
        PD_Control();
    
    IFS0bits.T1IF = 0; // Clear Timer1 Interrupt Flag

}


int main(void) {
    
   __delay_ms(500);
   OSC_Init();
   __delay_ms(10);
   LEDs_Init();
   Buttons_Init();
   UART_Init();
   QEI_Init();
   PWM_Init();
   TB6612FNG_Init();
   I2C_Init();
   MPU6050_Init();
   TMR1_Init();
  
 
   
   while(1){
     
       if(StartButton==0){
           __delay_ms(500);
           Reset_AngleZ();
           Set_Position();   
       }
       
       
       if(RightButton==0){
           Send();
       }
         
       
   }
       
    return 0;
}
