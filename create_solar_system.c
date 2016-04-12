//
//  create_solar_system.c
//  SolarSystem
//
//  Created by William Yingling on 11/20/13.
//
//
#include<stdlib.h>
#include<math.h>
#include"solar_system_gravity.h"
#include"create_solar_system.h"
#include"evolve_solar_system.h"  //contains time step calculator


// create ss

struct Planet *CreateSolarSystem(int n_planets)
{
    int i;
    
    
    double AU_in_km = 1.495979e+8;
    
    double v_c,v_e;  //circular velocity in Au/yr
    //Velocity at perihelion in Au/yr
    
    struct Planet *p = (struct Planet *) malloc(n_planets*sizeof(struct Planet));
    
    for(i=0;i<n_planets;i++)
    {
        
        //set semim a and ecce
        switch(i)
        {
            case 0:  //Mercury
                
                p[i].a = 57909227.0/ AU_in_km;
                
                p[i].e = 0.20563593;
                
                break;
                
            case 1: //Venus
                
                p[i].a = 108209475.0 / AU_in_km;
                
                p[i].e = 0.00677672;
                
                break;
                
            case 2:
                
                p[i].a = 1.0;
                
                p[i].e = 0.01671123;
                
                break;
        } //close switch
        
        p[i].t = 0.0;  // time at zero
        
        p[i].x[0] =p[i].a*(1-p[i].e); //y yes  y position to perihelion
        p[i].x[1] = 0.0;// position to zero
        
        
        v_c = solar_circular_velocity(p[i]);
        
        v_e = v_c*sqrt(1+p[i].e);
        
        
        p[i].v[0] = 0.0;
        p[i].v[1] = v_e;
        
        solar_gravitational_acceleration(&p[i]);
        
        //set timestep
        p[i].dt = calc_dt(p[i]);
        
    } //end for loop
    //return planets
    
    return p;
}// end struct