#ifndef FUN_SCORING_H_INCLUDED
#define FUN_SCORING_H_INCLUDED

#include <iostream>
#include <list>
#include "Card.h"

using namespace std;

namespace _scoring
{
    int table(list<Card> _tableCards, Card _lastCard, Card _currentCard);
    int roundOrDoubleRound(list<Card> _playerCards);
    int deck(list<Card> _winCards);
}

#endif // FUN_LIST_H_INCLUDED
