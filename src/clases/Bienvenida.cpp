#include <conio.h>
#include "Bienvenida.h"
#include "Header.h"
#include "../funciones/Display.h"

Bienvenida::Bienvenida() :Pantalla("Bienvenida", "P002")
{
	Header header;
    displayOnScreen();
}

void Bienvenida::setJugador(Jugador jugador)
{
	this->jugador = jugador;
}

Jugador Bienvenida::getJugador()
{
	return this->jugador;
}

void Bienvenida::displayOnScreen(){
	string _nombreJugador;
    pos::gotoxy(70, 9);
    text::printTextColorLN("BIENVENIDO", 0x0c);
    text::printTextPositionLN("Ingrese su nombre de Jugador y presione ENTER.", 50, 10);
    text::printTextPositionLN("__________", 50, 11);
	pos::gotoxy(50, 11);
	cin >> _nombreJugador;
	setJugador(Jugador(_nombreJugador));
    onEnter();

}

void Bienvenida::removeOnScreen()
{
    system("cls");
}

void Bienvenida::onEnter()
{
    removeOnScreen();
}
