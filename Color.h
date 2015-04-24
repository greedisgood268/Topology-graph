#ifndef _COLOR_H_
#define _COLOR_H_
class PeerList;

struct Color
{
	enum Value{white = 0,nat,red,purple,blue,brown,orange,violet,cyan,seagreen};
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
			default:
				return "white";
		}
	};

};
#endif


