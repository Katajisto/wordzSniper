
#include "stdafx.h"
#include "iostream"
#include <vector>
#include <string>
using namespace std;
int index = 0;
//Variable for storing the index of the tile we are currently using
int latestIndex;
//Index of the tiles that have been used in a word
//This is not used at the moment
vector<int> foundIndex = {};
vector<int> found = {};
vector<int> found2 = {};
//Declaring the neighbour tiles to every tile.
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
//A vector with all of the previous vectors
vector<vector<int>> positions = { nolla,yksi,kaksi,kolme,nelja,viisi,kuusi,seitseman,kahdeksan,seitseman,kahdeksan,yhdeksan,kymmenen,yksitoista,kaksitoista,kolmetoista,neljatoista,viisitoista };
//A vector for holding the word
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
	bool exists = false;
	foundIndex = {};
	for (int i : pos)
	{
		if (grid[i] == target)
		{
			latestIndex = i;
			foundIndex.push_back(pos[rangeIndex]);
			
			exists = true;
 		}
		rangeIndex++;
		
	}
	if (exists == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void stringToVector(string var)
{
	word = {};
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
	int foundInt = 0;
	stringToVector(toFind);
	searchGrid(word[1]);
	found2 = {};
	if (goodTiles.empty())
	{
		cout << "ITS EMPTY!!!!" << endl;
		return false;
	}
	cout << "Debug" << endl;
	
	
	for (int tile : goodTiles)
	{
		foundInt = 1;
		cout << "Debug" << endl;
		latestIndex = tile;
		for (int i = 1; i <= word.size(); i++)
		{
			if (existsInRange(positions[latestIndex], word[i - 1]))
			{
				cout << "Foundone" << endl;
				foundInt++;
			}
		}
		if (foundInt == word.size())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}

int main()
{
	int input1;
	char toFind;
	makeGrid();
	showGrid();
	if (findWord("hello"))
	{
		cout << "Found hello" << endl;
	}
	else
	{
		cout << "Didnt find" << endl;
	}
	while(true) {}


}

