#include <windows.h>
#include "clases/Pantalla.h"
#include "clases/Bienvenida.h"
#include "funciones/Display.h"

#pragma comment(lib, "user32")

void initConfig();

int main()
{
    initConfig();
    Bienvenida pBienvenida;

    return 0;
//    system("pause > 0");
}

void initConfig()
{
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
    font::setSize(18);
}
