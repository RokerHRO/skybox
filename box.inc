#version 3.7;

#declare R=0.07;
#declare RR = R/3.0;

#ifndef(ROT)
//#declare ROT=<22,22,22>;
#declare ROT=<0,0,0>;
#end

#declare T = texture
	{
		pigment { color rgb<0.4, 0.2, 1.0> }
	}

/*
sky_sphere
{
	pigment { color rgb<1.0, 0.7, 0.5>*0.71 }
}
*/

// scene
#declare I=-10;
#while(I<10)

// +Z
cylinder { <-10,  +I, +10>, <+10,  +I, +10>, R pigment { color rgb 1 } rotate ROT }
cylinder { < +I, -10, +10>, < +I, +10, +10>, R pigment { color rgb 1 } rotate ROT }

// -Z
cylinder { < -I, -10, -10>, < -I, +10, -10>, R pigment { color rgb 1 } rotate ROT }
cylinder { <-10,  -I, -10>, <+10,  -I, -10>, R pigment { color rgb 1 } rotate ROT }

// +Y
cylinder { < +I, +10, -10>, < +I, +10, +10>, R pigment { color rgb 1 } rotate ROT }
cylinder { <-10, +10,  -I>, <+10, +10,  -I>, R pigment { color rgb 1 } rotate ROT }

// -Y
cylinder { < -I, -10, -10>, < -I, -10, +10>, R pigment { color rgb 1 } rotate ROT }
cylinder { <-10, -10,  +I>, <+10, -10,  +I>, R pigment { color rgb 1 } rotate ROT }


// +X
cylinder { <+10,  -I, -10>, <+10,  -I, +10>, R pigment { color rgb 1 } rotate ROT }
cylinder { <+10, -10,  -I>, <+10, +10,  -I>, R pigment { color rgb 1 } rotate ROT }

// -X
cylinder { <-10,  +I, -10>, <-10,  +I, +10>, R pigment { color rgb 1 } rotate ROT }
cylinder { <-10, -10,  +I>, <-10, +10,  +I>, R pigment { color rgb 1 } rotate ROT }

#declare J=0;
#while(J<2)

// +Z
cylinder { <-10,  +I+J, +10>, <+10,  +I+J, +10>, RR texture{T} rotate ROT }
cylinder { < +I+J, -10, +10>, < +I+J, +10, +10>, RR texture{T} rotate ROT }

// -Z
cylinder { < -I-J, -10, -10>, < -I-J, +10, -10>, RR texture{T} rotate ROT }
cylinder { <-10,  -I-J, -10>, <+10,  -I-J, -10>, RR texture{T} rotate ROT }

// +Y
cylinder { < +I+J, +10, -10>, < +I+J, +10, +10>, RR texture{T} rotate ROT }
cylinder { <-10, +10,  -I-J>, <+10, +10,  -I-J>, RR texture{T} rotate ROT }

// -Y
cylinder { < -I-J, -10, -10>, < -I-J, -10, +10>, RR texture{T} rotate ROT }
cylinder { <-10, -10,  +I+J>, <+10, -10,  +I+J>, RR texture{T} rotate ROT }


// +X
cylinder { <+10,  -I-J, -10>, <+10,  -I-J, +10>, RR texture{T} rotate ROT }
cylinder { <+10, -10,  -I-J>, <+10, +10,  -I-J>, RR texture{T} rotate ROT }

// -X
cylinder { <-10,  +I+J, -10>, <-10,  +I+J, +10>, RR texture{T} rotate ROT }
cylinder { <-10, -10,  +I+J>, <-10, +10,  +I+J>, RR texture{T} rotate ROT }


#declare J=J+0.4;
#end

#declare I=I+2;
#end

sphere{ <-10,-10,-10>, 2 pigment { color rgb 0.15   } rotate ROT }
sphere{ <+10,-10,-10>, 2 pigment { color rgb<1,0,0> } rotate ROT }
sphere{ <-10,+10,-10>, 2 pigment { color rgb<0,1,0> } rotate ROT }
sphere{ <+10,+10,-10>, 2 pigment { color rgb<1,1,0> } rotate ROT }

sphere{ <-10,-10,+10>, 2 pigment { color rgb<0,0,1> } rotate ROT }
sphere{ <+10,-10,+10>, 2 pigment { color rgb<1,0,1> } rotate ROT }
sphere{ <-10,+10,+10>, 2 pigment { color rgb<0,1,1> } rotate ROT }
sphere{ <+10,+10,+10>, 2 pigment { color rgb<1,1,1> } rotate ROT }

torus { 20, 2.5
	pigment { color rgb<1.0, 0.6, 0.2> }
	finish { phong 0.5 }
	rotate z*30
}

light_source
{
	<-6, +6, -6> color 1
}
