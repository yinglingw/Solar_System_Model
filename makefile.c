EXEC   = astrolab                      #name of executable

OPTIMIZE =  -O2			         #compilation optimization

OBJS   = main.o evolve_solar_system.o create_solar_system.o solar_system_gravity.o save_solar_system.o leapfrog.o #object files to create

CC     = gcc                             #CC is the environment variable for the C compiler

INCL   = evolve_solar_system.h create_solar_system.h solar_system_gravity.h save_solar_system.h leapfrog.h planet.h        #local header files to include

LIBS   = -lm                              #libraries to add


#the following lines build an executable from the object files
$(EXEC): $(OBJS)
$(CC) $(OBJS) $(LIBS) -o $(EXEC)

$(OBJS): $(INCL)

#the following lines enable us to easily remove object files
.PHONY : clean

clean:
rm -f $(OBJS) $(EXEC)