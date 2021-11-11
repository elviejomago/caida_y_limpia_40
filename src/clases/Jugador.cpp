#include "Jugador.h"

Jugador::Jugador()
{
}

Jugador::Jugador(string nombre)
{
	this->nombre = nombre;
	this->numeroPartidas = 0;
	this->partidasPerdidas = 0;
	this->patidasGanadas = 0;
}

string Jugador::getNombre()
{
	return this->nombre;
}

void Jugador::setNumeroPartidas(int numeroPartidas)
{
	this->numeroPartidas = numeroPartidas;
}

int Jugador::getNumeroPartidas()
{
	return this->numeroPartidas;
}

void Jugador::setPatidasGanadas(int partidasGanadas)
{
	this->patidasGanadas = partidasGanadas;
}

int Jugador::getPatidasGanadas()
{
	return this->patidasGanadas;
}

void Jugador::setPartidasPerdidas(int partidasPerdidas)
{
	this->partidasPerdidas = partidasPerdidas;
}

int Jugador::getPartidasPerdidas()
{
	return this->partidasPerdidas;
}
