#include "Game.h"
#include <fstream>
#include "DiceFaceBase.h"
#include "Dice.h"
Game::Game()
{
	direction = 1; // assumed if red, then -1 :) 
				   // simply maintain direction
}// we need this at start of game as constructor does

void Game::setPlayers(int n)
{
	players = n; // user input
	// setMice() [say mice =20] /--> called initially here so now player share count
	int eachPlayerShare = mice / players; // equally distributed 
	int bowlShare = mice%players; // rest of the mice should be in bowl so remainder in the bowl
	for (int i = 0; i<players; i++) 
	{
		// looping through players and making objects and giving them ID and their share
		Player * p = new Player(i, eachPlayerShare); // player class ka object
		P.push_back(p); // push into player vector
	}
	bowl.update(bowlShare); // bowl updated here 

	//cout<<"Player Details"<<endl;    This code is commented as not required in part 3 and 4
	//for(int i=0;i<players;i++){
	//		(*P[i]).displayDetails();
	//} 		
}

void Game::setDiceNumber(int diceNumber)
{
	diceNo = diceNumber; // setter // setting objects // calling them initialising game class here 
}

int Game::numberOfActivePlayers() // how many players active
{
	int count = 0;
	Player *p = nullptr; // make it global 
	for (int i = 0; i<players; i++) 
	{
		if ((*P[i]).isPlayerActive()) // looping through players and let us know the active players
		{
			cout<<i<<" is active"<<endl;
			count++;
		}
		else 
		{
			cout<<i<<" is inactive"<<endl;
		}
	}
	return count;
}

bool Game::isOnlyOneActive() // returns if only one player is active // check active players 
// return winner as well 
{
	int count = 0;
	// Player *p = nullptr;
	for (int i = 0; i<players; i++) //looping through players and if active then count ++ 
	{
		if ((*P[i]).isPlayerActive()) 
		{
			count++;
			p = P[i];
		}
	}
	if (count == 1) {
		(*p).setWinner(); // if count = 1 then he is the winner // different pointer to set winner
		return true;
	}
	else 
	{
		return false;
	}
}

void Game::setMiceNumber(int miceNo)
{
	mice = miceNo; // setting number of mice 
}

void Game::reverseDirection()
{
	direction *= -1; // direction multiplied by -1 
	//direction = direction * -1;
}

