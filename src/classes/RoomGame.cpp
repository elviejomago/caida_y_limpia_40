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
#include "../functions/Scoring.h"

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

void RoomGame::resetGameTableCards()
{
    this->gameTableCards.clear();
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
    text::printTextColorPos("   -> ", _x, ++_y, Colors::GREEN);

    int _posCardX = P_REAL_PLAYER_AREA::x + 3;
    int _posCardY = P_REAL_PLAYER_AREA::y + 1;
    for (Card card : this->realPlayer.getInGameCards())
    {
        text::printTextColorPos(card.getLabel(), _posCardX, ++_posCardY, Colors::RED);
    }

    _x = P_REAL_PLAYER_WIN_CARDS::x;
    _y = P_REAL_PLAYER_WIN_CARDS::y;
    text::printTextColorPos("------", _x, ++_y, Colors::GREEN);
    text::printTextColorPos("|    |", _x, ++_y, Colors::GREEN);
    text::printTextColorPos("------", _x, ++_y, Colors::GREEN);
    _x = P_REAL_PLAYER_WIN_CARDS::x + 2;
    _y = P_REAL_PLAYER_WIN_CARDS::y + 2;
    text::printTextColorPos(std::to_string(this->realPlayer.getWinCards().size()), _x, _y, Colors::RED);

    _x = P_REAL_PLAYER_SCORE::x;
    _y = P_REAL_PLAYER_SCORE::y;
    text::printTextColorPos("--------", _x, ++_y, Colors::GREEN);
    text::printTextColorPos("|      |", _x, ++_y, Colors::GREEN);
    text::printTextColorPos("|      |", _x, ++_y, Colors::GREEN);
    text::printTextColorPos("--------", _x, ++_y, Colors::GREEN);

    _x = P_REAL_PLAYER_SCORE::x + 1;
    _y = P_REAL_PLAYER_SCORE::y + 2;
    text::printTextColorPos(this->realPlayer.score[0][0], ++_x, _y, Colors::RED);
    text::printTextColorPos(this->realPlayer.score[0][1], ++_x, _y, Colors::RED);
    text::printTextColorPos(this->realPlayer.score[0][2], ++_x, _y, Colors::RED);
    text::printTextColorPos(this->realPlayer.score[0][3], ++_x, _y, Colors::RED);

    _x = P_REAL_PLAYER_SCORE::x + 1;
    _y = P_REAL_PLAYER_SCORE::y + 3;
    text::printTextColorPos(this->realPlayer.score[1][0], ++_x, _y, Colors::RED);
    text::printTextColorPos(this->realPlayer.score[1][1], ++_x, _y, Colors::RED);
    text::printTextColorPos(this->realPlayer.score[1][2], ++_x, _y, Colors::RED);
    text::printTextColorPos(this->realPlayer.score[1][3], ++_x, _y, Colors::RED);
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

    _x = P_SYSTEM_PLAYER_WIN_CARDS::x;
    _y = P_SYSTEM_PLAYER_WIN_CARDS::y;
    text::printTextColorPos("------", _x, ++_y, Colors::WHITE);
    text::printTextColorPos("|    |", _x, ++_y, Colors::WHITE);
    text::printTextColorPos("------", _x, ++_y, Colors::WHITE);
    _x = P_SYSTEM_PLAYER_WIN_CARDS::x + 2;
    _y = P_SYSTEM_PLAYER_WIN_CARDS::y + 2;
    text::printTextColorPos(std::to_string(this->systemPlayer.getWinCards().size()), _x, _y, Colors::RED);

    _x = P_SYSTEM_PLAYER_SCORE::x;
    _y = P_SYSTEM_PLAYER_SCORE::y;
    text::printTextColorPos("--------", _x, ++_y, Colors::WHITE);
    text::printTextColorPos("|      |", _x, ++_y, Colors::WHITE);
    text::printTextColorPos("|      |", _x, ++_y, Colors::WHITE);
    text::printTextColorPos("--------", _x, ++_y, Colors::WHITE);

    _x = P_SYSTEM_PLAYER_SCORE::x + 1;
    _y = P_SYSTEM_PLAYER_SCORE::y + 2;
    text::printTextColorPos(this->systemPlayer.score[0][0], ++_x, _y, Colors::RED);
    text::printTextColorPos(this->systemPlayer.score[0][1], ++_x, _y, Colors::RED);
    text::printTextColorPos(this->systemPlayer.score[0][2], ++_x, _y, Colors::RED);
    text::printTextColorPos(this->systemPlayer.score[0][3], ++_x, _y, Colors::RED);

    _x = P_SYSTEM_PLAYER_SCORE::x + 1;
    _y = P_SYSTEM_PLAYER_SCORE::y + 3;
    text::printTextColorPos(this->systemPlayer.score[1][0], ++_x, _y, Colors::RED);
    text::printTextColorPos(this->systemPlayer.score[1][1], ++_x, _y, Colors::RED);
    text::printTextColorPos(this->systemPlayer.score[1][2], ++_x, _y, Colors::RED);
    text::printTextColorPos(this->systemPlayer.score[1][3], ++_x, _y, Colors::RED);
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
            int _score = _scoring::deck(this->realPlayer.getWinCards());
            this->realPlayer.addScore(_score);
            this->realPlayer.resetWinCards();
            _score = _scoring::deck(this->systemPlayer.getWinCards());
            this->systemPlayer.addScore(_score);
            this->systemPlayer.resetWinCards();
            resetGameTableCards();

            this->deck.resetRounds();
            this->deck.resetDeck();
            this->deck.shufflingCards();
        }
        giveCards();
        Card emptyCard;
        this->lastCard = emptyCard;
        string _selectCard;
        string _takeCard;
        while(this->realPlayer.getInGameCards().size() > 0
                && this->systemPlayer.getInGameCards().size() > 0)
        {
            pos::gotoxy(P_REAL_PLAYER_AREA::x, P_REAL_PLAYER_AREA::y + 8);
            cin >> _selectCard;

            pos::gotoxy(P_REAL_PLAYER_AREA::x + 6, P_REAL_PLAYER_AREA::y + 8);
            cin >> _takeCard;
            pos::gotoxy(P_REAL_PLAYER_AREA::x + 6, P_REAL_PLAYER_AREA::y + 8);
            cout << "     ";

            Card _cardSetected = _list::card::findByLabel(this->realPlayer.getInGameCards(), _selectCard);
            if(_cardSetected.getValue() != -1)
            {
                list<Card> _tCards = _list::card::removeByLabel(this->realPlayer.getInGameCards(), _selectCard);
                this->realPlayer.setInGameCards(_tCards);
                throwCardOnTablePlayer(_cardSetected, _takeCard);
                this->lastCard = _cardSetected;

                srand(time(NULL));
                int _randNumber = rand() % this->systemPlayer.getInGameCards().size();

                Card _systemCard = _list::card::findByIndex(this->systemPlayer.getInGameCards(), _randNumber);
                list<Card> _sCards = _list::card::removeByLabel(this->systemPlayer.getInGameCards(), _systemCard.getLabel());
                this->systemPlayer.setInGameCards(_sCards);
                throwCardOnTableSystem(_systemCard);
                this->lastCard = _systemCard;

                renderRoom();
            }
        }
    } while (!endGame);
}

