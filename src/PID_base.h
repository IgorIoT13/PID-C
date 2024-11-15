#ifndef PID_BASE
#define PID_BASE

#include <stdio.h>

typedef unsigned int time;

typedef struct PID_base{
    float kp;       
    float ki;       
    float kd;

    double prev_err;
    double integral;

    time td;


    void* (*setTime)(PID_base* self, time td);

    double (*compute)(PID_base *self, double target, double current);
    unsigned char (*compute_PWM)(PID_base *self, double target, double current);



    void (*deletePID_base)(PID_base* self);

}PID_base;


PID_base* createPID_base(float kp, float ki, float kd);
float scaleToRange(double input, double in_min, double in_max, double out_min, double out_max);


void* *setTime(PID_base* self, time td);

double *compute(PID_base *self, double target, double current);
unsigned char *compute_PWM(PID_base *self, double target, double current);


void *deletePID_base(PID_base* self);


#endif