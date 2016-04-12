//
//  solar_system_gravity.h
//  SolarSystem
//
//  Created by William Yingling on 11/20/13.
//
//

#ifndef SOLAR_SYSTEM_GRAVITY_H
#define SOLAR_SYSTEM_GRAVITY_H
#include"planet.h"

#define M_sun 1.0
#define G 39.4784176043574320  //4*pi*pi


double solar_circular_velocity(struct Planet p);


void solar_gravitational_acceleration(struct Planet *p);

#endif
