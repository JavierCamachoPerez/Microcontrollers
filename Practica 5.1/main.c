#include <xc.h>
#include "config.h"
#include <stdio.h>
#define _XTAL_FREQ 32000000
#include "flex_lcd.h"


void main(void) {
    int seg,seg1,min,min1,hora,hora1,dia,mes,anio;
    char buffer1[16];
    //Oscilador
    OSCCONbits.IRCF=0b1110;
    OSCCONbits.SCS=0;
    //Puertos
    ANSELA=0;
    SSPCON1bits.SSPEN=1;    
    SSPCON1bits.SSPM3=1 ;
    SSPCON1bits.SSPM2=0;
    SSPCON1bits.SSPM1=0;
    SSPCON1bits.SSPM0=0;
    SSPADD=19;      
    
    Lcd_Init();     //inicializamos el lcd
    Lcd_Cmd(LCD_CLEAR);		//limpiamos lcd
    Lcd_Cmd(LCD_CURSOR_OFF);	//apagamos el cursor
    __delay_ms(1000);
    Lcd_Out(2, 1, "Mecatronica");
    SEN=1;
        while(SEN);
        SSPBUF=0b11010000;
        while(BF);
        while(R_nW);
        SSPBUF=0;
        while(BF);
        while(R_nW);
        SSPBUF=0;//Seg
        while(BF);
        while(R_nW);
        SSPBUF=0b00110001;//min
        while(BF);
        while(R_nW);
        SSPBUF=0b00010110;//hor
        while(BF);
        while(R_nW);
        SSPBUF=0b00000101;//día
        while(BF);
        while(R_nW);
        SSPBUF=0b00001000;//fecha
        while(BF);
        while(R_nW);
        SSPBUF=0b00010001;//mes
        while(BF);
        while(R_nW);
        SSPBUF=0b00011000;//año
        while(BF);
        while(R_nW);
        SSPBUF=0b00010000;
        while(BF);
        while(R_nW);
        PEN=1;
        while(PEN);
        
        
    while(1){
        SSPCON2bits.SEN=1;      //Se genera la señal de Start
        while(SEN);
        SSPBUF=0b11010000;
        while(BF);          //espera hasta que se envie el dato
        while(R_nW);        //Espera hasta que llegue el 9o clock
        SSPBUF=0;           //Se escribe el siguiente dato
        while(BF);          //espera hasta que se envie el dato
        while(R_nW);        //Espera hasta que llegue el 9o clock
        RSEN=1;             //restart
        while(RSEN);
        SSPBUF=0b11010001;
        while(BF);
        while(R_nW)
        RCEN=1;         //habilita la recepción
        while(BF==0);
        seg=SSPBUF;           //leer dato de SSPBUF
        ACKDT=0;
        ACKEN=1;            //Genera ack
        while(ACKEN);
        RCEN=1;         //habilita la recepción
        while(BF==0);
        min=SSPBUF;           //leer dato de SSPBUF
        ACKDT=0;
        ACKEN=1;            //Genera ack
        while(ACKEN);
        RCEN=1;         //habilita la recepción
        while(BF==0);
        hora=SSPBUF;           //leer dato de SSPBUF
        ACKDT=1;
        ACKEN=1;            //Genera Noack
        while(ACKEN);
        PEN=1;
        while(PEN);
        seg1=((0b01110000 & seg)>>4)*10+(0b00001111 & seg);
        min1=((0b01110000 & min)>>4)*10+(0b00001111 & min);
        hora1=((0b01110000 & hora)>>4)*10+(0b00001111 & hora);
        sprintf(buffer1,"   %d:%d:%d",hora1,min1,seg1);
        Lcd_Out2(1, 1, buffer1);
        __delay_ms(900);
    }
    return;
}
