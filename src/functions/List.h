#ifndef FUN_LIST_H_INCLUDED
#define FUN_LIST_H_INCLUDED

#include <iostream>
#include <list>
#include "Card.h"

using namespace std;

namespace _list
{
    namespace card
    {
        Card findByLabel(list<Card> _listCards, string _label);
        list<Card> removeByLabel(list<Card> _listCards, string _label);
    }
}

#endif // FUN_LIST_H_INCLUDED
