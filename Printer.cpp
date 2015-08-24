#include <cstdio>
#include "string.h"
#include "string"
#include <list>

#include "Printer.h"
#include "PeerList.h"
#include "Peer.h"
#include "Color.h"

const int COLOR_LENGTH = 60;

Printer::Printer()
{
}
Printer::~Printer()	
{
}

void Printer::print(PeerList *peerList)
{
	if(peerList == NULL)
		return;
	std::string graph;
	getGraphResult(peerList, graph);
}

void Printer::getGraphResult( PeerList *peerList, std::string &graph)
{
	graph += "digraph{\n";
	colorNodes(peerList, graph);
	colorLines(peerList, graph);
}

void Printer::colorNodes(PeerList *peerList, std::string &graph )
{
	char colorLine[COLOR_LENGTH];
	graph += "{\nnode [style=filled]\n";
	peerList -> setToBegin();
	Peer *peer ; 
	while((peer = peerList -> next()) != NULL)	
	{
		if(peer -> getType() != Color::white)
		{
			memset(colorLine,COLOR_LENGTH,0);
			sprintf(colorLine,"%u%s%s%s",peer -> getPid(),\
				" [fillcolor=",Color::toString(peer -> getType()),"]\n");
			graph+= colorLine;
		}
	}
	graph += "}\n";
}

void Printer::colorLines(PeerList *peerList, std::string &graph)
{
	char buffer[COLOR_LENGTH];
	peerList -> setToBegin();	
	Peer *peer;

	while((peer = peerList -> next()) != NULL)
	{
		colorNormalLine(peer, graph);
		colorRescueLine(peer, graph);
	}
	graph += "}";
}

void Printer::colorRescueLine (Peer *peer, std::string &graph)
{
	char buffer[COLOR_LENGTH];
	const std::list<unsigned int>*nodes = peer -> getRescueChild();
	if( !nodes -> empty() )
	{
		std::list<unsigned int>::const_iterator Iter;
		for(Iter = nodes -> begin(); Iter != nodes -> end();Iter++)
		{
			memset(buffer,0,COLOR_LENGTH);
			sprintf(buffer,"\"%d\" -> \"%d\"[color = red]; \n",peer -> getPid() ,*Iter);
			graph += buffer;
		}
	}
}

void Printer::colorNormalLine (Peer *peer, std::string &graph)
{
	char buffer[COLOR_LENGTH];
	const std::list<unsigned int>*nodes = peer -> getNormalChild();
	if( !nodes -> empty() )
	{
		std::list<unsigned int>::const_iterator Iter;
		for(Iter = nodes -> begin(); Iter != nodes -> end();Iter++)
		{
			memset(buffer,0,COLOR_LENGTH);
			sprintf(buffer,"\"%d\" -> \"%d\"; \n",peer -> getPid() ,*Iter);
			graph += buffer;
		}
	}
}

