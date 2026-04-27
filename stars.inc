#version 3.7;

#declare S=seed(45701);

#declare I=0;
#while(I<33333)

#declare X=0;
#declare Y=0;
#declare Z=0;

#while ( (X*X+Y*Y+Z*Z > 1) | (X*X+Y*Y+Z*Z<0.5) )
#declare X=2*rand(S)-1;
#declare Y=2*rand(S)-1;
#declare Z=2*rand(S)-1;
#end

#declare PSI=atan2(X,Y)*180/pi;
#declare THETA=acos(Z/ sqrt(X*X + Y*Y + Z*Z)) * 180/pi;

#declare P=vrotate( vrotate(<0, -10-150*rand(S),0>, z*THETA), y*PSI);

union {
	cone {
		P-<0,1,0>, 0.2,
		P+<0,1,0>, 0
	}
	sphere {P-<0,1,0>, 0.2}
	pigment { color rgb <1,1,1>-<rand(S)*0.375, rand(S)*0.3, rand(S)*0.375> }
	rotate <11,22,33>
}


/*
	sphere { <0,-10-150*rand(S),0>, 0.2
		rotate z*THETA
		rotate y*PSI
		pigment { color rgb <1,1,1>-<rand(S)*0.375, rand(S)*0.3, rand(S)*0.375> }
	}
*/

#declare I=I+1;
#end

light_source
{
	<0, +7, 0> color rgb 1
}

light_source
{
	<0, -8 0> color rgb<1.0, 0.1, 0.5>
}
