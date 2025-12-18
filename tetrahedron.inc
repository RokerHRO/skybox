#version 3.7;

/*
#declare P1=<-1, -1/sqrt(3), -1/sqrt(6)> * 10;
#declare P2=<+1, -1/sqrt(3), -1/sqrt(6)> * 10;
#declare P3=< 0,  2/sqrt(3), -1/sqrt(6)> * 10;
#declare P4=< 0,  0        , +3/sqrt(6)> * 10;
*/

#declare P1=<-1, -1/sqrt(6), -1/sqrt(3)> * 20;
#declare P2=<+1, -1/sqrt(6), -1/sqrt(3)> * 20;
#declare P3=< 0, -1/sqrt(6),  2/sqrt(3)> * 20;
#declare P4=< 0, +3/sqrt(6),  0        > * 20;



#declare R=0.07;
#declare RR = R/3.0;

#ifndef(ROT)
//#declare ROT=<22,22,22>;
#declare ROT=<0,0,0>;
#end


// vertices of the tetrahedron

sphere{ P1, 2 pigment { color rgb<1,0,0> } rotate ROT }
sphere{ P2, 2 pigment { color rgb<0,1,0> } rotate ROT }
sphere{ P3, 2 pigment { color rgb<0,0,1> } rotate ROT }
sphere{ P4, 2 pigment { color rgb<1,1,1> } rotate ROT }


// edges of the tetrahedron
cylinder { P1, P2, R*2  pigment { color rgb<0,1,0> } }
cylinder { P1, P3, R*2  pigment { color rgb<0,0,1> } }
cylinder { P1, P4, R*2  pigment { color rgb<1,1,1> } }

cylinder { P2, P3, R*2  pigment { color red 1 } }
cylinder { P3, P4, R*2  pigment { color red 1 } }
cylinder { P4, P2, R*2  pigment { color red 1 } }

// faces of the tetrahedron
#include "triangle.inc"

Triangle(P1, P2, P4, 12)
Triangle(P2, P3, P4, 12)
Triangle(P3, P1, P4, 12)
Triangle(P1, P2, P3, 12)


torus { 25, 2.5
	pigment { color rgb<1.0, 0.6, 0.2> }
	finish { phong 0.5 }
	rotate z*30
}

light_source
{
	<-6, +6, -6> color 1
}
