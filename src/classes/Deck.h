#pragma once

#include <iostream>
#include "Card.h"

using namespace std;

class Deck {
private:
    Card cards[4][10];
    char visibleCards[4][10];

    void initCards();
    void initVisibleCards();
public:
	Deck();
	char getVisibleCard(int _row, int _column);
	void dealCards(int _round);
	void shufflingCards();
	void resetDeck();
};

