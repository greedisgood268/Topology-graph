#ifndef _PRINTER_H_
#define _PRINTER_H_
#include <string>
class PeerList;
class Peer;
class Printer
{
	public:

		Printer();	
		~Printer();	
		void print(PeerList *peerList);

	protected:

		void getGraphResult( PeerList *peerList, std::string &graph);
		void colorNodes(PeerList *peerList, std::string &graph );
		void colorLines(PeerList *peerList, std::string &graph);
		void colorRescueLine (Peer *peer, std::string &graph);
		void colorNormalLine (Peer *peer, std::string &graph);
};
#endif

