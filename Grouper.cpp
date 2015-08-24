#include "GroupList.h"
#include "Grouper.h"
#include "Group.h"
#include <list>
#include <cstdio>
#include <string.h>

const int Max_Line_Length = 256;

GroupList* Grouper::getGroupNodes(char **name)
{
	GroupList *list = new GroupList();

	for(int index = 0 ; ; index++)
	{
		if(name[index] == NULL)
			break;

		Group *group = getGroupMember(index,name[index]);
		if(group)
			list -> addGroup(group);
	}

	return list;
}

Group* Grouper::getGroupMember(int groupId,char *name)
{
	FILE *fp = fopen(name,"r");
	if(fp == NULL)
		return NULL;

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
	Group *group = new Group(groupId);
	
	for(std::list<int>::iterator Iter = nodes.begin(); Iter != nodes.end(); Iter++)
		group -> addPeer(*Iter);

	return group;
}
