include ${MOAB_BASE_DIR}/lib/moab.make

CPPFLAGS = $(MOAB_INCLUDES)
CXXFLAGS = $(MOAB_CXXFLAGS)
LDFLAGS = $(MOAB_LDFLAGS)


clean: 
	rm *.o test_app

test_app.o: test_app.F90
	gfortran -g -c test_app.F90

test_app: test_app.o idagmc.o
	gfortran -g -o test_app test_app.o idagmc.o -ldagmc ${MOAB_LIBS_LINK}  -lstdc++
