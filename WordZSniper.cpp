﻿/*

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
#include <algorithm>
#include <chrono>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
int index = 0;
int latestIndex;
bool isFirstRun = true;
vector<int> foundIndex = {};
vector<int> usedTiles = {};
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
vector<vector<int>> positions = { nolla,yksi,kaksi,kolme,nelja,viisi,kuusi,seitseman,kahdeksan,yhdeksan,kymmenen,yksitoista,kaksitoista,kolmetoista,neljatoista,viisitoista };
vector<char> word = {};
vector<char> grid = {};
vector<int> goodTiles = {};
string sana = "hello";
vector<int> startPos = {};
char gridTempChar = ' ';
bool rangeBool = false;
bool searchGrid(char letter)
{
	goodTiles = {};
	bool didFind = false;
	int gridIndex = 0;
	for (char tile : grid)
	{
		if (tile == letter)
		{
			goodTiles.push_back(gridIndex);
			didFind = true;
		}
		gridIndex++;
	}
	return didFind;
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
	cout << endl;
	cout << endl;
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
	grid = {};
	word = {};
	goodTiles = {};
}
void apv(int x, char y, vector<int>& z)
{
	for (int a : positions[x])
	{
		if (grid[a] == y)
		{
			z.push_back(a);
		}
	}
}
bool isInUse(int i, vector<int>& usedVector)
{
	for (int num : usedVector)
	{
		if (num == i)
		{
			return true;
		}
	}
	return false;
}
bool betterFind(string target)
{
	stringToVector(target);
	vector<int> used = { 42,42,42,42,42,42,42,42,42,42 };
	vector<int> a = {};
	vector<int> b = {};
	vector<int> c = {};
	vector<int> d = {};
	vector<int> e = {};
	vector<int> f = {};
	vector<int> g = {};
	vector<int> h = {};
	vector<int> i = {};
	vector<int> j = {};
	vector<int> k = {};
	searchGrid(word[0]);
	for (int tile1 : goodTiles)
	{
		a = {};
		b = {};
		c = {};
		d = {};
		e = {};
		f = {};
		g = {};
		h = {};
		i = {};
		j = {};
		k = {};
		if (word.size() == 1)
		{
			return true;
		}
		apv(tile1, word[1], a);
		used[0] = tile1;
		for (int tile2 : a)
		{
			if (!isInUse(tile2,used)) {
				used[1] = tile2;
				if (word.size() == 2)
				{
					return true;
				}
				apv(tile2, word[2], b);
				for (int tile3 : b)
				{
					if (!isInUse(tile3, used)) {
					used[2] = tile3;
					if (word.size() == 3)
					{
						return true;
					}
					apv(tile3, word[3], c);
					for (int tile4 : c)
					{
						if (!isInUse(tile4, used)) {
							used[3] = tile4;
							if (word.size() == 4)
							{
								return true;
							}
							apv(tile4, word[4], d);
							for (int tile5 : d)
							{
								if (!isInUse(tile5, used)) {
									used[4] = tile5;
									if (word.size() == 5)
									{
										return true;
									}
									apv(tile5, word[5], e);
									for (int tile6 : e)
									{
										if (!isInUse(tile6, used)) {
											used[5] = tile6;
											if (word.size() == 6)
											{
												return true;
											}
											apv(tile6, word[6], f);
											for (int tile7 : f)
											{
												if (!isInUse(tile7, used)) {
													used[6] = tile7;
													if (word.size() == 7)
													{
														return true;
													}

													apv(tile7, word[7], g);
													for (int tile8 : g)
													{
														if (!isInUse(tile8, used)) {
															used[7] = tile8;
															if (word.size() == 8)
															{
																return true;
															}
															apv(tile8, word[8], h);
															for (int tile9 : h)
															{
																if (!isInUse(tile9, used)) {
																	used[8] = tile9;
																	if (word.size() == 9)
																	{
																		return true;
																	}
																	apv(tile9, word[9], k);
																	for (int tile10 : k)
																	{
																		if (!isInUse(tile10, used))
																		{
																			used[9] = tile10;
																			if (word.size() == 10)
																			{
																				return true;
																			}
																		}
																	}
																}
															}
														}

													}
												}

											}
										}
									}
								}
							}
						}
					}
					}
				}
			}
		}
	}
}
//Well this main function is just self explanatory.
int main()
{
	if (isFirstRun)
	{
		cout << "Welcome to Sanajahti Sniper!" << endl;
		cout << "Programmed by Tuomas Katajisto" << endl;
		cout << "-------------------------------" << endl;
		cout << "Instructions: " << endl;
		cout << "The program will ask you for the rows of the grid, you can enter the whole grid at a time, or one row at a time." << endl;
		cout << "Please use \" for ä, and @ for ö, if you can't see the letters look at the readme file." << endl;
		cout << "DISCLAIMER: Please don't ruin the leaderboards with this, it's no fun" << endl;
	}
	isFirstRun = false;
	::std::locale d_Locale2("swedish");
	::std::locale::global(d_Locale2);
	std::string temp;
	vector<string> foundWords = {};
	string input1;
	char toFind;
	makeGrid();
	int i = 0;
	showGrid();
	auto start = std::chrono::steady_clock::now();
	std::ifstream file("dictionary_fin.katajisto");
	while (std::getline(file, temp))
	{
		if (betterFind(temp) == true)
		{
			foundWords.push_back(temp);
		}
	}
	struct compare {
		bool operator()(const std::string& first, const std::string& second) {
			return first.size() < second.size();
		}
	};
	compare c;
	std::sort(foundWords.begin(), foundWords.end(), c);
	for (string foundWord : foundWords)
	{
		cout << foundWord << endl;
	}
	auto finish = std::chrono::steady_clock::now();
	cout << "Done!" << endl;
	double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start).count();
	std::cout << elapsed_seconds << endl;
	cout << "Ready!" << endl;
	cout << "Do you want to find words in a new grid? (y/N): ";
	char input2;
	cin >> input2;
	if(input2 == 'y' || input2 == 'Y')
	{
		resetWord();
		main();
	}
	else
	{
		return 0;
	}
	
}
