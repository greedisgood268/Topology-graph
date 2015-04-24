#ifndef _TOPOPARSER_H_
#define _TOPOPARSER_H_
class PeerList;

class TopoParser
{
	public:

		TopoParser();
		~TopoParser();
		PeerList* parseFile(char *fileName, bool natGraph);
};
#endif
