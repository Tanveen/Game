#pragma once
#include<string>
#include<vector>
#include "DiceFaceBase.h"
class Dice 
{
public:
	Dice();
	~Dice();
	vector<DiceFaceBase *> F; // vector to set any number of faces 
							  // pointers to point to object of dicebaseface. 
	//any object can be pushed to this vetor 
	int faces;
	string getColor(int n, vector<string> color, vector<int> colorMap); // utility so private
	string getSymbol(int n, vector<string> symbol, vector<int> symbolMap); // utility so private 
	// map because 1-40 so red and 40-60 so green
	// same with symbol , red
	// this will generate number from 1-100 
	// input - probabilty distribution
	
	void setFaces(int f, vector<string> color, vector<string> symbol, vector<int> colorMap, vector<int> symbolMap);
	DiceFaceBase roll();
};

