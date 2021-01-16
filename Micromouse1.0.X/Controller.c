
#include "xc.h"
#include "Controller.h"

//******************************************************************************


int discard=0;

int positionA=0;
int positionB=0;

float positionX=0.0;
float positionW=0.0;

float targetPositionX=0.0;
float targetPositionW=0.0;

float errorX=0.0;
float errorW=0.0;

float oldErrorX=0.0;
float oldErrorW=0.0;
float oldPositionW=0.0;

float kpX=11.0;
float kdX=0.06;

float kpW=6.0;
float kdW=0.07;

int Ux=0;
int Uw=0;



void Set_Position(void){

    targetPositionW=45.0;
}

void PD_Control(){
    
    positionA = POS1CNT;
	positionB = POS2CNT;
  
    positionX = ((positionA + positionB)/2)*0.2; //mm
    positionW = Get_AngleZ(); //°
  
        
    errorX = targetPositionX - positionX;
    errorW = targetPositionW - positionW;
    
    Ux = kpX*errorX + kdX*(errorX-oldErrorX);
    Uw = kpW*errorW + kdW*(errorW-oldErrorW);
    
    
    Set_Motors(Ux-Uw, Ux+Uw);
    
    oldErrorX = errorX;
    oldErrorW = errorW;
 
}


