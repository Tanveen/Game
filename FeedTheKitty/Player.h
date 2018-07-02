#pragma once
class Player
{ 
	int id; // to identify player
	int mouse;
	bool isActive; // if mouse =0 then player inactive
	bool isWinner;
public:
	Player(int ID, int mice); // initialise them 
	// getter // setter // private members not directly accessible 
	int getID();
	void setActive();
	void setInActive();
	void setWinner();
	bool isPlayerActive();
	bool isPlayerWinner();
	void giveMouse();
	void takeMouse();
	int getMiceNo();
	void displayDetails();
	Player();
	~Player();
};

