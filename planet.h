//
//  planet.h
//  SolarSystem
//
//  Created by William Yingling on 11/20/13.
//
//

#ifndef PLANET_H
#define PLANET_H


struct Planet{
    
    double x[2];  // x and y posit in AU
    double v[2];  //velocity in AU/yr
    double a_g[2]; //  accel in au/yr/yr
    double t;
    double dt;
    double e;
    double a;  //time, timestep in year in terms of the year not day,  eccent,semiaxis major
    int istep;  // steps the planet has taken
};

#endif