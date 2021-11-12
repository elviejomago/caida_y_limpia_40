#include <windows.h>
#include "clases/Screen.h"
#include "clases/Welcome.h"
#include "funciones/Display.h"

#pragma comment(lib, "user32")

void initConfig();

int main()
{
    initConfig();
    Welcome sWelcome;

    return 0;
//    system("pause > 0");
}

void initConfig()
{
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
    font::setSize(18);
}