void RoomGame::giveCards()
{
    list<Card> realPlayerCards = this->deck.dealCards(this->deck.getRounds(), true);
    this->realPlayer.setInGameCards(realPlayerCards);
    int _score = _scoring::roundOrDoubleRound(realPlayerCards);
    this->realPlayer.addScore(_score);

    list<Card> systemPlayerCards = this->deck.dealCards(this->deck.getRounds(), false);
    this->systemPlayer.setInGameCards(systemPlayerCards);
    _score = _scoring::roundOrDoubleRound(systemPlayerCards);
    this->systemPlayer.addScore(_score);

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
    text::printTextColorPos("Mesa de Juego", _x, _y, Colors::WHITE);
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

void RoomGame::throwCardOnTablePlayer(Card _cardThrow, string _takeCard)
{
    string _takeCard2, _takeCard3;
    if(_takeCard.length() == 4)
    {
        _takeCard2 = _takeCard.substr(0, 2);
        _takeCard3 = _takeCard.substr(2, 3);
        Card _existCard2 = _list::card::findByLabel(this->gameTableCards, _takeCard2);
        Card _existCard3 = _list::card::findByLabel(this->gameTableCards, _takeCard3);
        if(_existCard2.getValue() != -1 && _existCard3.getValue() != -1 && _cardThrow.getValue() <= 7
           && _cardThrow.getValue() == (_existCard2.getValue() + _existCard3.getValue()))
        {
            this->realPlayer.addWinCard(_cardThrow);
            list<Card> _rCards2 = _list::card::removeByLabel(this->gameTableCards, _existCard2.getLabel());
            list<Card> _rCards3 = _list::card::removeByLabel(_rCards2, _existCard3.getLabel());
            this->gameTableCards = _rCards3;
            this->realPlayer.addWinCard(_existCard2);
            this->realPlayer.addWinCard(_existCard3);
            for(int i = _existCard2.getValue() + _existCard3.getValue() + 1; i <= 13; i++)
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
                    this->realPlayer.addWinCard(_existCardFor);
                }
                else
                {
                    break;
                }
            }
            int _score = _scoring::table(this->gameTableCards, this->lastCard, _cardThrow);
            this->realPlayer.addScore(_score);
        }
        else
        {
            this->gameTableCards.push_back(_cardThrow);
        }
    }
    else
    {
        Card _existCard = _list::card::findByLabel(this->gameTableCards, _takeCard);
        if(_existCard.getValue() != -1 && _existCard.getValue() == _cardThrow.getValue())
        {
            this->realPlayer.addWinCard(_cardThrow);
            list<Card> _rCards = _list::card::removeByLabel(this->gameTableCards, _existCard.getLabel());
            this->gameTableCards = _rCards;
            this->realPlayer.addWinCard(_existCard);
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
                    this->realPlayer.addWinCard(_existCardFor);
                }
                else
                {
                    break;
                }
            }
            int _score = _scoring::table(this->gameTableCards, this->lastCard, _cardThrow);
            this->realPlayer.addScore(_score);
        }
        else
        {
            this->gameTableCards.push_back(_cardThrow);
        }

    }
}

