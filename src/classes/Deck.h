#pragma once

#include <iostream>
#include <list>
#include "Card.h"

using namespace std;

class Deck {
private:
    int rounds;
    Card cards[4][10];
    char visibleCards[4][10];

    void initCards();
    void initVisibleCards();
public:
	Deck();
	void addRounds();
	void resetRounds();
	int getRounds();
	char getVisibleCard(int _row, int _column);
	list<Card> dealCards(int _round, bool _isFirstPlayer);
	void shufflingCards();
	void resetDeck();
};

