
#include "xc.h"
#include "MPU6050.h"

int VzH=0;
int VzL=0; 
int Vz=0;
float Stabilize=0.0;
float AngleZ=0.0; ////Pendiente para nuevo control 

void MPU6050_Init(void){
    
    //*******************************************************
    I2C1CONbits.SEN=1; //Initiate Start condition
    while(I2C1CONbits.SEN); //Wait for completion of Start
    
    I2C1TRN = 0xD0; 
    while(I2C1STATbits.TBF); 
    while(I2C1STATbits.TRSTAT);   
    while(I2C1STATbits.ACKSTAT);
    
    I2C1TRN = 0x6B; 
    while(I2C1STATbits.TBF); 
    while(I2C1STATbits.TRSTAT);   
    while(I2C1STATbits.ACKSTAT);
    
    I2C1TRN = 0x03; 
    while(I2C1STATbits.TBF); 
    while(I2C1STATbits.TRSTAT);   
    while(I2C1STATbits.ACKSTAT);
    
    //**************************************************
    I2C1CONbits.PEN=1; //Initiate Stop condition 
    while(I2C1CONbits.PEN); ////Wait for completion of Stop
    
    
    //*******************************************************
    I2C1CONbits.SEN=1; //Initiate Start condition
    while(I2C1CONbits.SEN); //Wait for completion of Start
    
    I2C1TRN = 0xD0; 
    while(I2C1STATbits.TBF); 
    while(I2C1STATbits.TRSTAT);   
    while(I2C1STATbits.ACKSTAT);
    
    I2C1TRN = 0x19; 
    while(I2C1STATbits.TBF); 
    while(I2C1STATbits.TRSTAT);   
    while(I2C1STATbits.ACKSTAT);
    
    I2C1TRN = 39; 
    while(I2C1STATbits.TBF); 
    while(I2C1STATbits.TRSTAT);   
    while(I2C1STATbits.ACKSTAT);
    
    //**************************************************
    I2C1CONbits.PEN=1; //Initiate Stop condition 
    while(I2C1CONbits.PEN); ////Wait for completion of Stop
    
    
    //*******************************************************
    I2C1CONbits.SEN=1; //Initiate Start condition
    while(I2C1CONbits.SEN); //Wait for completion of Start
    
    I2C1TRN = 0xD0; 
    while(I2C1STATbits.TBF); 
    while(I2C1STATbits.TRSTAT);   
    while(I2C1STATbits.ACKSTAT);
    
    I2C1TRN = 0x1A; 
    while(I2C1STATbits.TBF); 
    while(I2C1STATbits.TRSTAT);   
    while(I2C1STATbits.ACKSTAT);
    
    I2C1TRN = 0x00; 
    while(I2C1STATbits.TBF); 
    while(I2C1STATbits.TRSTAT);   
    while(I2C1STATbits.ACKSTAT);
    
    //**************************************************
    I2C1CONbits.PEN=1; //Initiate Stop condition 
    while(I2C1CONbits.PEN); ////Wait for completion of Stop
    
        //*******************************************************
    I2C1CONbits.SEN=1; //Initiate Start condition
    while(I2C1CONbits.SEN); //Wait for completion of Start
    
    I2C1TRN = 0xD0; 
    while(I2C1STATbits.TBF); 
    while(I2C1STATbits.TRSTAT);   
    while(I2C1STATbits.ACKSTAT);
    
    I2C1TRN = 0x1B; 
    while(I2C1STATbits.TBF); 
    while(I2C1STATbits.TRSTAT);   
    while(I2C1STATbits.ACKSTAT);
    
    I2C1TRN = 0x00; 
    while(I2C1STATbits.TBF); 
    while(I2C1STATbits.TRSTAT);   
    while(I2C1STATbits.ACKSTAT);
    
    //**************************************************
    I2C1CONbits.PEN=1; //Initiate Stop condition 
    while(I2C1CONbits.PEN); ////Wait for completion of Stop
    
}

float Get_VelocityZ(void){

    I2C1CONbits.SEN=1; //Initiate Start condition
    while(I2C1CONbits.SEN); //Wait for completion of Start
    
    I2C1TRN = 0xD0; 
    while(I2C1STATbits.TBF); 
    while(I2C1STATbits.TRSTAT);   
    while(I2C1STATbits.ACKSTAT);
        
    I2C1TRN = 0x47;   //GYRO_ZOUT_H
    while(I2C1STATbits.TBF); 
    while(I2C1STATbits.TRSTAT);   
    while(I2C1STATbits.ACKSTAT);
        
    I2C1CONbits.RSEN=1; //Initiate Re Start condition
    while( I2C1CONbits.RSEN); //Wait for completion of Start

    I2C1TRN = 0xD1; 
    while(I2C1STATbits.TBF); 
    while(I2C1STATbits.TRSTAT);   
    while(I2C1STATbits.ACKSTAT);
        
    I2C1CONbits.RCEN=1;//Habilitamos recepción
    while(!I2C1STATbits.RBF);//Esperamos a que se llene el dato
    VzH = I2C1RCV;
    I2C1CONbits.ACKDT=0; //Send ACK
    I2C1CONbits.ACKEN=1;//Initiate Acknowledge
    while(I2C1CONbits.ACKEN);//Esperamos a que se mande el ACK
        
    I2C1CONbits.RCEN=1;//Habilitamos recepción
    while(!I2C1STATbits.RBF);//Esperamos a que se llene el dato
    VzL = I2C1RCV;
    I2C1CONbits.ACKDT=1; //Send NAK
    I2C1CONbits.ACKEN=1;//Initiate Acknowledge
    while(I2C1CONbits.ACKEN);//Esperamos a que se mande el NACK
        
    I2C1CONbits.PEN=1; //Initiate Stop condition 
    while(I2C1CONbits.PEN); ////Wait for completion of Stop
        
        
    Vz = (VzH << 8) | (VzL);      
       
    return ((Vz/131.0) + 0.2);

}

void StabilizeGyro(void){
    
    AngleZ = Get_VelocityZ();
}

float Get_AngleZ(void){

    AngleZ += (Get_VelocityZ())/100;

    //FillVector(AngleZ);
    return(AngleZ);     
}

void Reset_AngleZ(void){

    AngleZ = 0;
      
}