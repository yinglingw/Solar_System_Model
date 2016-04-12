//
//  save_solar_system.c
//  SolarSystem
//
//  Created by William Yingling on 11/20/13.
//
//

#include<stdlib.h>
#include"save_solar_system.h"


//open simulation output file
FILE *OpenSolarSystemFile(void)
{
    FILE *fp;
    
    char fname[200];
    //file name
    
    //define file name
    sprintf(fname, "solar_system.dat");
    
    if(!(fp=fopen(fname,"w")))
    {
        printf("Error opening %s.\n", fname);
        fflush(stdout);
        exit(-1);
    }
    
    return fp;
}


//save simulation
void SaveSolarSystem(FILE *fp, struct Planet *p, int n_planets,double t, double dt, int istep)
{
    
    int k;
    
    if(istep==0)
    {
        //number of planets
        fwrite(&n_planets,1,sizeof(int),fp);
        
        for(k=0;k<n_planets;k++)
            fwrite(&p[k].a,1,sizeof(double),fp);
        
        for(k=0;k<n_planets;k++)
            fwrite(&p[k].a,1,sizeof(double),fp); // check this
        
        //output step info
        fwrite(&istep,1,sizeof(int),fp);
        fwrite(&t,1,sizeof(double),fp);
        fwrite(&dt,1,sizeof(double),fp);
        
        for(k=0;k<n_planets;k++)
            OutputDriftPlanets(fp,p[k]);
        
        return;
    }
}


void OutputDriftPlanets(FILE *fp, struct Planet p)
{
    
    int k;
    int ndim = 2;
    double v_drift[2];
    
    fwrite(&p.istep,1,sizeof(int),fp);
    fwrite(&p.t,1,sizeof(double),fp);
    fwrite(&p.dt,1,sizeof(double),fp);
    
    fwrite(&p.x[0],2,sizeof(double),fp);
    
    for(k=0;k<ndim;k++)
        v_drift[k] = p.v[k] + 0.5*p.a_g[k]*p.dt;
    
    fwrite(&v_drift[0],2,sizeof(double),fp);
    
    fwrite(&p.a_g[0],2,sizeof(double),fp);
    
    return;
}