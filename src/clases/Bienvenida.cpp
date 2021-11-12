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
    font::setColor(0x07);

    font::setSize(18);
	string _nombreJugador;
    pos::gotoxy(70, 5);
    font::setColor(0x0c);
    cout << "BIENVENIDO" << endl;
    font::setColor(0x07);
    pos::gotoxy(50, 6);
	cout << "Ingrese su nombre de Jugador y presione ENTER." << endl;
	pos::gotoxy(50, 8);
	cout << "__________" << endl;
	pos::gotoxy(50, 8);
	cin >> _nombreJugador;
	setJugador(Jugador(_nombreJugador));
}
