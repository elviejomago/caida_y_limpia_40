#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "../constants/TypeCard.h"

using namespace std;

Deck::Deck()
{
    initCards();
    initVisibleCards();
}

char Deck::getVisibleCard(int _row, int _column)
{
    return this->visibleCards[_row][_column];
}

void Deck::dealCards(int _round)
{
    for(int i = 0; i < 5; i++)
    {
        this->visibleCards[_round][i] = StatusCard::IN_GAME;
    }

    for(int i = 5; i < 10; i++)
    {
        this->visibleCards[_round][i] = StatusCard::IN_GAME;
    }

}

void Deck::initCards()
{
    this->cards[0][0] = Card(1, TypeCard::CLOVER);
    this->cards[0][1] = Card(2, TypeCard::CLOVER);
    this->cards[0][2] = Card(3, TypeCard::CLOVER);
    this->cards[0][3] = Card(4, TypeCard::CLOVER);
    this->cards[0][4] = Card(5, TypeCard::CLOVER);
    this->cards[0][5] = Card(6, TypeCard::CLOVER);
    this->cards[0][6] = Card(7, TypeCard::CLOVER);
    this->cards[0][7] = Card(11, TypeCard::CLOVER);
    this->cards[0][8] = Card(12, TypeCard::CLOVER);
    this->cards[0][9] = Card(13, TypeCard::CLOVER);

    this->cards[1][0] = Card(1, TypeCard::BLACK);
    this->cards[1][1] = Card(2, TypeCard::BLACK);
    this->cards[1][2] = Card(3, TypeCard::BLACK);
    this->cards[1][3] = Card(4, TypeCard::BLACK);
    this->cards[1][4] = Card(5, TypeCard::BLACK);
    this->cards[1][5] = Card(6, TypeCard::BLACK);
    this->cards[1][6] = Card(7, TypeCard::BLACK);
    this->cards[1][7] = Card(11, TypeCard::BLACK);
    this->cards[1][8] = Card(12, TypeCard::BLACK);
    this->cards[1][9] = Card(13, TypeCard::BLACK);

    this->cards[2][0] = Card(1, TypeCard::DIAMOND);
    this->cards[2][1] = Card(2, TypeCard::DIAMOND);
    this->cards[2][2] = Card(3, TypeCard::DIAMOND);
    this->cards[2][3] = Card(4, TypeCard::DIAMOND);
    this->cards[2][4] = Card(5, TypeCard::DIAMOND);
    this->cards[2][5] = Card(6, TypeCard::DIAMOND);
    this->cards[2][6] = Card(7, TypeCard::DIAMOND);
    this->cards[2][7] = Card(11, TypeCard::DIAMOND);
    this->cards[2][8] = Card(12, TypeCard::DIAMOND);
    this->cards[2][9] = Card(13, TypeCard::DIAMOND);

    this->cards[3][0] = Card(1, TypeCard::RED);
    this->cards[3][1] = Card(2, TypeCard::RED);
    this->cards[3][2] = Card(3, TypeCard::RED);
    this->cards[3][3] = Card(4, TypeCard::RED);
    this->cards[3][4] = Card(5, TypeCard::RED);
    this->cards[3][5] = Card(6, TypeCard::RED);
    this->cards[3][6] = Card(7, TypeCard::RED);
    this->cards[3][7] = Card(11, TypeCard::RED);
    this->cards[3][8] = Card(12, TypeCard::RED);
    this->cards[3][9] = Card(13, TypeCard::RED);
}

void Deck::initVisibleCards()
{
    this->visibleCards[0][0] = StatusCard::IN_DECK;
    this->visibleCards[0][1] = StatusCard::IN_DECK;
    this->visibleCards[0][2] = StatusCard::IN_DECK;
    this->visibleCards[0][3] = StatusCard::IN_DECK;
    this->visibleCards[0][4] = StatusCard::IN_DECK;
    this->visibleCards[0][5] = StatusCard::IN_DECK;
    this->visibleCards[0][6] = StatusCard::IN_DECK;
    this->visibleCards[0][7] = StatusCard::IN_DECK;
    this->visibleCards[0][8] = StatusCard::IN_DECK;
    this->visibleCards[0][9] = StatusCard::IN_DECK;

    this->visibleCards[1][0] = StatusCard::IN_DECK;
    this->visibleCards[1][1] = StatusCard::IN_DECK;
    this->visibleCards[1][2] = StatusCard::IN_DECK;
    this->visibleCards[1][3] = StatusCard::IN_DECK;
    this->visibleCards[1][4] = StatusCard::IN_DECK;
    this->visibleCards[1][5] = StatusCard::IN_DECK;
    this->visibleCards[1][6] = StatusCard::IN_DECK;
    this->visibleCards[1][7] = StatusCard::IN_DECK;
    this->visibleCards[1][8] = StatusCard::IN_DECK;
    this->visibleCards[1][9] = StatusCard::IN_DECK;

    this->visibleCards[2][0] = StatusCard::IN_DECK;
    this->visibleCards[2][1] = StatusCard::IN_DECK;
    this->visibleCards[2][2] = StatusCard::IN_DECK;
    this->visibleCards[2][3] = StatusCard::IN_DECK;
    this->visibleCards[2][4] = StatusCard::IN_DECK;
    this->visibleCards[2][5] = StatusCard::IN_DECK;
    this->visibleCards[2][6] = StatusCard::IN_DECK;
    this->visibleCards[2][7] = StatusCard::IN_DECK;
    this->visibleCards[2][8] = StatusCard::IN_DECK;
    this->visibleCards[2][9] = StatusCard::IN_DECK;

    this->visibleCards[3][0] = StatusCard::IN_DECK;
    this->visibleCards[3][1] = StatusCard::IN_DECK;
    this->visibleCards[3][2] = StatusCard::IN_DECK;
    this->visibleCards[3][3] = StatusCard::IN_DECK;
    this->visibleCards[3][4] = StatusCard::IN_DECK;
    this->visibleCards[3][5] = StatusCard::IN_DECK;
    this->visibleCards[3][6] = StatusCard::IN_DECK;
    this->visibleCards[3][7] = StatusCard::IN_DECK;
    this->visibleCards[3][8] = StatusCard::IN_DECK;
    this->visibleCards[3][9] = StatusCard::IN_DECK;

}
