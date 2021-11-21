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
