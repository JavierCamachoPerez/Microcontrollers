
#include "xc.h"
#include "Controller.h"

//******************************************************************************
float curSpeedX = 0;
float curSpeedW = 0;
int targetSpeedX = 0;
int targetSpeedW = 0;
int encoderFeedbackX = 0;
int encoderFeedbackW = 0;
float pidInputX = 0;
float pidInputW = 0;
float posErrorX = 0;
float posErrorW = 0;
float oldPosErrorX = 0;
float oldPosErrorW = 0;
int posPwmX = 0;
int posPwmW = 0;
float kpX = 2, kdX = 4;
float kpW = 1, kdW = 12;//used in straight
float kpW1 = 1;//used for T1 and T3 in curve turn
float kdW1 = 26;
float kpW2 = 1;//used for T2 in curve turn
float kdW2 = 36;
float accX = 600;//6m/s/s  
float decX = 600; 
float accW = 1; //cm/s^2
float decW = 1;


/*
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

*/


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


