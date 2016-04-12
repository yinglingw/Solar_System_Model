//
//  save_solar_system.h
//  SolarSystem
//
//  Created by William Yingling on 11/20/13.
//
//

#ifndef SAVE_SOLAR_SYSTEM_H
#define SAVE_SOLAR_SYSTEM_H
#include<stdio.h>
#include"planet.h"

FILE *OpenSolarSystemFile(void);

void SaveSolarSystem(FILE *fp,struct Planet *p, int n_planets,double t, double dt, int istep);

void OutputDriftPlanets(FILE *fp, struct Planet p);

#endif
