#ifndef CLASS_ROOMGAME_H
#define CLASS_ROOMGAME_H

#include <Screen.h>
#include "Deck.h"
#include "Player.h"


class RoomGame : public Screen
{
private:
    Deck deck;
    Player realPlayer;
    Player systemPlayer;
public:
    RoomGame();
    RoomGame(Player _player);
    void init(Player _player);
    void renderRoom();
    void drawDeckOnRoom();
    void drawRealPlayerArea();
    void drawSystemPlayerArea();
    void startGame();
    void giveCards();
};

#endif // CLASS_ROOMGAME_H
