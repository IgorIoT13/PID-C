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
        self->prev_err = 0;
        self->integral = 0;
        self->td = 0;

        self->compute = compute;
        self->compute_PWM = compute_PWM;
        self->setTime = setTime;
        self->deletePID_base = deletePID_base;
        return self;
    }   
    return NULL;
}

float scaleToRange(double input, double in_min, double in_max, double out_min, double out_max){
    if (input < in_min) input = in_min;
    if (input > in_max) input = in_max;

    return (input - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void* *setTime(PID_base* self, time td){
    if(self){
        self->td = td;
    }
}

double *compute(PID_base *self, double target, double current){
    if(self && self->td > 0){
        double resP, resI, resD, der, res;
        double err = target - current;


        resP = self->kp * err;

        self->integral += err * (self->td);
        resI =self->ki * self->integral;

        der = (err - self->prev_err)/self->td;
        resD = self->kd * der;

        self->prev_err = err;

        res = resP + resI + resD;
        return res;


    }
    return 0;
}
unsigned char *compute_PWM(PID_base *self, double target, double current);


void *deletePID_base(PID_base* self);