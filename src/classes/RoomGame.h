#ifndef CLASS_ROOMGAME_H
#define CLASS_ROOMGAME_H

#include <Screen.h>
#include "Player.h"


class RoomGame : public Screen
{
private:
    Player player;
    Player player2;

public:
    RoomGame();
};

#endif // CLASS_ROOMGAME_H
