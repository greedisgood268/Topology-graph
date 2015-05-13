#include "Drawer.h"
#include "PeerList.h"
#include "Peer.h"
#include <cstdio>
#include <list>
#include <string.h>

const int Max_Line_Length = 256;

void Drawer::colorNodes(char *name,PeerList* peerList,int colorType)
{
	if( peerList == NULL)
		return;

	FILE *fp = fopen(name,"r");
	if(fp == NULL)
		return;

	char row[Max_Line_Length];
	int number = 0;
	std::list<int> nodes;

	while( true )	
	{
		memset(row,0,Max_Line_Length);
		fscanf(fp,"%d",&number);
		if(feof(fp))
			break;
		nodes.push_back(number);			
	}
	fclose(fp);	

	nodes.unique();	

	peerList -> setToBegin();
	Peer *peer = NULL;
	
	std::list<int>::iterator Iter;
	for(Iter = nodes.begin(); Iter != nodes.end(); Iter++)
	{
		peer = peerList -> getPeer(*Iter);
		if(peer)
			peer -> setType(colorType);
	}
}
