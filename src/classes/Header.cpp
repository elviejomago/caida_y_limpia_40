#include <iostream>
#include "Header.h"
#include "../functions/Constants.h"
#include "../functions/Display.h"

Header::Header()
{
	for (int i = 0; i < ScreenLines::COLUMNS; i++)
	{
		pos::gotoxy(i, 0); std::cout << "-" << std::endl;
		pos::gotoxy(i, 1); std::cout << "O" << std::endl;
		pos::gotoxy(i, 2); std::cout << "-" << std::endl;
	}

	pos::gotoxy(65, 3); std::cout << "CAIDA Y LIMPIA - JUEGO DE 40" << std::endl;

	for (int i = 0; i < ScreenLines::COLUMNS; i++)
	{
		pos::gotoxy(i, 4); std::cout << "-" << std::endl;
		pos::gotoxy(i, 5); std::cout << "O" << std::endl;
		pos::gotoxy(i, 6); std::cout << "-" << std::endl;
	}

}
