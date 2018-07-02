#include "Player.h"
#include <iostream>
#include <cstring>

using namespace std;
Player::Player(int ID, int mice)
{
	id = ID;
	mouse = mice;
	isActive = true;
	isWinner = false;
}

int Player::getID()
{
	return id;
}

void Player::setActive()
{
	isActive = true;
}

void Player::setInActive()
{
	isActive = false;
}

void Player::setWinner()
{
	isWinner = true;
}

bool Player::isPlayerActive()
{

	return isActive;
}

bool Player::isPlayerWinner()
{
	return isWinner;
}

void Player::giveMouse()
{
	if (mouse > 0)
	{
		mouse--;
	}
	if (mouse == 0) {
		setInActive();
	}
}

void Player::takeMouse()
{
	mouse++;
	if (mouse > 0)
	{
		setActive();
	}
}

int Player::getMiceNo()
{
	return mouse;
}

void Player::displayDetails()
{
	cout << "ID:" << id << endl;
	cout << "Mice:" << mouse << endl;
	if (isActive)
	{
		cout << "Status:Active"; // status
	}
	else
	{
		cout << "Status:Inactive";
		cout << endl;
	}
}

Player::Player()
{
}


Player::~Player()
{
}
