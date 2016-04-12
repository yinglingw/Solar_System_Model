//
//  solar_system_gravity.c
//  SolarSystem
//
//  Created by William Yingling on 11/20/13.
//
//

#include<math.h>
#include"solar_system_gravity.h"

double solar_circular_velocity(struct Planet p)
{
    
    //radius in au
    double r = sqrt(p.x[0]*p.x[0] + p.x[1]*p.x[1]);
    
    
    return sqrt(G*M_sun/r);
}

void solar_gravitational_acceleration(struct Planet *p)
{
    //we use -> because this is a pointer within a structure
    //for velocity we simply use a "."
    //radius in AU
    double r = sqrt(p->x[0]*p->x[0] + p->x[1]*p->x[1]);
    //pointing with arrows
    
    double a_grav = -1.0*G*M_sun/(r*r);
    
    double theta;
    
    if(p->x[0]==0.0)
    {
        if(p->x[1]>0)
        {
            theta = 0.5*M_PI;
        }else{
            theta = 1.5*M_PI;
        }
    }else{
        theta = atan2(p ->x[1],p->x[0]);
    }
    
    p->a_g[0] = a_grav*cos(theta);
    p->a_g[1] = a_grav*sin(theta);
    
    return;
    
}
