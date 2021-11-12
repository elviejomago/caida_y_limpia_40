#pragma once

#include <iostream>
#include "../enums/TypeCard.h"

using namespace std;

class Card {
private:
    int value;
    TypeCard type;
    string label;
public:
	Card(int _value, TypeCard _type);
	int getValue();
	TypeCard getType();
	string getLabel();
};
