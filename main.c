//
//  main.c
//  SolarSystem
//
//  Created by William Yingling on 11/20/13.
//
//

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"planet.h"
#include"create_solar_system.h"
#include"evolve_solar_system.h"

int main(int argc, char **argv)
{
    
    int n_planets = 3;  //num ber of planets in our model
    double t_max = 1; //max time in years
    struct Planet *p; ////solar system planets
    
    
    //create our solar system and initial conditions
    p = CreateSolarSystem(n_planets);
    
    
    //evolve our ss from time t = 0 to t = t_max
    EvolveSolarSystem(p,n_planets,t_max);
    
    free(p);
    
    return 0;
}