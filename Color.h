#ifndef _COLOR_H_
#define _COLOR_H_
class PeerList;

struct Color
{
	enum Value{white = 0,nat,purple,blue,brown,orange,yellow,cyan,seagreen,lawngreen,\
			springgreen,cornflowerblue,magenta,darkgoldenrod,chocolate,gold,tomato,deeppink,\
			orangered,darkolivegreen,indianred,lightpink,powderblue,peru,red,blueviolet,darkgreen,\
			darkorange,darkslateblue,firebrick,ghostwhite,indigo,lightsalmon,lightsteelblue,mediumpurple,\
			mediumvioletred,navajowhite,paleturquoise,pink,steelblue,darksalmon,\
			darkturquoise,dimgrey,hotpink,lightcoral,limegreen,mediumblue,mediumspringgreen,lightcyan,\
			mediumorchid,palegreen,sandybrown,yellowgreen,sienna,olivedrab2,greenyellow,tomato4,tan1,violetred3\
			,wheat4,rosybrown,deepskyblue};

	const static char * toString(int value)
	{
		switch (value)
		{
			case white:
				return "white";
			case nat:
				return "green";
			case purple:
				return "plum";
			case seagreen:
				return "seagreen";
			case blue:
				return "skyblue";
			case red:
				return "red";
			case brown:
				return "burlywood";
			case orange:
				return "orange";
			case yellow: 
				return "yellow";
			case cyan:
				return "cyan";
			case lawngreen:
				return "lawngreen";
			case springgreen:
				return "springgreen";
			case cornflowerblue: 
				return "cornflowerblue"; 
			case magenta:
				return "magenta";
			case darkgoldenrod: 
				return "darkgoldenrod";
			case chocolate:
				return  "chocolate";
			case  gold:
				return "gold";
			case tomato:
				return "tomato";
			case deeppink:
				return "deeppink";
			case orangered:
				return "orangered";
			case darkolivegreen:
				return  "darkolivegreen";
			case indianred:
				return "indianred";
			case lightpink:
				return "lightpink";
			case powderblue:
				return "powderblue";
			case peru:
				return "peru";
			case blueviolet:
				return "blueviolet";
			case darkgreen:
				return "darkgreen";
			case darkorange:
				return "darkorange";
			case darkslateblue:
				return "darkslateblue";
			case firebrick:
				return "firebrick";
			case ghostwhite:
				return "ghostwhite";
			case indigo:
				return "indigo";
			case lightsalmon:
				return "lightsalmon";
			case lightsteelblue:
				return "lightsteelblue";
			case mediumpurple:
				return "mediumpurple";
			case mediumvioletred:
				return "mediumvioletred";
			case navajowhite:
				return "navajowhite";
			case paleturquoise:
				return "paleturquoise";
			case pink:
				return "pink";
			case steelblue:
				return "steelblue";
			case darksalmon:
				return "darksalmon";
			case darkturquoise:
				return "darkturquoise";
			case dimgrey:
				return "dimgrey";
			case hotpink:
				return "hotpink";
			case lightcoral:
				return "lightcoral";
			case limegreen:
				return "limegreen";
			case mediumblue:
				return "mediumblue";
			case mediumspringgreen:
				return "mediumspringgreen";
			case lightcyan:
				return "lightcyan";
			case mediumorchid:
				return "mediumorchid";
			case palegreen:
				return "palegreen";
			case sandybrown:
				return "sandybrown";
			case yellowgreen:
				return "yellowgreen";
			case sienna:
				return "sienna";
			case olivedrab2:
				return "olivedrab2";
			case greenyellow:
				return "greenyellow";
			case tomato4:
				return "tomato4";
			case tan1:
				return "tan1";
			case violetred3:
				return "violetred3";
			case wheat4:
				return "wheat4";
			case rosybrown:
				return "rosybrown";
			case deepskyblue:
				return "deepskyblue";
			default:
				return "white";
		}
	};

};
#endif


