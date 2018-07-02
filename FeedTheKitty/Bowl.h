#pragma once
class Bowl
{
	int mouse;
	
public:
	Bowl(); // initialise mouse done because  
	void update(int n);
	bool isEmpty();
	void addMouse();
	void remove();
	~Bowl();
};

