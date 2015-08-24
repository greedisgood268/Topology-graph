#ifndef _GROUP_PRINTER_H_
#define _GROUP_PRINTER_H_
#include "Printer.h"

class GroupList;

class GroupPrinter:public Printer
{
	public:
		void printGraph(PeerList *peerList,GroupList *groupList, char *outputFileName);
	private: 

		void colorNodes(PeerList *peerList, std::string &graph );
		void getGraphResult( PeerList *peerList, GroupList *groupList,std::string &graph);
		void printToTemporaryFile(std::string &graph);
		void colorLines(PeerList *peerList, std::string &graph);
		void colorRescueLine (Peer *peer, std::string &graph);
		void colorNormalLine (Peer *peer, std::string &graph);
		void drawSubGraph(std::string &graph, GroupList *groupList);
};
#endif
