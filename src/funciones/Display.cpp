#include <stdio.h>
#include <windows.h>
#include <cwchar>
#include "Display.h"

void pos::gotoxy(int _x,int _y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = _x;
    dwPos.Y= _y;
    SetConsoleCursorPosition(hcon,dwPos);
}

void font::setSize(int _size)
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = _size;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void font::setDefaultSize()
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 12;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void font::setColor( unsigned char color )
{
  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color );
}
