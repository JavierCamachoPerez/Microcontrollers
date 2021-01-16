
#include "xc.h"
#include "TB6612FNG.h"

int pwma=0;
int pwmb=0;

void TB6612FNG_Init(void){

    TRISAbits.TRISA7=0; //STBY
    PORTAbits.RA7=0;
    
    TRISAbits.TRISA10=0; //AIN1
    PORTAbits.RA10=0;
    
    TRISBbits.TRISB13=0; //AIN2
    PORTBbits.RB13=0;
    
    TRISAbits.TRISA0=0; //BIN1
    PORTAbits.RA0=0;
    AD1PCFGLbits.PCFG0=1;
    
    TRISAbits.TRISA1=0; //BIN2
    PORTAbits.RA0=0;
    AD1PCFGLbits.PCFG1=1;

    /*
    AIN1=0;
    AIN2=1;
    PWMA=200;
    BIN1=0;
    BIN2=1;
    PWMB=200;
    STBY=1;
    */
    
}



void Set_Motors(int a, int b){
    
    pwma = a;
    pwmb = b;
    
    
    if(pwma==0){
        AIN1=0;
        AIN2=0;
        PWMA=0;
        STBY=0;
    }else if(pwma>0){
        AIN1=0;
        AIN2=1;
        PWMA=pwma+230;
        STBY=1;        
    }else if(pwma<0){
        AIN1=1;
        AIN2=0;
        PWMA=230-pwma;
        STBY=1;        
    }
    
    
    if(pwmb==0){
        BIN1=0;
        BIN2=0;
        PWMB=0;
        STBY=0;
    }else if(pwmb>0){
        BIN1=0;
        BIN2=1;
        PWMB=pwmb+230;
        STBY=1;        
    }else if(pwmb<0){
        BIN1=1;
        BIN2=0;
        PWMB=230-pwmb;
        STBY=1;        
    }
    

}