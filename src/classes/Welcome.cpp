#include <conio.h>
#include "Welcome.h"
#include "Header.h"
#include "../functions/Display.h"

Welcome::Welcome() :Screen("Welcome", "P002")
{
	Header header;
    displayOnScreen();
}

void Welcome::setPlayer(Player player)
{
	this->player = player;
}

Player Welcome::getPlayer()
{
	return this->player;
}

void Welcome::displayOnScreen(){
	string _playerName;
    pos::gotoxy(70, 9);
    text::printTextColorLN("BIENVENIDO", 0x0c);
    text::printTextPositionLN("Ingrese su nombre de Jugador y presione ENTER.", 50, 10);
    text::printTextPositionLN("__________", 50, 11);
	pos::gotoxy(50, 11);
	cin >> _playerName;
	setPlayer(Player(_playerName));
    onEnter();

}

void Welcome::removeOnScreen()
{
    system("cls");
}

void Welcome::onEnter()
{
    removeOnScreen();
}
