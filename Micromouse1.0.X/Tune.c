
#include "xc.h"
#include "Tune.h"
#include "TB6612FNG.h"
int x=0;
int i=0;
int j=0;

int pos=200; //Invesigar por que no se puede asignar en el vector
double V[250];

bool send = false;

int tam=0;
char cadena[20];

void FillVector(float sW){
    
    V[x] = sW;
    x++;
    
    if(x==250){
      T1CONbits.TON = 0; // Stop Timer1
      Set_Motors(0,0);
      LED_R=1;
    } 
}

void Send(void){
    
    send = true;
    LED_B=1;
       
    while(send){
        for(j=0; j<250; j++){
            tam = sprintf(cadena,"%f,\r\n",V[j]);
            for(i=0; i<=tam; i++){       
                U1TXREG = cadena[i];
                while(!U1STAbits.TRMT);
            } 
        }
        send = false;
        LED_B=0;
    }

}

void Transmit(float q){
    
    tam = sprintf(cadena,"Pos: %f\r\n", q);
    
    for(i=0; i<=tam; i++){       
        U1TXREG = cadena[i];
        while(!U1STAbits.TRMT);
    }
   
}

