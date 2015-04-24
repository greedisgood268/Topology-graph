#ifndef _TOPOPEER_H_
#define _TOPOPEER_H_
#include <list>

class Peer
{
	public:

		Peer(unsigned int pid){myPid = pid; type_ = 0;};
		~Peer();
		unsigned int getPid(){return myPid;};

		const std::list<unsigned int> *getNormalChild(){normalChild.unique(); return &normalChild;};	
		const std::list<unsigned int> *getRescueChild(){rescueChild.unique(); return &rescueChild;};	

		void addRescueChild(unsigned int pid){rescueChild.push_back(pid);};
		void addNormalChild(unsigned int pid){normalChild.push_back(pid);};
		void setType(int type){type_ = type;};
		int getType(){return type_;};

	private:
		
		std::list<unsigned int> normalChild;
		std::list<unsigned int> rescueChild;
		unsigned int myPid;
		int type_;
};
#endif
