#ifndef _TOPOPARSER_H_
#define _TOPOPARSER_H_

#define NAT_GRAPH true
#define NON_NAT_GRAPH false

class PeerList;

class TopoParser
{
	public:

		TopoParser();
		~TopoParser();
		PeerList* parseFile(char *fileName, bool natGraph);
};
#endif
