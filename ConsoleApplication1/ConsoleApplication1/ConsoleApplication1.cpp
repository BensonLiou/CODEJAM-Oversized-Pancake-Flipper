// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define PREFIX "Case #%d: "

void saveAnsToFile(ofstream& of, int numOfFlipper, int tcCount )
{
	char tmpAns[100];
	sprintf(tmpAns, PREFIX, tcCount);
	if (numOfFlipper < 0)
		of << tmpAns << "IMPOSSIBLE" << endl;
	else
		of << tmpAns << numOfFlipper << endl;
}

char doFlip(char a) 
{
	return a == '-' ? '+' : '-';
}

int main()
{
	ifstream in("A-small-practice.in");
	ofstream ansFile("ans.txt");
	string pancakes;
	string sFlipper;
	long tc = 0;
	int ans = 0;
	int flipperSize = 0;       // size of flipper
	int numOfFlipper = 0; // how many times of flipping
	int tcCount = 0;
	int loop;

	if (in.is_open())
	{
		getline(in, pancakes);// it's the information of number of test cases
		loop = stoi(pancakes);
		for(tcCount =1; tcCount <= loop; tcCount++)
		{
			getline(in, pancakes, ' ');
			getline(in, sFlipper);
			flipperSize = stoi(sFlipper);			
			numOfFlipper = 0;
							
			for (int i = 0; i <= pancakes.length()- flipperSize; i++)
			{
				if (pancakes[i] == '-')
				{
					for(int j = 0; j < flipperSize;j++)
						pancakes[i+j] = doFlip(pancakes[i+j]);
					
					numOfFlipper++;
				}
			}

			for (int i = pancakes.length() - flipperSize; i < pancakes.length(); i++)
			{
				if (pancakes[i] == '-')
					numOfFlipper = -1;
			}

			saveAnsToFile(ansFile, numOfFlipper, tcCount);
						
		}
	}
	system("pause");
	return 0;
}

