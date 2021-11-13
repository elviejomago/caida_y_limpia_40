#include <iostream>
#include <sstream>
#include "RoomGame.h"
#include "Header.h"
#include "../functions/Display.h"
#include "../constants/Positions.h"
#include "../constants/Constants.h"

using namespace std;

RoomGame::RoomGame() :Screen("Room Game", "S003")
{
    Header header;
    Deck deck;
    this->deck = deck;
    drawDeckOnRoom();
    drawRealPlayerArea();
    drawSystemPlayerArea();
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
    text::printTextColorPos("Player", _x, _y, Colors::GREEN);
    text::printTextColorPos("--------", _x, ++_y, Colors::GREEN);
    text::printTextColorPos("|      |", _x, ++_y, Colors::GREEN);
    text::printTextColorPos("|      |", _x, ++_y, Colors::GREEN);
    text::printTextColorPos("|      |", _x, ++_y, Colors::GREEN);
    text::printTextColorPos("|      |", _x, ++_y, Colors::GREEN);
    text::printTextColorPos("|      |", _x, ++_y, Colors::GREEN);
    text::printTextColorPos("--------", _x, ++_y, Colors::GREEN);
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

}

