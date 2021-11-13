#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <cwchar>
#include "Display.h"
#include "../constants/Constants.h"

using namespace std;

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

void font::setColor( unsigned char _color )
{
  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), _color );
}

void text::printTextColor(string _text, unsigned char _color)
{
    font::setColor(_color);
    cout << _text;
    font::setColor(Colors::WHITE);
}

void text::printTextColorLN(string _text, unsigned char _color)
{
    font::setColor(_color);
    cout << _text << endl;
    font::setColor(Colors::WHITE);
}

void text::printTextPosition(string _text, int _x, int _y)
{
    pos::gotoxy(_x, _y);
    cout << _text;
}

void text::printTextPositionLN(string _text, int _x, int _y)
{
    pos::gotoxy(_x, _y);
    cout << _text << endl;
}

void text::printTextColorPos(string _text, int _x, int _y, unsigned char _color)
{
    pos::gotoxy(_x, _y);
    text::printTextColor(_text, _color);
}

void text::printTextColorPosLN(string _text, int _x, int _y, unsigned char _color)
{
    pos::gotoxy(_x, _y);
    text::printTextColorLN(_text, _color);
}
