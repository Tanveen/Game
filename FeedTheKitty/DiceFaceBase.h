#pragma once
#include<iostream>
#include<cstring>
// #include "DiceFaceVirtual.h"

using namespace std;
class DiceFaceBase 
{
public:
	DiceFaceBase();
	
		string color;
		string symbol;
	
		DiceFaceBase(string c, string s);
		string getColor();
		string getSymbol();
		virtual void display();
		~DiceFaceBase();
	};



