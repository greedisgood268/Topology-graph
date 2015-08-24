#include "Group.h"

Group::Group(int groupId)
{
	_groupId = groupId;
}

int Group::next()
{
	int returnValue = *_memberIter;
	_memberIter++;
	return returnValue;
}

void Group::setToBegin()
{
	_memberIter = _member.begin();
}

bool Group::isEnd()
{
	return _memberIter == _member.end();
}

bool Group::isEmpty()
{
	return _member.empty();
}

void Group::addPeer(int pid)
{
	_member.push_back(pid);
}
