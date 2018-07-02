#include "GameTable.h"
#include <time.h>
#include <algorithm>

#define MAX_PLAYERS 6 

//GameTable::GameTable()
//{
//}


GameTable::GameTable(int n) // many tables so created this class instead main method // table id = n 
{
	// Game newgame;
	tableid = n; 
	infile = "input";
	srand(time(NULL) + rand()); // to generate random numbers // site internet
	dice_num = 2;        //hard coded right now but can be randomly generated //was generating unexpected results
	mice_num = 20;       //hard coded right now but can be randomly generated
	players = 2 + rand() % (MAX_PLAYERS - 2); // minimum 2 players so 2+RAND() 
	newgame.setDiceNumber(dice_num); // game class methods setters here 
	newgame.setMiceNumber(mice_num);
	newgame.setPlayers(players);
	newgame.createDice(infile.c_str());  // passing input infile // c_str --> constant pointer to string 
	// else errors 
}

int GameTable::getId() // get ID
{
	return tableid;
}

void GameTable::tableplay() // calls play() from Game (part III) simulating each table
{
	newgame.play();
}

int GameTable::getPlayersNo()	// collecting stats
{
	return players;
}

int GameTable::getMiceNo() // collecting stats
{
	return mice_num;
}

int GameTable::getWinnerId() // collecting stats
{
	return newgame.getWinnerID();
}

int GameTable::getWinnerMice() // number of mice with number in game class
{
	return newgame.getWinnerMiceNo();
}

GameTable::~GameTable()
{
}
