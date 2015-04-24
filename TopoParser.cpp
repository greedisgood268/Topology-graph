#include "TopoParser.h"
#include "PeerList.h"
#include "Peer.h"
#include <cstdio>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Color.h"

const int MaxLineLength = 256;

TopoParser::TopoParser()
{
}
TopoParser::~TopoParser()
{
}
PeerList* TopoParser::parseFile(char *fileName, bool natGraph)
{
	FILE *fp = NULL;	
	fp = fopen(fileName,"r");

	if(!fp)
	{
		printf("%s%s\n","Failed to open the file to read : ",fileName);
		return NULL;
	}
	char *temporyLineIndex = NULL;
	char lineOfMessage[MaxLineLength];
	int currentPeerPid = 0;
	int currentPeerParentPid = 0;
	bool rescueFlag = false,childFlag = false;

	PeerList *peerList = new PeerList();

	while(!feof(fp))
	{
		childFlag = false;
		rescueFlag = false;
		memset(lineOfMessage,0,MaxLineLength);
		temporyLineIndex = NULL;

		fgets(lineOfMessage,MaxLineLength,fp);				
		if(strlen(lineOfMessage) == 1)
			break;
		temporyLineIndex = strstr(lineOfMessage,"]");
		if(temporyLineIndex == NULL)
			continue;
		temporyLineIndex++;
		while(isblank(*temporyLineIndex)) 
			temporyLineIndex++;
		
		if( !isdigit(*temporyLineIndex) )		
			continue;

		currentPeerPid = atoi(temporyLineIndex);		
		bool natFlag = false;
		char *publicIp = NULL, *privateIp = NULL,*temporyHead = NULL;
		int squareLength = 0;	
		temporyHead = strstr(temporyLineIndex,"(");	
		temporyLineIndex = strstr(temporyLineIndex,")");	
		squareLength = temporyLineIndex - temporyHead;	

		publicIp = temporyHead;
		temporyHead = strstr(temporyLineIndex,"(");
		temporyLineIndex = strstr(temporyHead,")");
		privateIp = temporyHead;
		if(strncmp(privateIp,publicIp,squareLength) != 0)	
			natFlag = true;	
		/*
		for(int i = 0 ; i < 2 ; i++)		
		{
			temporyLineIndex = strstr(temporyLineIndex,")");	
			temporyLineIndex++;
		}
		*/
		temporyLineIndex+=2;			
		if(*temporyLineIndex == 'C')
			continue;

		temporyLineIndex+=2;
		currentPeerParentPid = atoi(temporyLineIndex);

		while(isblank(*temporyLineIndex) || isdigit(*temporyLineIndex))
			temporyLineIndex++;
		/*
		temporyLineIndex = strstr(temporyLineIndex," ");
		temporyLineIndex++;
		*/
		if(*temporyLineIndex == 'R')
			rescueFlag = true;
		else 
			rescueFlag = false;	

		Peer *parent = peerList -> getPeer(currentPeerParentPid);
		if(parent == NULL)
			parent = new Peer(currentPeerParentPid);

		if(rescueFlag)
			parent -> addRescueChild(currentPeerPid);	
		else 
			parent -> addNormalChild(currentPeerPid);	
	
		peerList -> addPeer(parent);

		Peer *peer = peerList -> getPeer(currentPeerPid);
		if(peer == NULL)
		{
			peer = new Peer(currentPeerPid);	
			peerList -> addPeer(peer);
		}

		if(natFlag && natGraph)
			peer -> setType(Color::nat);
	}
	fclose(fp);
	return peerList;
}
