#pragma once
#include<iostream>

using namespace std;

class Jugador
{
private:
	string nombre;
	int numeroPartidas;
	int patidasGanadas;
	int partidasPerdidas;
public:
	Jugador();
	Jugador(string nombre);
	string getNombre();
	void setNumeroPartidas(int numeroPartidas);
	int getNumeroPartidas();
	void setPatidasGanadas(int partidasGanadas);
	int getPatidasGanadas();
	void setPartidasPerdidas(int partidasPerdidas);
	int getPartidasPerdidas();
};

