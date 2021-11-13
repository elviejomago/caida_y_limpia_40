#ifndef CLASS_ROOMGAME_H
#define CLASS_ROOMGAME_H

#include <Screen.h>
#include "Deck.h"


class RoomGame : public Screen
{
private:
    Deck deck;
public:
    RoomGame();
    void drawDeckOnRoom();
    void drawRealPlayerArea();
    void drawSystemPlayerArea();
};

#endif // CLASS_ROOMGAME_H
