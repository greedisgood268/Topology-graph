#ifndef _COLOR_H_
#define _COLOR_H_
class PeerList;

struct Color
{
	enum Value{white = 0,nat,red,purple,blue,brown,orange,violet,cyan,seagreen,lawngreen,\
			springgreen,cornflowerblue,magenta,darkgoldenrod,chocolate,gold,tomato,deeppink,\
			orangered,darkolivegreen,indianred,lightpink,powderblue,peru};
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
			case violet: 
				return "violet";
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
			default:
				return "white";
		}
	};

};
#endif


