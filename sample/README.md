sample
=======

This demonstrates the bare minimum F90 application that uses the idagmc
stripped down interface.

You will need to set MOAB_BASE_DIR to the location of your MOAB install, and
then go to the `sample` directory an type `make`.

This will make an program called `sample_app`

Test Geometries
---------------

The `sample_app` expects to read a file named `test.sat`.  There are 2 files
included in this directory that ca be used for this.  The simplest way is to
make a symbolic link to the file of interest (e.g. `ln -s test2.sat test.sat`)

`test1.sat`: this geometry has 2 cubes of side length 10, centered at 0,0,0,
and 100,0,0.

`test2.sat`: this geometry has 2 nested spheres of radii 25 and 15, both
centered at the origin.  NOTE: inner sphere has NOT been removed from he outer
sphere!  The origin is "inside" both spheres.
