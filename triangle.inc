#version 3.7;

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

// does NOT draw the triangle itself!
#macro Triangle (P1, P2, P3, Steps)

#local D12 = (P2-P1)/Steps;
#local D13 = (P3-P1)/Steps;
#local D23 = (P3-P2)/Steps;
#local D32 = (P2-P3)/Steps;

#local Q12 = P1;
#local Q13 = P1;
#local Q23 = P2;
#local Q32 = P3;

#local S=0;
#while(S<Steps)

#if(S>0)
	cylinder{ Q13, Q23, R  pigment{ color rgb 1} }
	cylinder{ Q12, Q13, R  pigment{ color rgb 1} }
	cylinder{ Q12, Q32, R  pigment{ color rgb 1} }
#end

	#local QQ12 = Q12 + D12/5;
	#local QQ13 = Q13 + D13/5;
	#local QQ23 = Q23 + D23/5;
	#local QQ32 = Q32 + D32/5;
	
	#local J=1;
	#while(J<5)

		cylinder{ QQ13, QQ23, RR  texture{T} }
		cylinder{ QQ12, QQ13, RR  texture{T} }
		cylinder{ QQ12, QQ32, RR  texture{T} }

		#local QQ12 = QQ12 + D12/5;
		#local QQ13 = QQ13 + D13/5;
		#local QQ23 = QQ23 + D23/5;
		#local QQ32 = QQ32 + D32/5;

	
	#local J=J+1;
	#end

	#local Q12 = Q12 + D12;
	#local Q13 = Q13 + D13;
	#local Q23 = Q23 + D23;
	#local Q32 = Q32 + D32;

#local S=S+1;
#end

#end