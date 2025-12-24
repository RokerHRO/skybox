#version 3.7;

#ifndef(ROT)
//#declare ROT=<22,22,22>;
#declare ROT=<0,0,0>;
#end

#declare Q5=1/sqrt(5);
#declare M5=(5-sqrt(5))/10;
#declare P5=(5+sqrt(5))/10;
#declare SM5=sqrt( (5-sqrt(5))/10 );
#declare SP5=sqrt( (5+sqrt(5))/10 );

/*
#declare P01=<    0, 0,+1> * 20;

#declare P02=< 2*Q5,   0, Q5> * 20;
#declare P03=<   M5, SP5, Q5> * 20;
#declare P04=<  -P5, SM5, Q5> * 20;
#declare P05=<  -P5,-SM5, Q5> * 20;
#declare P06=<   M5,-SP5, Q5> * 20;

#declare P07=<    0, 0,  -1> * 20;

#declare P08=<-2*Q5,    0, -Q5> * 20;
#declare P09=<  -M5, -SP5, -Q5> * 20;
#declare P10=<   P5, -SM5, -Q5> * 20;
#declare P11=<   P5,  SM5, -Q5> * 20;
#declare P12=<  -M5,  SP5, -Q5> * 20;
*/

#declare P01=vrotate(<    0, +1, 0>, ROT) * 20;

#declare P02=vrotate(< 2*Q5, Q5,   0>, ROT) * 20;
#declare P03=vrotate(<   M5, Q5, SP5>, ROT) * 20;
#declare P04=vrotate(<  -P5, Q5, SM5>, ROT) * 20;
#declare P05=vrotate(<  -P5, Q5,-SM5>, ROT) * 20;
#declare P06=vrotate(<   M5, Q5,-SP5>, ROT) * 20;

#declare P07=vrotate(<    0, -1, 0>, ROT) * 20;

#declare P08=vrotate(<-2*Q5, -Q5,    0>, ROT) * 20;
#declare P09=vrotate(<  -M5, -Q5, -SP5>, ROT) * 20;
#declare P10=vrotate(<   P5, -Q5, -SM5>, ROT) * 20;
#declare P11=vrotate(<   P5, -Q5,  SM5>, ROT) * 20;
#declare P12=vrotate(<  -M5, -Q5,  SP5>, ROT) * 20;


#declare R=0.07;
#declare RR = R/3.0;


// vertices of the icosahedron
sphere{ P01, 2 pigment { color rgb<1,1,1> } finish { phong 0.5 } }
sphere{ P02, 2 pigment { color rgb<1,0,0> } finish { phong 0.5 } }
sphere{ P03, 2 pigment { color rgb<1,0,0> } finish { phong 0.5 } }
sphere{ P04, 2 pigment { color rgb<1,0,0> } finish { phong 0.5 } }
sphere{ P05, 2 pigment { color rgb<1,0,0> } finish { phong 0.5 } }
sphere{ P06, 2 pigment { color rgb<1,0,0> } finish { phong 0.5 } }

sphere{ P07, 2 pigment { color rgb 0.25 } finish { phong 0.5 } }
sphere{ P08, 2 pigment { color rgb<0,0,1> } finish { phong 0.5 } }
sphere{ P09, 2 pigment { color rgb<0,0,1> } finish { phong 0.5 } }
sphere{ P10, 2 pigment { color rgb<0,0,1> } finish { phong 0.5 } }
sphere{ P11, 2 pigment { color rgb<0,0,1> } finish { phong 0.5 } }
sphere{ P12, 2 pigment { color rgb<0,0,1> } finish { phong 0.5 } }


// edges of the icosahedron
cylinder { P01, P02, R*2  pigment { color rgb<1,1,0> } }
cylinder { P01, P03, R*2  pigment { color rgb<1,1,0> } }
cylinder { P01, P04, R*2  pigment { color rgb<1,1,0> } }
cylinder { P01, P05, R*2  pigment { color rgb<1,1,0> } }
cylinder { P01, P06, R*2  pigment { color rgb<1,1,0> } }

cylinder { P02, P03, R*2  pigment { color rgb<1,1,0> } }
cylinder { P03, P04, R*2  pigment { color rgb<1,1,0> } }
cylinder { P04, P05, R*2  pigment { color rgb<1,1,0> } }
cylinder { P05, P06, R*2  pigment { color rgb<1,1,0> } }
cylinder { P06, P02, R*2  pigment { color rgb<1,1,0> } }

cylinder { P07, P08, R*2  pigment { color rgb<1,1,0> } }
cylinder { P07, P09, R*2  pigment { color rgb<1,1,0> } }
cylinder { P07, P10, R*2  pigment { color rgb<1,1,0> } }
cylinder { P07, P11, R*2  pigment { color rgb<1,1,0> } }
cylinder { P07, P12, R*2  pigment { color rgb<1,1,0> } }

cylinder { P08, P09, R*2  pigment { color rgb<1,1,0> } }
cylinder { P09, P10, R*2  pigment { color rgb<1,1,0> } }
cylinder { P10, P11, R*2  pigment { color rgb<1,1,0> } }
cylinder { P11, P12, R*2  pigment { color rgb<1,1,0> } }
cylinder { P12, P08, R*2  pigment { color rgb<1,1,0> } }

cylinder { P08, P05, R*2  pigment { color rgb<1,1,0> } }
cylinder { P05, P09, R*2  pigment { color rgb<1,1,0> } }
cylinder { P09, P06, R*2  pigment { color rgb<1,1,0> } }
cylinder { P06, P10, R*2  pigment { color rgb<1,1,0> } }
cylinder { P10, P02, R*2  pigment { color rgb<1,1,0> } }
cylinder { P02, P11, R*2  pigment { color rgb<1,1,0> } }
cylinder { P11, P03, R*2  pigment { color rgb<1,1,0> } }
cylinder { P03, P12, R*2  pigment { color rgb<1,1,0> } }
cylinder { P12, P04, R*2  pigment { color rgb<1,1,0> } }
cylinder { P04, P08, R*2  pigment { color rgb<1,1,0> } }



// faces of the icosahedron
#include "triangle.inc"

Triangle(P01, P02, P03, 5)
Triangle(P01, P03, P04, 5)
Triangle(P01, P04, P05, 5)
Triangle(P01, P05, P06, 5)
Triangle(P01, P06, P02, 5)

Triangle(P02, P11, P03, 5)
Triangle(P03, P11, P12, 5)
Triangle(P03, P12, P04, 5)
Triangle(P04, P12, P08, 5)
Triangle(P04, P08, P05, 5)
Triangle(P05, P08, P09, 5)
Triangle(P05, P09, P06, 5)
Triangle(P06, P09, P10, 5)
Triangle(P02, P06, P10, 5)
Triangle(P02, P10, P11, 5)

Triangle(P07, P08, P09, 5)
Triangle(P07, P09, P10, 5)
Triangle(P07, P10, P11, 5)
Triangle(P07, P11, P12, 5)
Triangle(P07, P12, P08, 5)

torus { 25, 2.5
	pigment { color rgb<1.0, 0.6, 0.2> }
	finish { phong 0.5 }
	rotate z*30
}

light_source
{
	<-6, +6, -6> color 1
}
