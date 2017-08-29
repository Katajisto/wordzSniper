
#include "stdafx.h"
#include "iostream"
#include <vector>
#include <string>
using namespace std;
int index = 0;
int latestIndex;
//Index of the tiles that have been used in a word
//This is not used at the moment
vector<int> foundIndex = {};
vector<int> nolla = { 1,5,4 };
vector<int> yksi = { 0,4,5,6,2 };
vector<int> kaksi = { 1,5,6,7,3 };
vector<int> kolme = { 2,6,7 };
vector<int> nelja = { 0,1,5,9,8 };
vector<int> viisi = { 0,1,2,6,10,9,8,4 };
vector<int> kuusi = { 1,2,3,7,11,10,9,5 };
vector<int> seitseman = { 2,3,6,10,11 };
vector<int> kahdeksan = { 4,5,9,13,12 };
vector<int> yhdeksan = { 4,5,6,10,14,13,12,8 };
vector<int> kymmenen = { 5,6,7,11,15,14,13,9 };
vector<int> yksitoista = { 6,7,10,14,15 };
vector<int> kaksitoista = { 8,9,13 };
vector<int> kolmetoista = { 12,8,9,10,14 };
vector<int> neljatoista = { 13,9,10,11,15 };
vector<int> viisitoista = { 14,10,11 };
vector<vector<int>> positions = { nolla,yksi,kaksi,kolme,nelja,viisi,kuusi,seitseman,kahdeksan,seitseman,kahdeksan,yhdeksan,kymmenen,yksitoista,kaksitoista,kolmetoista,neljatoista,viisitoista };
vector<char> word = {};
vector<char> grid = {};
vector<int> goodTiles = {};
int gridIndex = 0;
string sana = "hello";
int rangeIndex = 0;
char gridTempChar = ' ';
bool rangeBool = false;
void searchGrid(char letter)
{
	gridIndex = 0;
	for (char tile : grid)
	{
		if (tile == word[0])
		{
			goodTiles.push_back(gridIndex);
		}
		gridIndex++;
	}
}
void getIndex()
{
	latestIndex = goodTiles[0];
}
void showGrid()
{
	cout << "Here is your grid: " << endl;
	for (int x = 0; x <= 3; x++)
	{
		cout << grid[x];
	}
	cout << endl;
	for (int x = 4; x <= 7; x++)
	{
		cout << grid[x];
	}
	cout << endl;
	for (int x = 8; x <= 11; x++)
	{
		cout << grid[x];
	}
	cout << endl;
	for (int x = 12; x <= 15; x++)
	{
		cout << grid[x];
	}
}
void makeGrid()
{
	cout << "Enter the letter and press enter after every letter" << endl;
	cout << "Please enter the letters for the grid!" << endl;
	cout << "Row 1: ";
	for (int count = 1; count <= 4; count++)
	{
		cin >> gridTempChar;
		grid.push_back(gridTempChar);
	}
	cout << "Row 1 set" << endl;
	cout << endl;
	for (int count = 1; count <= 4; count++)
	{
		cin >> gridTempChar;
		grid.push_back(gridTempChar);
	}
	cout << "Row 2 set" << endl;
	cout << endl;
	for (int count = 1; count <= 4; count++)
	{
		cin >> gridTempChar;
		grid.push_back(gridTempChar);
	}
	cout << "Row 3 set" << endl;
	cout << endl;
	for (int count = 1; count <= 4; count++)
	{
		cin >> gridTempChar;
		grid.push_back(gridTempChar);
	}
	cout << endl << "Grid set!" << endl;
}

bool existsInRange(vector<int> pos, char target)
{
	rangeIndex = 0;
	rangeBool = false;
	foundIndex = {};
	for (int i : pos)
	{
		if (grid[i] == target)
		{
			rangeBool = true;
			foundIndex.push_back(pos[rangeIndex]);
 		}
		rangeIndex++;
		
	}
	cout << "Found the reguested chars in the following indexes: " << endl;
	for (int found : foundIndex)
	{
		cout << found << endl;
	}
	return rangeBool;
}
void stringToVector(string var)
{
	for (char letter : var)
	{
		word.push_back(letter);
	}
}
void resetWord()
{
	word = {};
}
bool findWord(string toFind)
{
	int counter = 0;
	stringToVector(toFind);
	searchGrid(word[0]);
	if (goodTiles.empty()) {
		return false;
	}
	else {
		getIndex();
		bool doesExist = false;
		for (char letter : word)
		{
			if (counter != 0)
			{
				doesExist = existsInRange(positions[latestIndex], letter);
				if (doesExist = true)
				{
					latestIndex = counter;
					cout << "Found letter: " << letter << endl;
				}
				if (doesExist = false)
				{
					return false;
				}
			}

			counter++;

		}
		return true;
	}


}
int main()
{
	makeGrid();
	showGrid();
	if (findWord(sana) == true)
	{
		cout << "Found word" << endl;
	}
	else
	{
		cout << "Did not find the word" << endl;
	}
	for (int goodTile : goodTiles)
	{
		cout << goodTile << endl;
	}
	while (true);
}

