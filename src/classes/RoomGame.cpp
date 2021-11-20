#include <iostream>
#include <list>
#include <cstring>
#include <sstream>
#include<stdlib.h>
#include<time.h>
#include "RoomGame.h"
#include "Header.h"
#include "../functions/Display.h"
#include "../constants/Positions.h"
#include "../constants/Constants.h"
#include "../functions/List.h"

using namespace std;

RoomGame::RoomGame() :Screen("Room Game", "S003") {}

RoomGame::RoomGame(Player _player) :Screen("Room Game", "S003")
{
    init(_player);
    renderRoom();
    startGame();
}

void RoomGame::init(Player _player)
{
    Header _header;
    Deck _deck;
    Player _systemPlayer;
    this->deck = _deck;
    this->realPlayer = _player;
    this->systemPlayer = _systemPlayer;
}

void RoomGame::drawDeckOnRoom()
{
    int _x = P_DECK::x;
    int _y = P_DECK::y;
    text::printTextPosition("B A R A J A S", P_DECK::x + 12, P_DECK::y - 2);
    for(int i = 0; i < 4; i++)
    {
        _y += i;
        for(int j = 0; j < 10; j++)
        {
            _x += 3;
            stringstream ss;
            ss << "|" << this->deck.getVisibleCard(i, j) << "|";
            text::printTextPosition("---", _x, P_DECK::y - 1);
            text::printTextPosition(ss.str(), _x, _y);
            _y++;
            text::printTextPosition("---", _x, _y);
            _y--;
        }
        _x = P_DECK::x;
        _y = P_DECK::y + i + 1;
    }
}

void RoomGame::drawRealPlayerArea()
{
    int _x = P_REAL_PLAYER_AREA::x;
    int _y = P_REAL_PLAYER_AREA::y;
    text::printTextColorPos(this->realPlayer.getName(), _x, _y, Colors::GREEN);
    text::printTextColorPos("--------", _x, ++_y, Colors::GREEN);
    text::printTextColorPos("|      |", _x, ++_y, Colors::GREEN);
    text::printTextColorPos("|      |", _x, ++_y, Colors::GREEN);
    text::printTextColorPos("|      |", _x, ++_y, Colors::GREEN);
    text::printTextColorPos("|      |", _x, ++_y, Colors::GREEN);
    text::printTextColorPos("|      |", _x, ++_y, Colors::GREEN);
    text::printTextColorPos("--------", _x, ++_y, Colors::GREEN);

    int _posCardX = P_REAL_PLAYER_AREA::x + 3;
    int _posCardY = P_REAL_PLAYER_AREA::y + 1;
    for (Card card : this->realPlayer.getInGameCards())
    {
        text::printTextColorPos(card.getLabel(), _posCardX, ++_posCardY, Colors::RED);
    }
}

void RoomGame::drawSystemPlayerArea()
{
    int _x = P_SYSTEM_PLAYER_AREA::x;
    int _y = P_SYSTEM_PLAYER_AREA::y;
    text::printTextColorPos("System", _x, _y, Colors::WHITE);
    text::printTextColorPos("--------", _x, ++_y, Colors::WHITE);
    text::printTextColorPos("|      |", _x, ++_y, Colors::WHITE);
    text::printTextColorPos("|      |", _x, ++_y, Colors::WHITE);
    text::printTextColorPos("|      |", _x, ++_y, Colors::WHITE);
    text::printTextColorPos("|      |", _x, ++_y, Colors::WHITE);
    text::printTextColorPos("|      |", _x, ++_y, Colors::WHITE);
    text::printTextColorPos("--------", _x, ++_y, Colors::WHITE);

    int _posCardX = P_SYSTEM_PLAYER_AREA::x + 3;
    int _posCardY = P_SYSTEM_PLAYER_AREA::y + 1;
    for (Card card : this->systemPlayer.getInGameCards())
    {
        text::printTextColorPos(card.getLabel(), _posCardX, ++_posCardY, Colors::RED);
    }
}

