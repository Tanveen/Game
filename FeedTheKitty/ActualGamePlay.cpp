#include "Game.h"
#include <string>
#include <fstream>
#include <iostream>
#include "TimingWheel.h"


void initialize(TimingWheel & T, int tableNo) // timing wheel object gain kra h by reference // by default
{
	for (int i = 0; i<tableNo; i++) // looping through partitions and create 
	{
		Partition * U = new Partition(i); //using value of i as table id
		T.updateTotalPlayers(U->getDelay()); //As delay is equal to number of players
		T.updateCurrentActivePlayers(U->getDelay());
		T.insert(0, U); //initially inserting all partition as slot 0 as required in the problem
	}
}
void print_status(TimingWheel &T, ofstream & d)
{
	T.printCurrentStatus(d);
}
void print_status(TimingWheel &T)
{
	T.printCurrentStatus();
}
int main()
{
	
	string outfile;
	int currTime = 0, simulationTime, tableNo;
	cout << "Enter output file name" << endl;
	cin >> outfile;
	cout << "Enter Number of tables in Arcade" << endl;
	cin >> tableNo;
	cout << "Enter Simulation time" << endl;
	cin >> simulationTime;
	ofstream file;
	file.open(outfile.c_str());
	TimingWheel T;
	initialize(T, tableNo);
	while (currTime < simulationTime) // loop till simulation time
	{
		print_status(T);
		print_status(T, file);  //polymorphic form of print status to send status to file
		T.schedule(file);
		currTime++;
	}
	file.close();
}