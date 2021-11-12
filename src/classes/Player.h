#pragma once
#include<iostream>

using namespace std;

class Player
{
private:
	string name;
	int numGames;
	int winGames;
	int lostGames;
public:
	Player();
	Player(string _name);
	string getName();
	void addNumGames();
	int getNumGames();
	void addWinGames();
	int getWinGames();
	void addLostGames();
	int getLostGames();
};