void RoomGame::startGame()
{
    string _startGame;

    do
    {
        text::printTextColorPos("Presionar E para empezar el juego ", 52, 15, Colors::RED);
        cin >> _startGame;
    }
    while (strcasecmp(_startGame.c_str(), "E") != 0);

    bool endGame = false;
    do
    {
        if(this->deck.getRounds() == 0 || this->deck.getRounds() == 4)
        {
            this->deck.resetRounds();
            this->deck.resetDeck();
            this->deck.shufflingCards();
        }
        giveCards();
        string _selectCard;
        while(this->realPlayer.getInGameCards().size() > 0
                && this->systemPlayer.getInGameCards().size() > 0)
        {
            pos::gotoxy(P_REAL_PLAYER_AREA::x, P_REAL_PLAYER_AREA::y + 8);
            cin >> _selectCard;

            Card _cardSetected = _list::card::findByLabel(this->realPlayer.getInGameCards(), _selectCard);
            if(_cardSetected.getValue() != -1)
            {
                list<Card> _tCards = _list::card::removeByLabel(this->realPlayer.getInGameCards(), _selectCard);
                this->realPlayer.setInGameCards(_tCards);
                throwCardOnTable(_cardSetected);

                srand(time(NULL));
                int _randNumber = rand() % this->systemPlayer.getInGameCards().size();

                Card _systemCard = _list::card::findByIndex(this->systemPlayer.getInGameCards(), _randNumber);
                list<Card> _sCards = _list::card::removeByLabel(this->systemPlayer.getInGameCards(), _systemCard.getLabel());
                this->systemPlayer.setInGameCards(_sCards);
                throwCardOnTable(_systemCard);

                renderRoom();
            }
        }
    } while (!endGame);
}

void RoomGame::giveCards()
{
    list<Card> realPlayerCards = this->deck.dealCards(this->deck.getRounds(), true);
    this->realPlayer.setInGameCards(realPlayerCards);
    list<Card> systemPlayerCards = this->deck.dealCards(this->deck.getRounds(), false);
    this->systemPlayer.setInGameCards(systemPlayerCards);
    renderRoom();
    this->deck.addRounds();
}

void RoomGame::renderRoom()
{
    drawDeckOnRoom();
    drawRealPlayerArea();
    drawSystemPlayerArea();
    drawGameTable();
}

void RoomGame::drawGameTable()
{
    int _x = P_GAME_TABLE::x;
    int _y = P_GAME_TABLE::y;
    text::printTextColorPos("System", _x, _y, Colors::WHITE);
    text::printTextColorPos("------------------------------------------", _x, ++_y, Colors::WHITE);
    text::printTextColorPos("|                                        |", _x, ++_y, Colors::WHITE);
    text::printTextColorPos("|                                        |", _x, ++_y, Colors::WHITE);
    text::printTextColorPos("|                                        |", _x, ++_y, Colors::WHITE);
    text::printTextColorPos("|                                        |", _x, ++_y, Colors::WHITE);
    text::printTextColorPos("|                                        |", _x, ++_y, Colors::WHITE);
    text::printTextColorPos("|                                        |", _x, ++_y, Colors::WHITE);
    text::printTextColorPos("|                                        |", _x, ++_y, Colors::WHITE);
    text::printTextColorPos("------------------------------------------", _x, ++_y, Colors::WHITE);

    int _posCardX = P_GAME_TABLE::x;
    int _posCardY = P_GAME_TABLE::y + 3;
    int _index = 0;
    for (Card card : this->gameTableCards)
    {
        if(_index != 5)
        {
            _posCardX += 6;
            _index++;
            text::printTextColorPos(card.getLabel(), _posCardX, _posCardY, Colors::RED);
        }
        else
        {
            _posCardX = P_GAME_TABLE::x + 6;
            _index = 1;
            _posCardY += 2;
            text::printTextColorPos(card.getLabel(), _posCardX, _posCardY, Colors::RED);
        }
    }

}

void RoomGame::throwCardOnTable(Card _cardThrow)
{
    Card _existCard = _list::card::findByValue(this->gameTableCards, _cardThrow.getValue());
    if(_existCard.getValue() != -1)
    {
        list<Card> _rCards = _list::card::removeByLabel(this->gameTableCards, _existCard.getLabel());
        this->gameTableCards = _rCards;
        for(int i = _cardThrow.getValue()+1; i <= 13; i++)
        {
            if(i == 8 || i == 9 || i == 10)
            {
                continue;
            }
            Card _existCardFor = _list::card::findByValue(this->gameTableCards, i);
            if(_existCardFor.getValue() != -1)
            {
                list<Card> _rCardsFor = _list::card::removeByLabel(this->gameTableCards, _existCardFor.getLabel());
                this->gameTableCards = _rCardsFor;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        this->gameTableCards.push_back(_cardThrow);
    }
}
