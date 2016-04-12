//
//  leapfrog.c
//  SolarSystem
//
//  Created by William Yingling on 11/20/13.
//
//


#include"leapfrog.h"

double x_first_step(double x_i, double v_i, double a_i, double Delta_t)
{
    return x_i + 0.5*v_i*Delta_t + 0.25*a_i*Delta_t*Delta_t;
}


double v_full_step(double v_i, double a_ip12, double Delta_t)
{
    return v_i + a_ip12*Delta_t;
}


double x_full_step(double x_ip12, double v_ip1, double Delta_t)
{
    return x_ip12 + v_ip1*Delta_t;
}
