/*
		  _______  _______  ______   _______    _______  _       _________ _______  _______  _______
|\     /|(  ___  )(  ____ )(  __  \ / ___   )  (  ____ \( (    /|\__   __/(  ____ )(  ____ \(  ____ )
| )   ( || (   ) || (    )|| (  \  )\/   )  |  | (    \/|  \  ( |   ) (   | (    )|| (    \/| (    )|
| | _ | || |   | || (____)|| |   ) |    /   )  | (_____ |   \ | |   | |   | (____)|| (__    | (____)|
| |( )| || |   | ||     __)| |   | |   /   /   (_____  )| (\ \) |   | |   |  _____)|  __)   |     __)
| || || || |   | || (\ (   | |   ) |  /   /          ) || | \   |   | |   | (      | (      | (\ (
| () () || (___) || ) \ \__| (__/  ) /   (_/\  /\____) || )  \  |___) (___| )      | (____/\| ) \ \__
(_______)(_______)|/   \__/(______/ (_______/  \_______)|/    )_)\_______/|/       (_______/|/   \__/

Programmed by: Tuomas Katajisto
Website: ktj.st
Email: t@ktj.st

My first proper C++ program
It finds words in a 4 x 4 grid.
*/
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
vector<vector<int>> positions = { nolla,yksi,kaksi,kolme,nelja,viisi,kuusi,seitseman,kahdeksan,yhdeksan,kymmenen,yksitoista,kaksitoista,kolmetoista,neljatoista,viisitoista };
//A vector for holding the word
vector<char> word = {};
//A vector for holding the grid
//vector<char> grid = {'s','o','s','e','u','a','i','k','a','t','t','l','a','m','v','m'};
vector<char> grid = {};
//A vector for holding the tiles that hold the starting letter of the word.
vector<int> goodTiles = {};
//A string that holds the word, before it is split into chars in a vector
string sana = "hello";
//A vector that holds the starting positions of a word
vector<int> startPos = {};
//A temporary place for a char from the grid
char gridTempChar = ' ';
//A bool that is used in a function and is also needed (atleast was) elsewhere
bool rangeBool = false;
//Search the whole grid for a letter
bool startSearch()
{
	bool didFind = false;
	int index = 0;
	for (char letter : grid)
	{
		if (letter == word[0])
		{
			didFind = true;
			startPos.push_back(index);
		}
	index++;
	}
	return didFind;
}
bool searchGrid(char letter)
{
	//Resetting the goodTiles vector that holds the tiles that share the character reguested
	goodTiles = {};
	bool didFind = false;
	//Current place in the grid
	int gridIndex = 0;
	//For every char in the grid
	for (char tile : grid)
	{
		//if the char is the same as the letter reguested.
		if (tile == letter)
		{
			//Add it to the vector with all of the tiles containing the first letter
			goodTiles.push_back(gridIndex);
			didFind = true;
		}
		//Add 1 to the grid index
		gridIndex++;
		//Tell my findWord() function if this function found a word.
		
	}
	return didFind;
}
//Show the grid. Only for UI purposes.
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
	cout << endl;
	cout << endl;
}
//Get user input for the grid.
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
//Check if a character is in a position in the grid that is listed in a vector
bool existsInRange(vector<int> pos, char target)
{
	int rangeIndex = 0;
	bool exists = false;
	foundIndex = {};
	//For every position stored in that vector
	for (int i : pos)
	{
		//If the certain characted is in that position in the grid
		if (grid[i] == target)
		{
			//Tell the index of it to the findWord() function
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
//Chop up a string into chars and put them into a vector
void stringToVector(string var)
{
	word = {};
	for (char letter : var)
	{
		word.push_back(letter);
	}
}
//Reset the word, not currently used
void resetWord()
{
	word = {};
	found = {};
	found2 = {};
	goodTiles = {};
}
//Redoing the findWord fuction to use new logic
//This time it will check if a letter exists, then check if it is in the neighbour vector of the latest tile.
//It will make the program run slower, but I can probably make it work better.
//Will probably revisit this program sometime to make the original function work.
bool findWord(string toFind)
{
	bool foundChar = false;
	bool isFirstRun = true;
	int tempTile;
	int foundCharacters = 0;
	int wordSize = word.size();
	//Converting the provided string to a vector, then putting it into the word vector.
	stringToVector(toFind);
	//Does the char exist in the grid
	if (startSearch() == true)
	{
		//For every index of a tile that has the character
		for (int tile : startPos)
		{
			isFirstRun = true;
			tempTile = tile;
			for (char curChar : word)
			{
				foundChar = false;
				//Skip the word[0]
				if (isFirstRun == true)
				{
					isFirstRun = false;
				}
				else
				{
					if (searchGrid(curChar) == true)
					{
						for (int pos : goodTiles)
						{
							for (int goodPos : positions[tempTile])
							{
								if (pos == goodPos)
								{
									//FOUND THE CHAR 
									//cout << "Found " << curChar << endl;
									tempTile = pos;
									foundCharacters++;
									break;
								}
								else
								{
									//Haven't found it yet
								}
							}
						}
					}
					else
					{
						return false;
					}

				}
			}
			if (foundCharacters + 1 == word.size())
			{
				//cout << "Found this many characters: " << foundCharacters << endl;
				return true;
			}
		}
		return false;
	}
	//If the char doesnt exist, just exit the function, the word is not going to be there...
	else
	{
		return false;
	}
}
/*
This was the hardest function to write. It finds if a word can be found from the grid.
*/
/*
bool findWord(string toFind)
{
	int foundInt = 0;
	//Convert the word into a vector
	stringToVector(toFind);
	//search the grid for the first letter of that word
	searchGrid(word[0]);
	found2 = {};
	//Making sure that if the first letter doesnt exist in the grid the program doesn't crash
	if (goodTiles.empty())
	{
		//Just for debugging
		//cout << "ITS EMPTY!!!!" << endl;
		return false;
	}
	//cout << "Debug" << endl;
	
	//for every tile that has the first letter in it.
	for (int tile : goodTiles)
	{
		cout << "Found a tile with starting letter: " << grid[tile] << endl;
		foundInt = 1;
		//cout << "Debug" << endl;
		//making sure that it stops searching when all the letters have been found
		latestIndex = tile;
		for (int i = 1; i <= word.size(); i++)
		{
			//checking if the next letter is next to the current letter
			if (existsInRange(positions[latestIndex], word[i - 1]))
			{
				cout << "Found letter: " << word[i - 1] << " at index " << latestIndex << endl;
				//cout << "Foundone" << endl;
				foundInt++;
			}
		}

	}
	return true;
}
*/
//Well this main function is just self explanatory.
int main()
{
	string input1;
	char toFind;
	makeGrid();
	int i = 0;
	showGrid();
	/*
	for (vector<int> systeemi : positions)
	{
		cout << "Here are the pos of vector pos: " << i << endl;
		for (int pos : systeemi)
		{
			cout << pos << ", " << endl;
		}
		cout << endl;
		i++;
	}
	*/
	while(true) 
	{
		cout << "Word to find:" << endl;
		cin >> input1;
		cout << endl;
		if (findWord(input1) == true)
		{
			cout << input1 << endl;
		}
		resetWord();

	}


}

