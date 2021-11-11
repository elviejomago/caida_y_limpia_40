#include <iostream>
#include <windows.h>
#include "wtypes.h"
#include "clases/Pantalla.h"
#include "clases/Bienvenida.h"

#pragma comment(lib, "user32")

int main()
{
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

    Bienvenida pBienvenida;

    return 0;
//    system("pause > 0");
}

