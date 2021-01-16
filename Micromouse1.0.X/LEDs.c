
#include "xc.h"
#include "LEDs.h"

void LEDs_Init(void){
    
    TRISCbits.TRISC4 = 0;
    PORTCbits.RC4 = 0;
    
    TRISCbits.TRISC5 = 0;
    PORTCbits.RC5 = 0;
    
    TRISBbits.TRISB5 = 0;
    PORTBbits.RB5 = 0;
    
}

