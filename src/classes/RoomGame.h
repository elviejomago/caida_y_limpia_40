#ifndef CLASS_ROOMGAME_H
#define CLASS_ROOMGAME_H

#include <Screen.h>
#include <list>
#include "Deck.h"
#include "Player.h"
#include "Card.h"


class RoomGame : public Screen
{
private:
    Deck deck;
    Player realPlayer;
    Player systemPlayer;
    list<Card> gameTableCards;
public:
    RoomGame();
    RoomGame(Player _player);
    void init(Player _player);
    void renderRoom();
    void drawDeckOnRoom();
    void drawRealPlayerArea();
    void drawSystemPlayerArea();
    void drawGameTable();
    void startGame();
    void giveCards();
    void throwCardOnTable(Card _card);
};

#endif // CLASS_ROOMGAME_H