void Game::createDice(const char * filename) // very hard & important 
// read file and make dice 
// getcolor map and symbol map are made here actually
// SetDiceFace() called from here 
// probability taken from this method in actual 
{
	vector<string> faceColor;   
	vector<int> facePercent;
	vector<string> symbol;
	vector<int> symbolPercent;
	vector<int> colorRangeMap;
	vector<int> symbolRangeMap;
	int face = 0, color = 0, symbols = 0;
	ifstream f; // read
	f.open(filename); // hardcorded
	if (!f) // if no file
	{
		cout << "Cant open " << endl;
		exit(1);
	}
	f >> face; // indirection operator // used reading from file
	f >> color; // >> ignore white spaces
	f >> symbols;
	for (int i = 0; i<color; i++) 
	{ // looping through colors
		string color;
		int percent;
		f >> color;
		f >> percent;
		faceColor.push_back(color); 
		facePercent.push_back(percent); // logic built here // probabilty
	}
	for (int i = 0; i<symbols; i++) 
	 { // looping through symbols and selecting the symbol to push to dice
		string sym;
		int percent;
		f >> sym;
		f >> percent;
		symbol.push_back(sym);
		symbolPercent.push_back(percent); // according to probabilty
	}
	for (int i = 0; i<faceColor.size(); i++) // range selected here
	{
		if (i == 0)
		{
			colorRangeMap.push_back(facePercent[i]);  // green here 
		}// green-60 red-40 // made corresponding map // this is an example 
		else
		{
			colorRangeMap.push_back(colorRangeMap[i - 1] + facePercent[i]); // red here
		}
	}
	for (int i = 0; i<symbol.size(); i++)
	{ // looping through symbols 
		// SC , AR, MC 10 and BL 70
		if (i == 0)
		{
			symbolRangeMap.push_back(symbolPercent[i]);
		}
		else
		{
			symbolRangeMap.push_back(symbolRangeMap[i - 1] + symbolPercent[i]);
		}
	}

	f.close(); 

	for (int i = 0; i<diceNo; i++)  // dice number from input 
	{
		Dice * dice = new Dice(); // dice object and push faces accordingly // each dice 
		(*dice).setFaces(face, faceColor, symbol, colorRangeMap, symbolRangeMap); // map using to see probabilty
		D.push_back(dice); // pushing into dice
	}
}
void Game::play() //  
{
	
	int curr = 0; // players = 0 assume 
	while (!isOnlyOneActive()) // loop till only one player active // see function above
	{
		//cout<<"Number of Active Players:"<<numberOfActivePlayers()<<endl; Not required for part 3 and 4
		Player * p = P[curr]; // current player initialised 
		//(*p).displayDetails(); Not required for part 3 and 4
		cout << p->getID(); 
		cout << "********";
		cout << p->getMiceNo();
		cout << endl;
		if ((*p).isPlayerActive()) // if active then roll dice
		{
			for (int i = 0; i<diceNo; i++) // looping through dice here 
			{ 
				//Though code is generic we have rules for only 2 colors and 4 symbols.
				//From where we get rules in case of more colors and symbols
				Dice * d = D[i]; 
				DiceFaceBase DF = (*d).roll(); // roll return diceFace (object of class DiceFaceBase)  
				//DF.display(); Not required for part 3 and 4
				//cout<<endl;
				string color = DF.getColor(); // base class methods to fetch color and symbol 
				string symbol = DF.getSymbol(); 
				cout << color;
				cout << "*****";
				cout << symbol;
				//cout << d->getSymbol(int n, vector<string> symbol, vector<int> symbolMap);
				cout << endl;
				if (symbol == "SleepingCat") 
				{
					//Do nothing
				}
				if (symbol == "Bowl") 
				{
					(*p).giveMouse(); // player gives one mouse 
					bowl.addMouse(); // add bowl to mouse 
				}
				if (symbol == "Arrow") // mouse to next player 
				{
					int next; 
					// see direction to see if mouse to given to which player 
					if (curr == 0 && direction == -1)
					{
						next = players - 1; // reverse direction here 
					}
					else
					{
						// + direction coz out of bound - nai jana 
						next = (curr + direction) % players; // % used to go round and here 
					}
					(*p).giveMouse(); // player give mouse 
					Player * q = P[next]; // player vector gives next player 
					(*q).takeMouse(); // that player takes mouse 
				}
				if (symbol == "Mouse") 
				{
					bowl.remove(); // bowl minus
					(*p).takeMouse(); // player take mouse
				}
				if (color == "Red")
				{
					reverseDirection(); // reverse direction // multiply with -1 
				}
			}
		}
		cout << p->getID();
		cout << "********";
		cout << p->getMiceNo();
		cout << endl;
		if (curr == 0 && direction == -1)
		{
			curr = players - 1; // circle iterate see direction and select player 
		}
		else
		{
			curr = (curr + direction) % players; // circle iterator see direction and select player 
		}
	}
}

void Game::result()
{
	for (int i = 0; i<players; i++) 
	{ // looping players object
		if ((*P[i]).isPlayerWinner())
		{
			cout << "Player with ID " << (*P[i]).getID() << " is Winner" << endl;
			return;
		}
	}
	cout << "Till Now no one is Winner" << endl;
}

int Game::getWinnerID() // looping through players and fetch winner  and ID
{
	for (int i = 0; i<players; i++)
	{
		if ((*P[i]).isPlayerWinner()) 
		{
			return (*P[i]).getID();
		}
	}
	return 0;
}

int Game::getWinnerMiceNo() 
{
	for (int i = 0; i<players; i++) 
	{
		if ((*P[i]).isPlayerWinner()) 
		{
			return (*P[i]).getMiceNo();
		}
	}
	return 0;
}


Game::~Game()
{
}
