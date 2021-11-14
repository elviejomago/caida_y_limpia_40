#pragma once

#include <iostream>

using namespace std;

class Card {
private:
    int value;
    char type;
    string label;
public:
    Card();
	Card(int _value, char _type);
	bool operator == (const Card& c) const { return value == c.value && type == c.type; }
	int getValue();
	char getType();
	string getLabel();
};
