
#include <xc.h>

void OSC_Init(void){
    
    OSCCONbits.NOSC = 0b001;
    CLKDIVbits.DOZE = 0; //FCY/1
    CLKDIVbits.FRCDIV = 0; //FRC dividido entre 1
    PLLFBDbits.PLLDIV = 41; //M=43
    CLKDIVbits.PLLPRE = 0; //N1=2
    CLKDIVbits.PLLPOST = 0; //N2=2
}

void QEI_Init(void){
    
    //QEI1
    TRISCbits.TRISC9=1;
    TRISCbits.TRISC7=1;
    
    RPINR14bits.QEA1R=23; 
    RPINR14bits.QEB1R=25;
  
    QEI1CONbits.QEISIDL=0;
    QEI1CONbits.QEIM=0b111;
    QEI1CONbits.SWPAB=0;
    QEI1CONbits.PCDOUT=0;
    QEI1CONbits.TQGATE=0;
    QEI1CONbits.POSRES=0;
    QEI1CONbits.UPDN_SRC=0;
    
    DFLT1CONbits.QEOUT=0;
    
    MAX1CNT=0xFFFF;
    POS1CNT=0x0000;
    
    //QEI2
    TRISBbits.TRISB10=1;
    TRISCbits.TRISC8=1;
    
    RPINR16bits.QEA2R=24; 
    RPINR16bits.QEB2R=10;
  
    QEI2CONbits.QEISIDL=0;
    QEI2CONbits.QEIM=0b111;
    QEI2CONbits.SWPAB=0;
    QEI2CONbits.PCDOUT=0;
    QEI2CONbits.TQGATE=0;
    QEI2CONbits.POSRES=0;
    QEI2CONbits.UPDN_SRC=0;
    
    DFLT1CONbits.QEOUT=0;
    
    MAX2CNT=0xFFFF;
    POS2CNT=0x0000;
    
}


void UART_Init(void){
    
    TRISBbits.TRISB6=0;//RB6 como salida
    RPOR3bits.RP6R=0b00011;//RP6--->TX
    
    U1MODEbits.STSEL = 0; // 1 Stop bit
    U1MODEbits.PDSEL = 0; // No Parity, 8 data bits
    U1MODEbits.ABAUD = 0; // Auto-Baud Disabled
    U1MODEbits.BRGH = 0; // Low Speed mode
    U1BRG=257;//9600 Baud rate 40MIPS
    
    U1MODEbits.IREN=0;
    U1MODEbits.USIDL=1;
    U1STAbits.UTXINV=0;//Polaridad Idle TX=1
    
    U1MODEbits.UARTEN = 1; // Enable UART
    U1STAbits.UTXEN = 1; // Enable UART TX
    
    //U1MODEbits.UEN=0;//TX y RX habilitado
    //U1MODEbits.URXINV=0;//Polaridad RX=1
   
}

void PWM_Init(void){
    
    //P1TCONbits.PTSIDL = 0; //PWM time base runs in CPU Idle mode
    P1TCONbits.PTOPS = 0b0000; //1:1 postscale
    P1TCONbits.PTCKPS = 0b00; //1:1 prescale
    P1TCONbits.PTMOD = 0b00; //PWM time base operates in a Free-Running mode
    
    P1TPER = 2047;//32766;  //PWM switching frequency is 1.22 kHz
    
    PWM1CON1bits.PMOD1 = 1; //PWM I/O pin pair is in the Independent PWM Output mode
    PWM1CON1bits.PMOD2 = 1; //PWM I/O pin pair is in the Independent PWM Output mode    
    PWM1CON1bits.PMOD3 = 1; //PWM I/O pin pair is in the Independent PWM Output mode 
    
    PWM1CON1bits.PEN1H = 1; //PWM pin is enabled for PWM output
    PWM1CON1bits.PEN1L = 0; //PWMxH pin disabled, I/O pin becomes general purpose I/O
            
    PWM1CON1bits.PEN2H = 1; //PWM pin is enabled for PWM output
    PWM1CON1bits.PEN2L = 0; //PWMxH pin disabled, I/O pin becomes general purpose I/O
            
    PWM1CON1bits.PEN3H = 0; //PWMxH pin disabled, I/O pin becomes general purpose I/O
    PWM1CON1bits.PEN3L = 0; //PWMxH pin disabled, I/O pin becomes general purpose I/O
    
    PWM1CON2bits.IUE = 1; //Updates to the active PxDC registers are immediate
    
    PWM1CON2bits.UDIS = 0;  //Updates from Duty Cycle and Period Buffer registers are enabled
            
    P1OVDCON = 0xFFFF; //PWM I/O pin controlled by PWM Generator
    
    P1DC1=0; //Initialize duty cycle values for PWM1 signal
    P1DC2=0; //Initialize duty cycle values for PWM2 signal
    
    P1TCONbits.PTEN=1; //Enabling PWM Pulse Generation
            
    

}



void TMR1_Init(void){
    
    T1CONbits.TON = 0; // Disable Timer
    T1CONbits.TCS = 0; // Select internal instruction cycle clock
    T1CONbits.TGATE = 0; // Disable Gated Timer mode
    T1CONbits.TCKPS = 0b10; // Select 1:64 Prescaler
    
    TMR1 = 0x00; // Clear timer register
    PR1 = 6189; // Load the period value(10ms)
    
    IPC0bits.T1IP = 0x01; // Set Timer1 Interrupt Priority Level
    IFS0bits.T1IF = 0; // Clear Timer1 Interrupt Flag
    IEC0bits.T1IE = 1; // Enable Timer1 interrupt
    T1CONbits.TON = 1; // Start Timer
    
}

void I2C_Init(void){

    ODCBbits.ODCB8=1; //SCL pin as open-drain
    ODCBbits.ODCB9=1; //SDA pin as open-drain
    
    I2C1CONbits.A10M=0; //I2C1ADD is a 7-bit slave address
    I2C1BRG=0x2C; //Baud Rate = 400kHz

    I2C1CONbits.I2CEN=1; //Enables the I2Cx module and configures the SDAx and SCLx pins as serial port pins
}




