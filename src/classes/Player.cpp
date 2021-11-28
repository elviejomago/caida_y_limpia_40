#include "Player.h"

Player::Player()
{
}

Player::Player(string _name)
{
    this->name = _name;
    this->numGames = 0;
    this->winGames = 0;
    this->lostGames = 0;
    initScore();
}

void Player::initScore()
{
    this->score[0][0] = "";
    this->score[0][1] = "";
    this->score[0][2] = "";
    this->score[0][3] = "";
    this->score[1][0] = "";
    this->score[1][1] = "";
    this->score[1][2] = "";
    this->score[1][3] = "";
}

string Player::getName()
{
    return this->name;
}

void Player::addNumGames()
{
    this->numGames++;
}

int Player::getNumGames()
{
    return this->numGames;
}

void Player::addWinGames()
{
    this->winGames++;
}

int Player::getWinGames()
{
    return this->winGames;
}

void Player::addLostGames()
{
    this->lostGames++;
}

int Player::getLostGames()
{
    return this->lostGames;
}

void Player::setInGameCards(list<Card> _cards)
{
    this->inGameCards = _cards;
}

list<Card> Player::getInGameCards()
{
    return this->inGameCards;
}

void Player::addWinCard(Card _card)
{
    this->winCards.push_back(_card);
}

list<Card> Player::getWinCards()
{
    return this->winCards;
}

void Player::resetWinCards()
{
    this->winCards.clear();
}

void Player::addScore(int _score)
{
    if(_score > 0)
    {
        int _coins = _score / 2;
        _coins += this->score[1][0].compare("o") == 0 ? 1 : 0;
        _coins += this->score[1][1].compare("o") == 0 ? 1 : 0;
        _coins += this->score[1][2].compare("o") == 0 ? 1 : 0;
        _coins += this->score[1][3].compare("o") == 0 ? 1 : 0;
        int _dogs = _coins/5;
        _dogs += this->score[0][0].compare("x") == 0 ? 1 : 0;
        _dogs += this->score[0][1].compare("x") == 0 ? 1 : 0;
        _dogs += this->score[0][2].compare("x") == 0 ? 1 : 0;
        _dogs += this->score[0][3].compare("x") == 0 ? 1 : 0;
        initScore();
        if(_dogs > 0)
        {
            for(int i = 0; i < 4; i++)
            {
                if(_dogs > 0 && this->score[0][i].compare("x") != 0)
                {
                    this->score[0][i] = "x";
                    _dogs--;
                    _coins -= 5;
                }
            }
        }
        if(_coins > 0)
        {
            for(int i = 0; i < 4; i++)
            {
                if(_coins > 0 && this->score[1][i].compare("o") != 0)
                {
                    this->score[1][i] = "o";
                    _coins --;
                }
            }
        }
    }
}
