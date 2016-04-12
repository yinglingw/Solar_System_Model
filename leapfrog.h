//
//  leapfrog.h
//  SolarSystem
//
//  Created by William Yingling on 11/20/13.
//
//

#ifndef LEAPFROG_H
#define LEAPFROG_H


//the steps of leapfrog integration

double x_first_step(double x_i, double v_i, double a_i, double Delta_t);

double v_full_step(double v_i, double a_ip12, double Delta_t);

double x_full_step(double x_ip12, double v_ip1, double Delta_t);

#endif