void RoomGame::throwCardOnTableSystem(Card _cardThrow)
{
    Card _existCard = _list::card::findByValue(this->gameTableCards, _cardThrow.getValue());
    if(_existCard.getValue() != -1)
    {
        this->systemPlayer.addWinCard(_cardThrow);
        list<Card> _rCards = _list::card::removeByLabel(this->gameTableCards, _existCard.getLabel());
        this->gameTableCards = _rCards;
        this->systemPlayer.addWinCard(_existCard);
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
                this->systemPlayer.addWinCard(_existCardFor);
            }
            else
            {
                break;
            }
        }
        int _score = _scoring::table(this->gameTableCards, this->lastCard, _cardThrow);
        this->systemPlayer.addScore(_score);
    }
    else
    {
        Card _cardsArray[this->gameTableCards.size()];
        int p = 0;
        for(Card _card : this->gameTableCards)
        {
            _cardsArray[p] = _card;
            p++;
        }
        for(int j = 0; j < this->gameTableCards.size(); j++)
        {
            for(int k = j+1; k < this->gameTableCards.size(); k++)
            {
                if(_cardThrow.getValue() <= 7 && _cardThrow.getValue() == (_cardsArray[j].getValue() + _cardsArray[k].getValue()))
                {
                    this->systemPlayer.addWinCard(_cardThrow);
                    list<Card> _rCards2 = _list::card::removeByLabel(this->gameTableCards, _cardsArray[j].getLabel());
                    list<Card> _rCards3 = _list::card::removeByLabel(_rCards2, _cardsArray[k].getLabel());
                    this->gameTableCards = _rCards3;
                    this->systemPlayer.addWinCard(_cardsArray[j]);
                    this->systemPlayer.addWinCard(_cardsArray[k]);
                    for(int i = _cardsArray[j].getValue() + _cardsArray[k].getValue() + 1; i <= 13; i++)
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
                            this->systemPlayer.addWinCard(_existCardFor);
                        }
                        else
                        {
                            break;
                        }
                    }
                    int _score = _scoring::table(this->gameTableCards, this->lastCard, _cardThrow);
                    this->systemPlayer.addScore(_score);
                }
            }
        }



        this->gameTableCards.push_back(_cardThrow);
    }
}
