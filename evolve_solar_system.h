//
//  evolve_solar_system.h
//  SolarSystem
//
//  Created by William Yingling on 11/20/13.
//
//

#ifndef EVOLVE_SOLAR_SYSTEM_H
#define EVOLVE_SOLAR_SYSTEM_H
#include"planet.h"

#define ETA_TIME_STEP 0.0004


//driver routine for evolving SS
void EvolveSolarSystem(struct Planet *p, int n_planets, double t_max);
//passsing array of planets


//determine the timestepp
double calc_dt(struct Planet p);


#endif
