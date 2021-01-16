
#include <xc.h>

#define PWMA P1DC1
#define PWMB P1DC2
#define STBY LATAbits.LATA7
#define AIN1 LATAbits.LATA10
#define AIN2 LATBbits.LATB13
#define BIN1 LATAbits.LATA0
#define BIN2 LATAbits.LATA1

void TB6612FNG_Init(void);
void Set_Motors(int, int);