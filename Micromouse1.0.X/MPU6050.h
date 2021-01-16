
#include <xc.h>
#include "Tune.h"

void MPU6050_Init(void);
float Get_VelocityZ(void);
void StabilizeGyro(void);
float Get_AngleZ(void);
void Reset_AngleZ(void);