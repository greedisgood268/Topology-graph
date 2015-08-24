#ifndef _GROUPER_H_
#define _GROUPER_H_
class GroupList;

class Grouper
{
	public:

		Grouper(){};
		~Grouper(){};
		GroupList* getGroupNodes(char **name);

	private:

		Group* getGroupMember(int groupId,char *name);
};
#endif
