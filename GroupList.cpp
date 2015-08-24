#include "GroupList.h"
#include "Group.h"
#include <cstdio>
GroupList::GroupList()
{

}
GroupList::~GroupList()
{
	std::map<int,Group*>::iterator Iter;
	for(Iter = _groups.begin(); Iter != _groups.end(); Iter++)
	{
		if(Iter -> second)
			delete Iter -> second;
		Iter -> second = NULL;
	}

	_groups.clear();
}

void GroupList::addGroup(Group* group)
{
	std::map<int,Group*>::iterator Iter = _groups.find(group -> getGroupId());
	if(Iter == _groups.end())
		_groups[group -> getGroupId()] = group;
}

void GroupList::setToBegin()
{
	_groupsIter = _groups.begin();
}

bool GroupList::isEmpty()
{
	return _groups.empty();
}

bool GroupList::isEnd()
{
	return _groupsIter == _groups.end();
}

Group* GroupList::next()
{
	Group *returnValue = _groupsIter -> second;
	_groupsIter++;
	return returnValue;
}


