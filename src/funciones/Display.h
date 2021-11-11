#ifndef F_DISPLAY_H_INCLUDED
#define F_DISPLAY_H_INCLUDED

namespace pos
{
 void gotoxy(int _x,int _y);
}

namespace font
{
 void setSize(int _size);
 void setDefaultSize();
 void setColor( unsigned char color );
}

#endif // F_DISPLAY_H_INCLUDED
