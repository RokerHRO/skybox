#version 3.7;

#include "defs.inc" // defined by 'make'
#include "scene.inc" // defined by 'make'


#if(CAMERA="ft") // +z
camera
{
	right <-1,0,0>
	up <0,1,0>
	location <0,0,0>
	look_at <0,0,+1>
	angle 90
}
#end

#if(CAMERA="bk") // -z
camera
{
	right <-1,0,0>
	up <0,1,0>
	location <0,0,0>
	look_at <0,0,-1>
	angle 90
}
#end

#if(CAMERA="rt") // +x
camera
{
	right <-1,0,0>
	up <0,1,0>
	location <0,0,0>
	look_at <+1,0,0>
	angle 90
}
#end

#if(CAMERA="lf") // -x
camera
{
	right <-1,0,0>
	up <0,1,0>
	location <0,0,0>
	look_at <-1,0,0>
	angle 90
}
#end

#if(CAMERA="up") // +y
camera
{
	right <-1,0,0>
	up <0,1,0>
	location <0,0,0>
	sky<-1,0,0>
	look_at <0,+1,0>
	angle 90
}
#end

#if(CAMERA="dn") // -y
camera
{
	right <-1,0,0>
	up <0,1,0>
	location <0,0,0>
	sky<+1,0,0>
	look_at <0,-1,0>
	angle 90
}
#end


#if(CAMERA="spherical")  // spherical
camera
{
	spherical
	right <-1,0,0>
	up <0,1,0>
	location <0,0,0>
	look_at <0,0,-1>
	angle 360
}
#end

#if(CAMERA="normal") // +z but with greater distance
camera
{
	right <-1,0,0>
	up <0,1,0>
	location <0,15,-25>
	look_at <0,0,0>
	angle 75
}

plane { y, 0
	pigment { checker color rgbt<0.8, 0.8, 0.8, 0.8> color rgbt<0.9, 0.3, 0.3, 0.8> scale 2}
}

#end
