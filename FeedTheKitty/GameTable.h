#pragma once
#include "Game.h"
#include <string>
class GameTable
{

public:
	int tableid;
	Game newgame;
	int players, dice_num, mice_num;
	string infile; // input file
	GameTable(int n); // tableID input 
//	GameTable();
	int getId(); 		
	void tableplay(); 
	int getPlayersNo();
	int getMiceNo();
	int getWinnerId(); 
	int getWinnerMice(); 
	
	~GameTable();
};

