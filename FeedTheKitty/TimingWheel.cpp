#include "TimingWheel.h"
#include <iostream>
#include <fstream>


TimingWheel::TimingWheel()
{
	currentActivePlayers = 0; // initialise zero 
	totalPlayers = 0; // till now how many players 
	maxMice = 0;
	currSlot = 0;
	for (int i = 0; i<MAX_PLAYERS; i++) // MAXPLAYERS = Max time slots ofcourse ;) ;) ;) bn raha haiii 
	{
		S.push_back(NULL); // partitions initialised to null 
	}
	isGameStart = true; // part 4 mentioned when game starts partition slot = 0 but not execute game so slot =NULL  
}

void TimingWheel::insert(int players, Partition * p)// to insert partition into slot with number of players 
{
	Partition *u = NULL; // new partition and loop through all partitons 
	int slot = (currSlot + players) % MAX_PLAYERS;
	if (S[slot] == NULL)
	{ // next next and insert there where is null
		S[slot] = p;
		return;
	}
	else if (S[slot] != NULL) {
		u = S[slot];
		while (u->getNext() != NULL) {
			u = u->getNext();
		}
		u->setNext(p);
		return;
	}
}

void TimingWheel::schedule(ofstream & file) // partitons = 0 assume 
// loop linked list
// delay = noOfPlayers remember
// schedule not execute pehle
// then next time execute hora h and else mei jara h 
// us slot mei list mei loop krega 
// table pointer pe table play in else 
// current active update and print krdega
{
	Partition * p = S[currSlot]; // schedule the partition
	clearCurrentSlot();
	while (p != NULL) 
	{
		if (isGameStart) 
		{
			int no = p->getDelay(); // loop through 
			Partition * x = p->getNext();
			if (x != NULL) 
			{
				x->setNext(NULL);
				insert(no, x);
			}
		}
		else {
			cout << "*********************************************************" << endl;
			cout << "Game Ending at Table " << p->getGameTablePointer()->getId() << endl;
			p->getGameTablePointer()->tableplay();
			updateCurrentActivePlayers(-(p->getDelay())); //As delay is equal to number of player subtract these from current Active Player Count
			cout << "Player with ID " << p->getGameTablePointer()->getWinnerId() << " Won with " << p->getGameTablePointer()->getWinnerMice() << " Mice" << endl;
			setMaxMice(p->getGameTablePointer()->getWinnerMice());
			cout << "*********************************************************" << endl;
			file << "*********************************************************" << endl;
			file << "Game Ending at Table " << p->getGameTablePointer()->getId() << endl;
			file << "Player with ID " << p->getGameTablePointer()->getWinnerId() << " Won with " << p->getGameTablePointer()->getWinnerMice() << " Mice" << endl;
			file << "*********************************************************" << endl;
			// actual thing now
			// now pick ID and initialise new game here so new pointer here 
			// new partiton new players new game 
			Partition * W = new Partition(p->getGameTablePointer()->getId());
			updateTotalPlayers(W->getDelay()); //As delay is equal to number of players // update krdiya 
			updateCurrentActivePlayers(W->getDelay()); //As delay is equal to number of players // update krdiya
			insert(W->getDelay(), W); // fir se slot mei insert kr diya 
		}
		p = p->getNext(); 
	}
	currSlot = (currSlot + 1) % MAX_PLAYERS; // current slot ko aage fr krdiya 
	isGameStart = false;// not to execute first 

}

void TimingWheel::clearCurrentSlot()
{
	S[currSlot] = NULL;
}

int TimingWheel::getTotalPlayers()
{
	return totalPlayers;
}

void TimingWheel::updateTotalPlayers(int n)
{
	totalPlayers += n;
}

int TimingWheel::getCurrentActivePlayers()
{
	return currentActivePlayers;
}

void TimingWheel::updateCurrentActivePlayers(int n)
{
	currentActivePlayers += n;
}

void TimingWheel::setMaxMice(int n)
{
	if (maxMice < n) 
		maxMice = n;
}

int TimingWheel::getMaxMice()
{
	return maxMice;
}

void TimingWheel::printCurrentStatus(ofstream & d) 
{
	Partition * p = S[currSlot]; // update current slot update //partiton list looping through 
	while (p != NULL) {
		d << "*********************************************************" << endl;
		d << "Current Time:" << currSlot;
		d << "Currenty Active Players in Arcade" << getCurrentActivePlayers() << endl;
		d << "Total Players in the Arcade till now" << getTotalPlayers() << endl;
		d << "Game going on at Table " << p->getGameTablePointer()->getId() << endl;
		d << "Number of players" << p->getGameTablePointer()->getPlayersNo() << endl;
		d << "Number of mice " << p->getGameTablePointer()->getMiceNo() << " Mice" << endl;
		d << "*********************************************************" << endl;
		p = p->getNext();
	}
}

void TimingWheel::printCurrentStatus() // polymorphic call // overloaded -- one for file -- one for screen
{
	Partition * p = S[currSlot];
	while (p != NULL)
	{
		cout << "*********************************************************" << endl;
		cout << "Current Time: " << currSlot << endl;
		cout << "Currenty Active Players in Arcade: " << getCurrentActivePlayers() << endl;
		cout << "Total Players in the Arcade till now: " << getTotalPlayers() << endl;
		cout << "Maximum Mice Win is with " << getMaxMice() << endl;
		cout << "Game going at Table " << p->getGameTablePointer()->getId() << endl;
		cout << "Number of players" << p->getGameTablePointer()->getPlayersNo() << endl;
		cout << "Number of mice " << p->getGameTablePointer()->getMiceNo() << " Mice" << endl;
		cout << "*********************************************************" << endl;
		p = p->getNext();
	}
}


TimingWheel::~TimingWheel()
{
}
