#include <iostream>
#include <sstream>
#include "Card.h"

using namespace std;

Card::Card()
{
    this->value = -1;
}

Card::Card(int _value, char _type)
{
    this->value = _value;
    this->type = _type;
}

int Card::getValue()
{
    return this->value;
}

char Card::getType()
{
    return this->type;
}

string Card::getLabel()
{
    stringstream ss;
    switch(this->value)
    {
    case 11:
        ss << "J" << this->type ;
        return  ss.str();

    case 12:
        ss << "Q" << this->type ;
        return  ss.str();

    case 13:
        ss << "K" << this->type ;
        return  ss.str();

    default:
        ss << this->value << this->type ;
        return  ss.str();
    }
}
