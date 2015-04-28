#ifndef _COLOR_H_
#define _COLOR_H_
class PeerList;

struct Color
{
	enum Value{white = 0,nat,red,purple,blue,brown,orange,violet,cyan,seagreen,lawngreen,springgreen,cornflowerblue,magenta,darkgoldenrod,chololate,gold,tomato,deeppink,orangered,darkolivegreen,indianred,lightpink};
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
				return "lawgreen";
			case springgreen:
				return "springgreen";
			case cornflowerblue: 
				return "cornflowerblue"; 
			case magenta:
				return "magenta";
			case darkgoldenrod: 
				return "darkgoldenrod";
			case chololate:
				return  "chololate";
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
			default:
				return "white";
		}
	};

};
#endif


