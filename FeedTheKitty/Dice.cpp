#include "Dice.h"
#include<time.h>
#include "GreenArrow.h"
#include "GreenBowl.h"
#include "GreenMouse.h"
#include "GreenSleepingCat.h"
#include "RedArrow.h"
#include "RedBowl.h"
#include "RedMouse.h"
#include "RedSleepingCat.h"	

		Dice::Dice()
		{
		}
		string Dice::getColor(int n, vector<string> color, vector<int> colorMap)
		{
			for (int i = 0; i < color.size(); i++)
			{
				if (n <= colorMap[i]) return color[i];
			}
			//return string();
		}
		string Dice::getSymbol(int n, vector<string> symbol, vector<int> symbolMap)
		{
			for (int i = 0; i < symbol.size(); i++)
			{
				if (n <= symbolMap[i]) return symbol[i];
			}
			//return string();
		}
		void Dice::setFaces(int f, vector<string> color, vector<string> symbol, vector<int> colorMap, vector<int> symbolMap)
		{
			faces = f;
			int rd; // 1- 100 
			// get color get symbol - map - tells us what color what symbol
			srand(time(NULL)); // current time se kiya initialise
			string cl, sym;
			DiceFaceBase * d; // dicefacebase pointer
			for (int i = 0; i < faces; i++)  // loop through the faces whihc are 6 
			{
				rd = (rand() % 100) + 1;
				cl = getColor(rd, color, colorMap); // set the color according to the map 
				sym = getSymbol(rd, symbol, symbolMap); // sam ewith the symbol
				// what object 
				if (cl == "Green" && sym == "SleepingCat") 
				{
					d = new GreenSleepingCat();
				}
				if (cl == "Green" && sym == "Arrow") 
				{
					d = new GreenArrow();
				}
				if (cl == "Green" && sym == "Mouse") 
				{
					d = new GreenMouse();
				}
				if (cl == "Green" && sym == "Bowl") 
				{
					d = new GreenBowl();
				}
				if (cl == "Red" && sym == "SleepingCat") 
				{
					d = new RedSleepingCat();
				}
				if (cl == "Red" && sym == "Arrow")
			    {
					d = new RedArrow();
				}
				if (cl == "Red" && sym == "Mouse") 
				{
					d = new RedMouse();
				}
				if (cl == "Red" && sym == "Bowl") 
				{
					d = new RedBowl();
				}
				F.push_back(d); // vector push
			}
		}


	

DiceFaceBase Dice::roll()
{ 
	int rd = (rand() % 6) + 1; // faces- hardcorded
	DiceFaceBase * DF = F[rd - 1]; // 0-5 random - corresponding faces fetch all and return one niche wli statement mei
	return (*DF); // return the one corresponding face
}
Dice::~Dice()
{
}
