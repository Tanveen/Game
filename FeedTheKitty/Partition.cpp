#include "Partition.h"

// representing (table + next table like linked list) 
//maintains 2 pointers 
// header class in part 3 
// table play duration // not to calcualte time but assume -- > players = time units

Partition::Partition()
{
}


Partition::Partition(int tableId)
{
	gtp = new GameTable(tableId);
	next = NULL;
	delay = gtp->getPlayersNo();
}

int Partition::getDelay()
{
	return delay;
}

Partition * Partition::getNext()
{
	return next;
}

void Partition::setNext(Partition * K)
{
	next = K;
}

GameTable * Partition::getGameTablePointer()
{
	return gtp;
}

void Partition::setGameTablePointer(GameTable * G)
{
	gtp = G;
}

Partition::~Partition()
{
}
