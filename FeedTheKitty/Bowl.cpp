#include "Bowl.h"


Bowl::Bowl()
{
	mouse = 3; // so that bowl remains not empty in nay case // hard coded 
}

void Bowl::update(int n)
{
	mouse = n; // 
}

bool Bowl::isEmpty()
{
	return (mouse == 0); // bowl empty or not // not using though :P 
}

void Bowl::addMouse()
{
	mouse++;
}

void Bowl::remove()
{
	mouse--;
}


Bowl::~Bowl()
{
}
