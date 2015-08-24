#ifndef _GROUP_LIST_H_
#define _GROUP_LIST_H_
#include <map>

class Group;
class GroupList
{
	public:

		GroupList();		
		~GroupList();		

		void setToBegin();
		void addGroup(Group* group);

		bool isEmpty();
		bool isEnd();
		Group* next();

	private:
		std::map<int,Group*> _groups;
		std::map<int,Group*>::iterator _groupsIter;
};
#endif
