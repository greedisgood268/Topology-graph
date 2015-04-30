#include <iostream>
#include "PeerList.h"
#include "TopoParser.h"
#include "Color.h"
#include "GraphPrinter.h"
#include "Drawer.h"
#include "string.h"
using namespace std;
void drawWithHightNode(char *name, PeerList *peerList, int type);

int main(int argc, char**argv)
{
	if(argc == 1)	
		return 0;////loop requeset
	else if (argc >= 4)
	{
		TopoParser parser;
		PeerList *peerList = NULL;

		if( strcmp("NAT",argv[1]) == 0)
			peerList = parser.parseFile(argv[2], true);
		else if( strcmp("GROUP",argv[1]) == 0)
			peerList = parser.parseFile(argv[2], false);
		else
		{
			cout<<"No such option exists: "<<argv[1]<<endl;
			return 0;
		}

		for(int i = 4; i < argc; i++)
		{
			Drawer drawer;
			drawer.colorNodes( argv[i],peerList,i-2);
		}	

		GraphPrinter printer;
		printer.printGraph(peerList, argv[3]);
	}
	else
		cout<<"Wrong command usage"<<endl;
	return 0;
}

