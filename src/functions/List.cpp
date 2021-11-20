#include <iostream>
#include <cstring>
#include <list>
#include "List.h"
#include "Card.h"

using namespace std;

Card _list::card::findByLabel(list<Card> _list, string _label)
{
    Card emptyCard;
	for (Card _card : _list) {
        if(strcasecmp(_label.c_str(), _card.getLabel().c_str()) == 0)
        {
            return _card;
        }
	}
	return emptyCard;
}

Card _list::card::findByIndex(list<Card> _list, int _index)
{
    Card emptyCard;
    int i = 0;
	for (Card _card : _list) {
        if(i == _index)
        {
            return _card;
        }
        i++;
	}
	return emptyCard;
}

Card _list::card::findByValue(list<Card> _list, int _value)
{
    Card emptyCard;
	for (Card _card : _list) {
        if(_value == _card.getValue())
        {
            return _card;
        }
	}
	return emptyCard;
}

list<Card> _list::card::removeByLabel(list<Card> _list, string _label)
{
	Card card;
	for (Card _card : _list) {
        if(strcasecmp(_label.c_str(), _card.getLabel().c_str()) == 0)
        {
            card = _card;
        }
	}

    _list.remove(card);
    return _list;
}
