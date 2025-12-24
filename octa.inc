#version 3.7;

#ifndef(ROT)
//#declare ROT=<22,22,22>;
#declare ROT=<0,0,0>;
#end

#declare P1=vrotate(<+20, +00, +00>, ROT);
#declare P2=vrotate(<+00, +00, +20>, ROT);
#declare P3=vrotate(<-20, +00, +00>, ROT);
#declare P4=vrotate(<+00, -00, -20>, ROT);
#declare P5=vrotate(<+00, +20, +00>, ROT);
#declare P6=vrotate(<+00, -20, +00>, ROT);


#declare R=0.07;
#declare RR = R/3.0;


// vertices of the octahedron

sphere{ P1, 2 pigment { color rgb<1,0,0> } finish { phong 0.5 } }
sphere{ P2, 2 pigment { color rgb<0,1,0> } finish { phong 0.5 } }
sphere{ P3, 2 pigment { color rgb<0,0,1> } finish { phong 0.5 } }
sphere{ P4, 2 pigment { color rgb<1,1,0> } finish { phong 0.5 } }
sphere{ P5, 2 pigment { color rgb<1,1,1> } finish { phong 0.5 } }
sphere{ P6, 2 pigment { color rgb 0.25   } finish { phong 0.5 } }


// edges of the octahedron
cylinder { P1, P2, R*2  pigment { color rgb<1,1,0> } }
cylinder { P2, P3, R*2  pigment { color rgb<1,1,0> } }
cylinder { P3, P4, R*2  pigment { color rgb<1,1,0> } }
cylinder { P4, P1, R*2  pigment { color rgb<1,1,0> } }

cylinder { P1, P5, R*2  pigment { color rgb<1,1,0> } }
cylinder { P2, P5, R*2  pigment { color rgb<1,1,0> } }
cylinder { P3, P5, R*2  pigment { color rgb<1,1,0> } }
cylinder { P4, P5, R*2  pigment { color rgb<1,1,0> } }

cylinder { P1, P6, R*2  pigment { color rgb<1,1,0> } }
cylinder { P2, P6, R*2  pigment { color rgb<1,1,0> } }
cylinder { P3, P6, R*2  pigment { color rgb<1,1,0> } }
cylinder { P4, P6, R*2  pigment { color rgb<1,1,0> } }


// faces of the octahedron
#include "triangle.inc"

Triangle(P1, P2, P5, 12)
Triangle(P2, P3, P5, 12)
Triangle(P3, P4, P5, 12)
Triangle(P4, P1, P5, 12)

Triangle(P1, P2, P6, 12)
Triangle(P2, P3, P6, 12)
Triangle(P3, P4, P6, 12)
Triangle(P4, P1, P6, 12)


torus { 25, 2.5
	pigment { color rgb<1.0, 0.6, 0.2> }
	finish { phong 0.5 }
	rotate z*30
}

light_source
{
	<-6, +6, -6> color 1
}
