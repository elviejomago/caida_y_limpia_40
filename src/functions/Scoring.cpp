#include <algorithm>
#include <list>
#include "Scoring.h"

int _scoring::table(list<Card> _tableCards, Card _lastCard, Card _currentCard)
{
    if(_lastCard.getValue() == _currentCard.getValue() || _tableCards.size() == 0)
    {
        return 2;
    }
    return 0;
}

int _scoring::roundOrDoubleRound(list<Card> _playerCards)
{
    list<int> _evaluateCards;
    for(Card _card : _playerCards)
    {
        bool _found = (std::find(_evaluateCards.begin(), _evaluateCards.end(), _card.getValue()) != _evaluateCards.end());
        if(!_found)
        {
            _evaluateCards.push_back(_card.getValue());
        }
    }
    return _evaluateCards.size() == 3 ? 2 :
        _evaluateCards.size() == 2 ? 40 : 0;
}

int _scoring::deck(list<Card> _winCards)
{
    int _minCard = 19;
    int _minScore = 6;
    if(_winCards.size() > _minCard)
    {
        int _diffCards = _winCards.size() - _minCard;
        int _plusPoints = _diffCards - 1;
        int _score = _minScore + _plusPoints;
        if(_score % 2 != 0)
        {
            _score += 1;
        }
        return _score;
    }
    return 0;
}
