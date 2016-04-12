//
//  evolve_solar_system.c
//  SolarSystem
//
//  Created by William Yingling on 11/20/13.
//
//

#include <stdio.h>
#include<math.h>
#include"evolve_solar_system.h"
#include"leapfrog.h"
#include"save_solar_system.h"
#include"solar_system_gravity.h"

void EvolveSolarSystem(struct Planet *p, int n_planets, double t_max)
{
    int i,k;
    FILE *fp; //file pointer to our save file
    int ndim = 2;  //# of spatial dimensions
    int istep = 0; //number of timesteps
    double t =0;  //current gloabal time in yearts
    double dt = 0.5/365.25;
    
    
    //open file in our data
    fp = OpenSolarSystemFile();
    
    
    // output initial state
    SaveSolarSystem(fp,p,n_planets,t,dt,istep);
    
    //loop for global time
    while(t<t_max)
    {
        //check timestep if exceeds max time
        if(t+dt>t_max)
            dt = t_max - t; //limit timestep to global max time
        
        //evolve each planet
        for(i=0;i<n_planets;i++)
        {
            //evolve system to time t+dt
            do{
                if(p[i].istep==0)  //special first case first step
                {
                    for(k=0;k<ndim;k++)
                        p[i].x[k] = x_first_step(p[i].x[k], p[i].v[k], p[i].a_g[k], p[i].dt);
                    
                    //updat5e accel
                    solar_gravitational_acceleration(&p[i]);
                    
                    //update time by 1/2dt
                    p[i].t += 0.5*p[i].dt;
                    
                    //update timestep
                    p[i].dt = calc_dt(p[i]);
                }
                //check to see is planets timestep exceeds global timestep
                
                
                if(p[i].t+p[i].dt>t+dt) //no curcly braket is just that statement which is executed
                    p[i].dt = t+dt-p[i].t;
                
                //evolve velocity
                for(k=0;k<ndim;k++)
                    p[i].v[k] = v_full_step(p[i].v[k], p[i].a_g[k], p[i].dt);
                
                //evolve position
                for(k=0;k<ndim;k++)
                    p[i].x[k] = x_full_step(p[i].x[k], p[i].v[k], p[i].dt);
                
                solar_gravitational_acceleration(&p[i]);
                
                p[i].t += p[i].dt;
                
                p[i].dt = calc_dt(p[i]);
                
                p[i].istep++;
                
            }while(p[i].t<t+dt);
            
        }// end loop over planets
        
        //update time
        t += dt;
        
        //update global step number
        istep++;
        
        //output current state
        SaveSolarSystem(fp,p,n_planets,t,dt,istep);
        
    } //end while loop over the global time
    
    printf("Total number of steps = %d\n", istep);
    
    fclose(fp); //close output file
    
    return;
}


//determine timestep

double calc_dt(struct Planet p)
{
    double eta = ETA_TIME_STEP;
    double v = sqrt(p.v[0]*p.v[0] + p.v[1]*p.v[1]);
    double a = sqrt(p.a_g[0]*p.a_g[0] + p.a_g[1]*p.a_g[1]);
    double dt = (double)(eta*fmin(1./fabs(v),1./sqrt(fabs(a))));
    
    return dt; //return timestep in years
}