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

#declare Y70=sin( radians(70) ) * 10;

#declare I=0;
#while(I<180)

torus { 10, R pigment { color rgb 1 }
	sturm
	rotate z*90
	rotate y*I
}

#if(I>0)
#declare C=cos( radians(I-90) ) * 10;
#declare S=sin( radians(I-90) ) * 10;

torus { C, R sturm pigment { color rgb 1 }
	translate<0, S, 0>
}

#end

#declare J=2;
#while(J<10)

intersection {
	torus { 10, RR texture {T}
		sturm
		rotate z*90
		rotate y*(I+J)
	}
	plane{ +y, Y70 }
	plane{ -y, Y70 }
}


#if(I>=20 & I<160)
#declare C=cos( radians(I+J-90) ) * 10;
#declare S=sin( radians(I+J-90) ) * 10;

torus { C, RR  texture{T}
	translate<0, S, 0>
}

#end


#declare J=J+2;
#end

#declare I=I+10;
#end

torus { 20, 2.5
	pigment { color rgb<1.0, 0.6, 0.2> }
	finish { phong 0.5 }
	rotate z*30
}

light_source
{
	<-5, +5, -5> color 1
}
