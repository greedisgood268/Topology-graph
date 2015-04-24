#ifndef _GRAPHPRINTER_H_
#define _GRAPHPRINTER_H_
#include "Printer.h"
class GraphPrinter: public Printer
{
	public:
		void printGraph(PeerList *peerList, char *name);

	private:
		void printToTemporaryFile(std::string &graph);
};
#endif
