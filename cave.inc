#version 3.7;

#declare R=0.07;
#declare RR = R/3.0;

#ifndef(ROT)
//#declare ROT=<22,22,22>;
#declare ROT=<0,0,0>;
#end

#declare S=seed(471100);

#declare T=texture
	{
		pigment { color rgb 0.722 }
//		pigment { granite scale 3 }
		normal { granite 0.2 scale 1.2 }
		finish { phong 0.6 }
	}


union {
	sphere { <0,0,0>, 10 }

#declare I=0;
#while(I<3333)

	#declare P=vrotate(
		vrotate(
			vrotate(<0,1,0>, <rand(S)*360, rand(S)*360, rand(S)*360>),
			<rand(S)*360, rand(S)*360, rand(S)*360>),
		<rand(S)*360, rand(S)*360, rand(S)*360> );

	box { -0.6, +0.6 scale 1+rand(S) rotate <rand(S)*360, rand(S)*360, rand(S)*360> translate P*10
	//	pigment { color rgb<0.3, 1.0, 0.3> }
	}

#declare I=I+1;
#end

	hollow
	texture { T }
}

light_source
{
	<0, +2, 0> color rgb<0.4, 0.6, 1.0>*0.3
	area_light <0, 0.3, 0>, <0.3, 0, 0>, 4, 4 jitter orient circular adaptive 1
	fade_distance 6
	fade_power 1
}

light_source
{
	<1, -8.3, 0> color rgb<1.0, 0.1, 0.1>*1.7
	fade_distance 1
	fade_power 1
	area_light <0, 0.3, 0>, <0.3, 0, 0>, 4, 4 jitter orient circular adaptive 1
}

