#include "PeerList.h"
#include "Peer.h"
#include "cstdio"

PeerList::PeerList()
{
}

PeerList::~PeerList()
{
	for(peerMap_Iter = peerMap_.begin();peerMap_Iter != peerMap_.end();peerMap_Iter++)	
		delete peerMap_Iter -> second;
	peerMap_.clear();
}
void PeerList::addPeer(Peer *peer)
{
	peerMap_[peer -> getPid()] = peer;
}

void PeerList::deletePeer(unsigned int pid)
{
	std::map<unsigned int ,Peer*>::iterator Iter;
	Iter = peerMap_.find(pid);
	if(Iter == peerMap_.end())
		return;
	delete Iter -> second;
	peerMap_.erase(Iter);
}

void PeerList::setToBegin()
{
	peerMap_Iter = peerMap_.begin();
}

Peer* PeerList::next()
{
	if(peerMap_Iter != peerMap_.end())
	{
		Peer *peer = peerMap_Iter -> second;
		peerMap_Iter++;
		return peer;
	}
	return NULL;
}
Peer* PeerList::getPeer(unsigned int pid)
{
	peerMap_Iter = peerMap_.find(pid);
	if(peerMap_Iter == peerMap_.end())
		return NULL;
	return peerMap_Iter -> second;
}

