#include <windows.h>
#include "classes/Screen.h"
#include "classes/Welcome.h"
#include "functions/Display.h"
#include "constants/Constants.h"

#pragma comment(lib, "user32")

void initConfig();

int main()
{
    initConfig();
    Welcome sWelcome;

    system("pause > 0");
}

void initConfig()
{
    //::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
    font::setSize(18);
    font::setColor(Colors::WHITE);
}
