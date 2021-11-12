#ifndef F_DISPLAY_H_INCLUDED
#define F_DISPLAY_H_INCLUDED

#include <iostream>

using namespace std;

namespace pos
{
void gotoxy(int _x,int _y);
}

namespace font
{
void setSize(int _size);
void setDefaultSize();
void setColor( unsigned char _color );
}

namespace text
{
void printTextColor(string _text, unsigned char _color);
void printTextColorLN(string _text, unsigned char _color);
void printTextPosition(string _text, int _x, int _y);
void printTextPositionLN(string _text, int _x, int _y);
}

#endif // F_DISPLAY_H_INCLUDED
