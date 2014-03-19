#include "mcnp_funcs.h"

#include "MBInterface.hpp"
#include "MBCartVect.hpp"

#include "DagMC.hpp"
using moab::DagMC;

#include <limits>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// globals

#define DAG DagMC::instance()

void dagmcinit_(char *cfile, int *clen)
{
 
  MBErrorCode rval;

  // terminate all filenames with null char
  cfile[*clen] = ftol[*ftlen] = '\0';

  // read geometry
  rval = DAG->load_file(cfile);

  if (MB_SUCCESS != rval) {
    std::cerr << "DAGMC failed to read input file: " << cfile << std::endl;
    exit(EXIT_FAILURE);
  }

  // initialize geometry
  rval = DAG->init_OBBTree();
  if (MB_SUCCESS != rval) {
    std::cerr << "DAGMC failed to initialize geometry and create OBB tree" <<  std::endl;
    exit(EXIT_FAILURE);
  }


}


void dagmcchkcel_(double *xxx,double *yyy,double *zzz, int *vol, int *result)
{

  int inside;
  MBEntityHandle vol = DAG->entity_by_index( 3, *i1 );
  double xyz[3] = {*xxx, *yyy, *zzz};
  double uvw[3] = {0,0,0};
  MBErrorCode rval = DAG->point_in_volume( vol, xyz, inside, uvw );

  if (MB_SUCCESS != rval) {
    std::cerr << "DAGMC: failed in point_in_volume" <<  std::endl;
    exit(EXIT_FAILURE);
  }

  if (MB_SUCCESS != rval) *j = -2;
  else
    switch (inside)
      {
      case 1: 
        *j = 0; // inside==  1 -> inside volume -> j=0
        break;
      case 0:
        *j = 1; // outside== 0  -> outside volume -> j=1
        break;
      case -1:
        *j = 1; // onboundary== -1 -> on boundary -> j=1 (assume leaving volume)
        break;
      default:
        std::cerr << "Impossible result in dagmcchkcel" << std::endl;
        exit(EXIT_FAILURE);
      }
}

