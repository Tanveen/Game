#pragma once
#include "Partition.h"
#define MAX_PLAYERS 6 
class TimingWheel
{
	vector<Partition *> S; // to maintain pointer to partition 
	int currSlot; // what instance game playing 
	bool isGameStart; 
	int currentActivePlayers;
	int totalPlayers;
	int maxMice;
public:
	TimingWheel();
	void insert(int players, Partition * p);
	void schedule(ofstream & file);
	void clearCurrentSlot();
	int getTotalPlayers();
	void updateTotalPlayers(int n);
	int getCurrentActivePlayers();
	void updateCurrentActivePlayers(int n);
	void setMaxMice(int n);
	int getMaxMice();
	void printCurrentStatus(ofstream & d);
	void printCurrentStatus();
	~TimingWheel();
};

