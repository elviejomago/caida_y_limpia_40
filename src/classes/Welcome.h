#pragma once
#include<iostream>
#include "Screen.h"
#include "Player.h"

using namespace std;

class Welcome : public Screen
{
private:
	string message;
	Player player;
public:
	Welcome();
	void setPlayer(Player player);
	Player getPlayer();
	void displayOnScreen();
	void removeOnScreen();
	void onEnter();
};

