#include <windows.h>
#include "classes/Screen.h"
#include "StartScreen.h"
#include "functions/Display.h"
#include "constants/Constants.h"

#pragma comment(lib, "user32")

void initConfig();

int main()
{
    initConfig();
    StartScreen startScreen;

    system("pause > 0");
}

void initConfig()
{
    //::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
    font::setSize(18);
    font::setColor(Colors::WHITE);
}
