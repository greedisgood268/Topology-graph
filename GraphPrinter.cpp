#include "GraphPrinter.h"
#include <cstdio>
#include <stdlib.h>

char TEMPORARY_FILE[] = "temporaryFile.txt"; 

void GraphPrinter::printGraph(PeerList *peerList, char *outputFileName)
{
	if(peerList == NULL)
		return;

	std::string graph;
	getGraphResult(peerList, graph);
	printToTemporaryFile( graph );

	std::string command;
	command = "dot ";
	command += TEMPORARY_FILE;
	command += " -T jpeg -o"; 
	command += outputFileName;
	if(system(command.c_str()) == -1)
	{
		printf("%s\n","Unable to operate the program");
		return;
	}
	command.erase(command.begin(),command.end());
	command = "rm ";
	command += TEMPORARY_FILE;
	system(command.c_str());
}

void GraphPrinter::printToTemporaryFile(std::string &graph)
{
	FILE *fp = fopen(TEMPORARY_FILE,"w");
	if(fp == NULL)
	{
		printf("%s\n","Failed to create temporary files");
		return;
	}

	fputs(graph.c_str(), fp);	
	fclose(fp);
}
