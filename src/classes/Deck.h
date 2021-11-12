#pragma once

#include <iostream>
#include "Card.h"

using namespace std:

class Deck {
private:
    vector<Card> cards(40);
public:
	Deck();
	void dealCards();
	void shufflingCards();
	void resetDeck();
};

