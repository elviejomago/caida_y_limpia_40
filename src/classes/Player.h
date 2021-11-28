#pragma once
#include <iostream>
#include <list>
#include <array>
#include "Card.h"

using namespace std;

class Player
{
private:
	string name;
	int numGames;
	int winGames;
	int lostGames;
	list<Card> winCards;
	list<Card> inGameCards;
public:
	string score[2][4];

	Player();
	Player(string _name);
	void initScore();
	string getName();
	void addNumGames();
	int getNumGames();
	void addWinGames();
	int getWinGames();
	void addLostGames();
	int getLostGames();
	void addWinCard(Card _card);
	list<Card> getWinCards();
	void resetWinCards();
	void setInGameCards(list<Card> _cards);
	list<Card> getInGameCards();
	void addScore(int _score);
};

