#include <iostream>
#include "PeerList.h"
#include "TopoParser.h"
#include "Color.h"
#include "GraphPrinter.h"
#include "GroupPrinter.h"
#include "Drawer.h"
#include "string.h"
#include "GroupList.h"
#include "Grouper.h"

#define MAX_GROUP_SIZE 256

using namespace std;

int main(int argc, char**argv)
{
	if(argc >= 4)
	{
		TopoParser parser;
		PeerList *peerList = NULL;

		if( strcmp("NAT",argv[1]) == 0)
			peerList = parser.parseFile(argv[2], NAT_GRAPH);
		else if( strcmp("GROUP",argv[1]) == 0)
		{
			peerList = parser.parseFile(argv[2], NON_NAT_GRAPH);
			for(int i = 4; i < argc; i++)
			{
				Drawer drawer;
				drawer.colorNodes( argv[i],peerList,i-2);
			}	

			GraphPrinter printer;
			printer.printGraph(peerList, argv[3]);
			if (peerList)
				delete peerList;
		}
		else if( strcmp("SUBGROUP",argv[1]) == 0 )
		{
			peerList = parser.parseFile(argv[2], NON_NAT_GRAPH);

			char *groupFiles[MAX_GROUP_SIZE] = {0};
			for(int i = 4; i < argc; i++)
				(groupFiles[i-4]) = argv[i];
			
			Grouper grouper;
			GroupList *list = grouper.getGroupNodes(groupFiles);
			GroupPrinter printer;
			printer.printGraph(peerList,list,argv[3]);
			if (peerList)
				delete peerList;
			if(list)
				delete list;
		}
		else
		{
			cout<<"No such option exists: "<<argv[1]<<endl;
			return 0;
		}
	}
	else
		cout<<"Wrong command usage"<<endl;
	return 0;
}


