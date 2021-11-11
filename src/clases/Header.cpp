#include <iostream>
#include "Header.h"
#include "../funciones/Constants.h"
#include "../funciones/Display.h"

Header::Header() 
{
	for (int i = 0; i < ScreenLines::COLUMNS; i++)
	{
		pos::gotoxy(i, 1); std::cout << "-" << std::endl;
		pos::gotoxy(i, 2); std::cout << "O" << std::endl;
		pos::gotoxy(i, 3); std::cout << "-" << std::endl;
	}

	pos::gotoxy(35, 5); std::cout << "CAIDA Y LIMPIA - JUEGO DE 40" << std::endl;

	for (int i = 0; i < ScreenLines::COLUMNS; i++)
	{
		pos::gotoxy(i, 7); std::cout << "-" << std::endl;
		pos::gotoxy(i, 8); std::cout << "O" << std::endl;
		pos::gotoxy(i, 9); std::cout << "-" << std::endl;
	}

}