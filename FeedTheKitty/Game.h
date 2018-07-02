#pragma once
#include<vector>
#include "Player.h"
#include "Dice.h"
#include "Bowl.h"
class Game
{
	int direction;
	int players; //  counts
	int diceNo; 
	int mice;
	vector<Player *> P; // players object maintained 
						// can be more than one so vector
	vector<Dice *> D; // dice class ka object maintained 
	Bowl bowl;  // one bowl class ka object
	
public:
	Game();
	Player *p = nullptr;
	void setPlayers(int n);
	void setDiceNumber(int diceNumber);
	int numberOfActivePlayers();
	bool isOnlyOneActive();
	void setMiceNumber(int miceNo);
	void reverseDirection();
	void createDice(const char * filename);
	void play();
	void result();
	int getWinnerID();
	int getWinnerMiceNo();
	~Game();
};

