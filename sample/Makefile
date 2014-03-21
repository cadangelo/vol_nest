include ${MOAB_BASE_DIR}/lib/moab.make

CPPFLAGS = $(MOAB_INCLUDES)
CXXFLAGS = $(MOAB_CXXFLAGS)
LDFLAGS = $(MOAB_LDFLAGS)


sample_app: sample_app.o ../idagmc.o
	gfortran -g -o sample_app sample_app.o ../idagmc.o -ldagmc ${MOAB_LIBS_LINK}  -lstdc++

clean: 
	rm -f *.o sample_app

sample_app.o: sample_app.F90
	gfortran -g -c sample_app.F90
