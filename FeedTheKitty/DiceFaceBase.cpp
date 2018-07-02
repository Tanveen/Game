#include "DiceFaceBase.h"
#include<string>
using namespace std;
DiceFaceBase::DiceFaceBase()
{
}

DiceFaceBase::DiceFaceBase(string c, string s)
{
	color = c;
	symbol = s;
}

string DiceFaceBase::getColor()
{
	return color;
}

string DiceFaceBase::getSymbol()
{
	return symbol;
}

void DiceFaceBase::display()
{
	cout << color << "-" << symbol;
}

DiceFaceBase::~DiceFaceBase()
{
}
