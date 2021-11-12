#include <iostream>
#include "Card.h"
#include "../enums/TypeCard.h"

using namespace std;

Card::Card(int _value, TypeCard _type)
{
    this->value = _value;
    this->type = _type;
}
