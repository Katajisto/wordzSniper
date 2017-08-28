/*
Sanajahti Sniper. Programmed by Tuomas Katajisto. WORK IN PROGRESS.
*/
#include "stdafx.h"
#include "iostream"
#include <vector>
#include <string>
using namespace std;
int index = 0;
vector<char> word = {};
vector<char> grid = { 'a', 'x','x','x','u','x','x','x','t','x','x','x','i','x','x','x' };
string sana = "Hur Dur";
bool isNear(int index, char letter)
{
	cout << "The current letter is" << grid[index] << endl;
	if (index - 1 > 0 && index + 1 < 16)
	{
		cout << "next to it are the letters: " << grid[index - 1] << " & " << grid[index + 1] << endl;
	}
	return true;
}
void stringToVector(string var)
{
	for (char letter : var)
	{
		word.push_back(letter);
	}
}
int main()
{
	stringToVector(sana);
	for (char x : word)
	{
		cout << x << endl;
	}
	isNear(3, 'h');
	while (true);
}

