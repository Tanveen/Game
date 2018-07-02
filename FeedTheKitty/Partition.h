#pragma once
#include "GameTable.h"
class Partition
{
public:
	int delay;  // assume in report 
	GameTable *gtp; // acc to header file // maintains game list.
	Partition *next; // maintain next partition (table + next table like linked list) 
	Partition();
	Partition(int tableId); // new game table
	int getDelay(); // return the duration of a table partiton
	Partition* getNext(); // to loop through partitions 
	void setNext(Partition * K); // to set the next partiton
	GameTable* getGameTablePointer(); // to get the gtp pointer 
	void setGameTablePointer(GameTable * G); // set the gtp pointer 
	~Partition();
};

