program test_app


implicit none
integer:: result, vol_idx
character(12):: filename
real*8:: x, y, z


filename = "test.sat"

call dagmcinit(filename,8)

x=0
y=0
z=0
vol_idx=1 

call dagmcchkcel(x,y,z,vol_idx,result)
if (result == 0) then
   write(*,*) "point (",x,",",y,",",z,") is inside volume ",vol_idx
else
   write(*,*) "point (",x,",",y,",",z,") is outside volume ",vol_idx
endif

x=100
y=0
z=0
vol_idx=1 

call dagmcchkcel(x,y,z,vol_idx,result)
if (result == 0) then
   write(*,*) "point (",x,",",y,",",z,") is inside volume ",vol_idx
else
   write(*,*) "point (",x,",",y,",",z,") is outside volume ",vol_idx
endif

x=100
y=0
z=0
vol_idx=2 

call dagmcchkcel(x,y,z,vol_idx,result)
if (result == 0) then
   write(*,*) "point (",x,",",y,",",z,") is inside volume ",vol_idx
else
   write(*,*) "point (",x,",",y,",",z,") is outside volume ",vol_idx
endif

x=200
y=0
z=0
vol_idx=2 

call dagmcchkcel(x,y,z,vol_idx,result)
if (result == 0) then
   write(*,*) "point (",x,",",y,",",z,") is inside volume ",vol_idx
else
   write(*,*) "point (",x,",",y,",",z,") is outside volume ",vol_idx
endif


end
