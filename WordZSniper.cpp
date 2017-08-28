// WordZSniper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <vector>
using namespace std;
vector<char> word = { 'n','e','k','r' };
vector<char> row1 = { '1','a','a','n' };
vector<char> row2 = { '3','a','a','e' };
vector<char> row3 = { '3','a','a','k' };
vector<char> row4 = { '7','a','a','r' };
int index = 0;
int main()
{

	for (char letter : row1)
	{
		if (letter == word[0])
		{
			
			if (row2[index] == word[1])
			{
				cout << "Found:" << word[1] << endl;
				if (row3[index] == word[2])
				{
					cout << "Found:" << word[2] << endl;
					if (row4[index] == word[3])
					{
						cout << "Found all of it" << endl;
					}
				}
			}
		}
		++index;
	}
	while (true) {}
}

