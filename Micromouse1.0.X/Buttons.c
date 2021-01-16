
#include "xc.h"
#include "Buttons.h"


void Buttons_Init(void){
    
    TRISAbits.TRISA9=1;
    PORTAbits.RA9=0;
    
    TRISBbits.TRISB4=1;
    PORTBbits.RB4=0;
    
    TRISCbits.TRISC3=1;
    PORTCbits.RC3=0;
    
    
}

