#include <xc.h>
#define _XTAL_FREQ 32000000
#include"Config.h"
int x;
int r1=1;



void main(void) {
   // OSCFRQbits.HFFRQ = 0b110; //HSINTOSC
    
    
    PORTA=0;
    PORTB=0;
    PORTC=0;
    ANSELA=0;
    ANSELB=0;
    ANSELC=0;
    TRISA=0b00000000;
    TRISB=0b00010101;
    TRISC=0b00110000;
    RC1PPS = 0x09; //CCP ---> RB0
    RC2PPS = 0x0A; //CCP2 ---> RB2
    //TIMER2 ---> CCP1
    PR2 = 255; //SEÑAL PWM - 1.95 kHz
    T2CLKCONbits.CS = 0b0001; //CS FOSC/4
    T2CONbits.CKPS = 0b100; //PRESCALER 1:16
    T2CONbits.OUTPS = 0; //POSTCALER 1:1
    T2CONbits.ON = 1; //ENCENDER TIMER2
    //CCP1
    CCP1CONbits.EN = 1; //ENCIENDE CCP1
    CCP1CONbits.FMT = 0; //JUSTIFICACIÓN DERECHA
    CCP1CONbits.MODE = 0b1111; //MODO PWM
    CCPTMRS0bits.C1TSEL = 0b01; //TIMER2 ---> CCP1
    //CCP2
    CCP2CONbits.CCP2EN = 1; //ENCIENDE CCP1
    CCP2CONbits.FMT = 0; //JUSTIFICACIÓN DERECHA
    CCP2CONbits.MODE = 0b1111; //MODO PWM
    CCPTMRS0bits.C2TSEL = 1; //  //TIMER2 ---> 
    
    
    while (1) {
        
        
        LATAbits.LATA7 = 1;
        
        if(r1==1){
            //adelante
            LATAbits.LATA6 = 0;
            LATCbits.LATC0 = 1;
            LATAbits.LATA1 = 1;
            LATAbits.LATA2 = 0;
        
            //Esperar sensor
            while(PORTBbits.RB4 ==1);
            
            //Retroceder
            LATAbits.LATA6 = 1;
            LATCbits.LATC0 = 0;
            LATAbits.LATA1 = 0;
            LATAbits.LATA2 = 1;
            
            __delay_ms(100);
            
            //Girar derecha
            LATAbits.LATA6 = 1;
            LATCbits.LATC0 = 0;
            LATAbits.LATA1 = 1;
            LATAbits.LATA2 = 0;
            
           // r1=0;
            }
        
        /*
            if(PORTBbits.RB0==1 && PORTBbits.RB2==0){
            
            }
            
            if(PORTBbits.RB0==0 && PORTBbits.RB2==1){
            
            }
            
            if(PORTBbits.RB0==1 && PORTBbits.RB2==1){
            
            }
          
            
            */
            
            
      
       
        
        
    }
    return;
}