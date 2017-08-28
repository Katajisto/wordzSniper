
#include "stdafx.h"
#include "iostream"
#include <vector>
#include <string>
using namespace std;
int index = 0;

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
vector<char> grid = { 'a', 'x','x','x','u','z','x','x','t','x','x','x','i','x','x','x' };
string sana = "Hur Dur";
int rangeIndex = 0;
bool rangeBool = false;
bool existsInRange(vector<int> pos, char target)
{
	rangeIndex = 0;
	rangeBool = false;
	for (int i : pos)
	{
		if (grid[i] == target)
		{
			cout << "Found " << target << " at index " << pos[rangeIndex] << endl;
			rangeBool = true;
 		}
		rangeIndex++;
	}
	return rangeBool;
}
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
	
	existsInRange(positions[1], 'z');
	while (true);
}

