#include "GroupPrinter.h"
#include "GroupList.h"
#include "Group.h"
#include <cstdio>
#include <stdlib.h>
#include <string.h>

const int GRAPHMSG_LENGTH = 60;
char GROUP_TEMPORARY_FILE[] = "temporaryFile.txt";

void GroupPrinter::printGraph(PeerList *peerList,GroupList *groupList, char *outputFileName)
{
	if(peerList == NULL)
		return;

	std::string graph;
	getGraphResult(peerList, groupList,graph);
	drawSubGraph(graph,groupList);
	printToTemporaryFile( graph );

	std::string command;
	command = "dot ";
	command += GROUP_TEMPORARY_FILE;
	command += " -T jpeg -o"; 
	command += outputFileName;
	if(system(command.c_str()) == -1)
	{
		printf("%s\n","Unable to operate the program");
		return;
	}
	command.erase(command.begin(),command.end());
	command = "rm ";
	command += GROUP_TEMPORARY_FILE;
	//system(command.c_str());
}

void GroupPrinter::printToTemporaryFile(std::string &graph)
{
	FILE *fp = fopen(GROUP_TEMPORARY_FILE,"w");
	if(fp == NULL)
	{
		printf("%s\n","Failed to create temporary files");
		return;
	}

	fputs(graph.c_str(), fp);	
	fclose(fp);
}

void GroupPrinter::drawSubGraph(std::string &graph, GroupList *groupList)
{
	if(groupList -> isEmpty())
		return;

	graph.erase(--graph.end());		
	groupList -> setToBegin();
	char buffer[GRAPHMSG_LENGTH] = {0};
	while(!groupList -> isEnd())
	{
		printf("hello");
		Group *group = groupList -> next();

		memset(buffer,0,GRAPHMSG_LENGTH);
		sprintf(buffer,"subgraph \"group %d\"  { label=\"group %d\";",group -> getGroupId(),group -> getGroupId());
		graph += buffer;

		group -> setToBegin();
		while( !group -> isEnd())
		{
			memset(buffer,0,GRAPHMSG_LENGTH);
			sprintf(buffer,"\"%d\"; ",group -> next());
			graph += buffer;
		}
		memset(buffer,0,GRAPHMSG_LENGTH);
		sprintf(buffer,"}\n");
		graph += buffer;
	}

	memset(buffer,0,GRAPHMSG_LENGTH);
	sprintf(buffer,"}\n");
	graph += buffer;
}
