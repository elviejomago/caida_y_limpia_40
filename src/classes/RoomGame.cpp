#include <iostream>
#include <list>
#include <cstring>
#include <sstream>
#include "RoomGame.h"
#include "Header.h"
#include "../functions/Display.h"
#include "../constants/Positions.h"
#include "../constants/Constants.h"
#include "../functions/List.h"

using namespace std;

RoomGame::RoomGame() :Screen("Room Game", "S003"){}

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
            _y++; text::printTextPosition("---", _x, _y); _y--;
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
	for (Card card : this->realPlayer.getInGameCards()) {
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
	for (Card card : this->systemPlayer.getInGameCards()) {
        text::printTextColorPos(card.getLabel(), _posCardX, ++_posCardY, Colors::RED);
	}
}

void RoomGame::startGame()
{
    string _startGame;
    text::printTextColorPos("Presionar E para empezar el juego", 30, 15, Colors::RED);

    bool endGame = false;
    do
    {
        cin >> _startGame;
        if(strcasecmp(_startGame.c_str(), "E") == 0)
        {
            list<Card>::iterator it;
            giveCards();
            string _selectCard;
            while(true)
            {
                pos::gotoxy(P_REAL_PLAYER_AREA::x, P_REAL_PLAYER_AREA::y + 8);
                cin >> _selectCard;

                Card _cardSetected = _list::card::findByLabel(this->realPlayer.getInGameCards(), _selectCard);
                if(_cardSetected.getValue() != -1)
                {
                    list<Card> _tCards = _list::card::removeByLabel(this->realPlayer.getInGameCards(), _selectCard);
                    this->realPlayer.setInGameCards(_tCards);
                    renderRoom();
                }
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
}
