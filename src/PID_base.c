#include "PID_base.h"

PID_base* createPID_base(float kp, float ki, float kd){
    PID_base* self = (PID_base*)malloc(sizeof(PID_base));

    for(int i = 0; i < 10 && !self ; i++){
        PID_base* self = (PID_base*)malloc(sizeof(PID_base));
    }

    if(!self){
        return NULL;
    }else{
        self->kp = kp;
        self->ki = ki;
        self->kd = kd;
        self->td = 0;

        self->compute = compute;
        self->compute_PWM = compute_PWM;
        self->setTime = setTime;
        self->deletePID_base = deletePID_base;
        return self;
    }   
    return NULL;
}

float scaleToRange(double input, double in_min, double in_max, double out_min, double out_max);


void* *setTime(PID_base* self, time td);

float *compute(PID_base *self, double target, double current);
unsigned char *compute_PWM(PID_base *self, double target, double current);


void *deletePID_base(PID_base* self);