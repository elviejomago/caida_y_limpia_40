#pragma once
#include<iostream>
#include "Pantalla.h"
#include "Jugador.h"

using namespace std;

class Bienvenida : public Pantalla
{
private:
	string mensaje;
	Jugador jugador;
public:
	Bienvenida();
	void setJugador(Jugador jugador);
	Jugador getJugador();

	void displayOnScreen();
	void removeOnScreen();
	void onEnter();
};

