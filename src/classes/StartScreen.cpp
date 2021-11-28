#include <thread>
#include <chrono>
#include <atomic>
#include "StartScreen.h"
#include "Welcome.h"
#include "../functions/Letters.h"

StartScreen::StartScreen() :Screen("Start Game", "S001")
{
    int _yUp = 3;
    int _yBottom = 18;
    _letter::up::drawLetterC(2, _yUp);
    _letter::up::drawLetterA(14, _yUp);
    _letter::up::drawLetterI(30, _yUp);
    _letter::up::drawLetterD(42, _yUp);
    _letter::up::drawLetterA(57, _yUp);

    _letter::up::drawLetterY(75, _yUp);

    _letter::up::drawLetterL(92, _yUp);
    _letter::up::drawLetterI(104, _yUp);
    _letter::up::drawLetterM(114, _yUp);
    _letter::up::drawLetterP(130, _yUp);
    _letter::up::drawLetterI(144, _yUp);
    _letter::up::drawLetterA(154, _yUp);

    _letter::bottom::drawLetterJ(12, _yBottom);
    _letter::bottom::drawLetterU(25, _yBottom);
    _letter::bottom::drawLetterE(38, _yBottom);
    _letter::bottom::drawLetterG(51, _yBottom);
    _letter::bottom::drawLetterO(64, _yBottom);

    _logo::drawLogo(75, _yBottom-2);

    _letter::bottom::drawLetterD(102, _yBottom);
    _letter::bottom::drawLetterE(115, _yBottom);

    _number::bottom::drawNumber4(128, _yBottom);
    _number::bottom::drawNumber0(141, _yBottom);

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    system("cls");
    Welcome welcome;
}

