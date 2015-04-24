#ifndef _PEERLIST_H_
#define _PEERLIST_H_
#include "Peer.h"
#include <map>

class PeerList
{
	public:

		PeerList();		
		~PeerList();		

		Peer* getPeer(unsigned int pid);
		void addPeer(Peer* peer);
		void deletePeer(unsigned int pid);
		void setToBegin();
		Peer* next();

	private:

		std::map<unsigned int ,Peer*>peerMap_;
		std::map<unsigned int ,Peer*>::iterator peerMap_Iter;
};
#endif
