#ifndef _GROUP_H_
#define _GROUP_H_
#include<list>

class Group
{
	public:

		Group(int groupId);
		~Group(){};
		int next();
		int getGroupId(){return _groupId;};	
		void setToBegin();
		bool isEnd();
		bool isEmpty();
		void addPeer(int pid);

	private:

		std::list<int> _member;
		std::list<int>::iterator _memberIter;
		int _groupId;
};
#endif
