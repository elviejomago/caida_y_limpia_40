#include <iostream>
#include "Letters.h"
#include "Display.h"

using namespace std;

void _letter::up::drawLetterA(int _x, int _y)
{
    text::printTextPosition("     ---     ", _x, _y++);
    text::printTextPosition("    /   \\    ", _x, _y++);
    text::printTextPosition("   /     \\   ", _x, _y++);
    text::printTextPosition("  /       \\  ", _x, _y++);
    text::printTextPosition(" /   ___   \\ ", _x, _y++);
    text::printTextPosition("|   |   |   |", _x, _y++);
    text::printTextPosition("|   |   |   |", _x, _y++);
    text::printTextPosition("|   |   |   |", _x, _y++);
    text::printTextPosition("|   |___|   |", _x, _y++);
    text::printTextPosition("|   |   |   |", _x, _y++);
    text::printTextPosition("|   |   |   |", _x, _y++);
    text::printTextPosition("|___|   |___|", _x, _y++);
}

void _letter::up::drawLetterC(int _x, int _y)
{
    text::printTextPosition("    -----    ", _x, _y++);
    text::printTextPosition("   /     \\   ", _x, _y++);
    text::printTextPosition("  /   ____\\  ", _x, _y++);
    text::printTextPosition(" /   |       ", _x, _y++);
    text::printTextPosition("|    |       ", _x, _y++);
    text::printTextPosition("|    |       ", _x, _y++);
    text::printTextPosition("|    |       ", _x, _y++);
    text::printTextPosition("|    |       ", _x, _y++);
    text::printTextPosition(" \\   |____   ", _x, _y++);
    text::printTextPosition("  \\       /  ", _x, _y++);
    text::printTextPosition("   \\     /   ", _x, _y++);
    text::printTextPosition("    _____    ", _x, _y++);
}

void _letter::up::drawLetterD(int _x, int _y)
{
    text::printTextPosition("--------\\    ", _x, _y++);
    text::printTextPosition("|        \\   ", _x, _y++);
    text::printTextPosition("|         \\  ", _x, _y++);
    text::printTextPosition("|          \\ ", _x, _y++);
    text::printTextPosition("|   _____   |", _x, _y++);
    text::printTextPosition("|  |     |  |", _x, _y++);
    text::printTextPosition("|  |_____|  |", _x, _y++);
    text::printTextPosition("|           |", _x, _y++);
    text::printTextPosition("|          / ", _x, _y++);
    text::printTextPosition("|         /  ", _x, _y++);
    text::printTextPosition("|        /   ", _x, _y++);
    text::printTextPosition("|_______/    ", _x, _y++);
}

void _letter::up::drawLetterI(int _x, int _y)
{
    text::printTextPosition("--------", _x, _y++);
    text::printTextPosition("|      |", _x, _y++);
    text::printTextPosition("--|  |--", _x, _y++);
    text::printTextPosition("  |  |  ", _x, _y++);
    text::printTextPosition("  |  |  ", _x, _y++);
    text::printTextPosition("  |  |  ", _x, _y++);
    text::printTextPosition("  |  |  ", _x, _y++);
    text::printTextPosition("  |  |  ", _x, _y++);
    text::printTextPosition("  |  |  ", _x, _y++);
    text::printTextPosition("--|  |--", _x, _y++);
    text::printTextPosition("|      |", _x, _y++);
    text::printTextPosition("________", _x, _y++);
}

void _letter::up::drawLetterL(int _x, int _y)
{
    text::printTextPosition("-----", _x, _y++);
    text::printTextPosition("|   |", _x, _y++);
    text::printTextPosition("|   |", _x, _y++);
    text::printTextPosition("|   |", _x, _y++);
    text::printTextPosition("|   |", _x, _y++);
    text::printTextPosition("|   |", _x, _y++);
    text::printTextPosition("|   |", _x, _y++);
    text::printTextPosition("|   |", _x, _y++);
    text::printTextPosition("|   |", _x, _y++);
    text::printTextPosition("|   |----", _x, _y++);
    text::printTextPosition("|        |", _x, _y++);
    text::printTextPosition("|________|", _x, _y++);
}

void _letter::up::drawLetterM(int _x, int _y)
{
    text::printTextPosition("|\\         /|", _x, _y++);
    text::printTextPosition("|  \\     /  |", _x, _y++);
    text::printTextPosition("|\\   \\_/   /|", _x, _y++);
    text::printTextPosition("|  \\     /  |", _x, _y++);
    text::printTextPosition("|  | \\_/ |  |", _x, _y++);
    text::printTextPosition("|  |     |  |", _x, _y++);
    text::printTextPosition("|  |     |  |", _x, _y++);
    text::printTextPosition("|  |     |  |", _x, _y++);
    text::printTextPosition("|  |     |  |", _x, _y++);
    text::printTextPosition("|  |     |  |", _x, _y++);
    text::printTextPosition("|  |     |  |", _x, _y++);
    text::printTextPosition("|__|     |__|", _x, _y++);
}

void _letter::up::drawLetterP(int _x, int _y)
{
    text::printTextPosition("--------\\", _x, _y++);
    text::printTextPosition("|  ____  \\", _x, _y++);
    text::printTextPosition("|  |  |   |", _x, _y++);
    text::printTextPosition("|  ----   |", _x, _y++);
    text::printTextPosition("|        /", _x, _y++);
    text::printTextPosition("|    ___/  ", _x, _y++);
    text::printTextPosition("|   |", _x, _y++);
    text::printTextPosition("|   |", _x, _y++);
    text::printTextPosition("|   |", _x, _y++);
    text::printTextPosition("|   |", _x, _y++);
    text::printTextPosition("|   |", _x, _y++);
    text::printTextPosition("|___|", _x, _y++);
}

void _letter::up::drawLetterY(int _x, int _y)
{
    text::printTextPosition("---    ---", _x, _y++);
    text::printTextPosition("\\  \\  /  /", _x, _y++);
    text::printTextPosition(" \\  \\/  / ",_x, _y++);
    text::printTextPosition("  \\    / ", _x, _y++);
    text::printTextPosition("   \\  /   ", _x, _y++);
    text::printTextPosition("   |  |  ", _x, _y++);
    text::printTextPosition("   |  |  ", _x, _y++);
    text::printTextPosition("   |  |  ", _x, _y++);
    text::printTextPosition("   |  |  ", _x, _y++);
    text::printTextPosition("   |  |  ", _x, _y++);
    text::printTextPosition("   |  |  ", _x, _y++);
    text::printTextPosition("   |__|  ", _x, _y++);
}

void _letter::bottom::drawLetterJ(int _x, int _y)
{
    text::printTextPosition("----------", _x, _y++);
    text::printTextPosition("|___  ___|", _x, _y++);
    text::printTextPosition("   |  |",_x, _y++);
    text::printTextPosition("   |  |", _x, _y++);
    text::printTextPosition("   |  |", _x, _y++);
    text::printTextPosition("___|  |", _x, _y++);
    text::printTextPosition("|     |", _x, _y++);
    text::printTextPosition("|_____|", _x, _y++);
}

void _letter::bottom::drawLetterU(int _x, int _y)
{
    text::printTextPosition("----  ----", _x, _y++);
    text::printTextPosition("|  |  |  |", _x, _y++);
    text::printTextPosition("|  |  |  |",_x, _y++);
    text::printTextPosition("|  |  |  |", _x, _y++);
    text::printTextPosition("|  |  |  |", _x, _y++);
    text::printTextPosition("|  |__|  |", _x, _y++);
    text::printTextPosition("|        | ", _x, _y++);
    text::printTextPosition("|________|", _x, _y++);
}

void _letter::bottom::drawLetterE(int _x, int _y)
{
    text::printTextPosition("--------", _x, _y++);
    text::printTextPosition("|  ____|", _x, _y++);
    text::printTextPosition("|  |    ",_x, _y++);
    text::printTextPosition("|  ---- ", _x, _y++);
    text::printTextPosition("|  ___| ", _x, _y++);
    text::printTextPosition("|  |    ", _x, _y++);
    text::printTextPosition("|  |----", _x, _y++);
    text::printTextPosition("|______|", _x, _y++);
}

void _letter::bottom::drawLetterO(int _x, int _y)
{
    text::printTextPosition("----------", _x, _y++);
    text::printTextPosition("|        |", _x, _y++);
    text::printTextPosition("|  ----  |", _x, _y++);
    text::printTextPosition("|  |  |  |",_x, _y++);
    text::printTextPosition("|  |  |  |", _x, _y++);
    text::printTextPosition("|  ----  |", _x, _y++);
    text::printTextPosition("|        |", _x, _y++);
    text::printTextPosition("|________|", _x, _y++);
}

void _letter::bottom::drawLetterG(int _x, int _y)
{
    text::printTextPosition("---------", _x, _y++);
    text::printTextPosition("|  _____|", _x, _y++);
    text::printTextPosition("|  |    ",_x, _y++);
    text::printTextPosition("|  | ____", _x, _y++);
    text::printTextPosition("|  | |   |", _x, _y++);
    text::printTextPosition("|  | --| |", _x, _y++);
    text::printTextPosition("|  |---| |", _x, _y++);
    text::printTextPosition("|________|", _x, _y++);
}

void _letter::bottom::drawLetterD(int _x, int _y)
{
    text::printTextPosition("--------\\    ", _x, _y++);
    text::printTextPosition("|        \\ ", _x, _y++);
    text::printTextPosition("|   ___   |", _x, _y++);
    text::printTextPosition("|  |   |  |", _x, _y++);
    text::printTextPosition("|  |___|  |", _x, _y++);
    text::printTextPosition("|         |", _x, _y++);
    text::printTextPosition("|        /   ", _x, _y++);
    text::printTextPosition("|_______/    ", _x, _y++);
}

void _number::bottom::drawNumber4(int _x, int _y)
{
    text::printTextPosition("----", _x, _y++);
    text::printTextPosition("|  |   ----", _x, _y++);
    text::printTextPosition("|  |   |  |", _x, _y++);
    text::printTextPosition("|  |   |  |", _x, _y++);
    text::printTextPosition("|  ----   |", _x, _y++);
    text::printTextPosition("|______   |", _x, _y++);
    text::printTextPosition("      |   |", _x, _y++);
    text::printTextPosition("      |___|", _x, _y++);
}

void _number::bottom::drawNumber0(int _x, int _y)
{
    text::printTextPosition("----------", _x, _y++);
    text::printTextPosition("|        |", _x, _y++);
    text::printTextPosition("|  ----  |", _x, _y++);
    text::printTextPosition("|  ||||  |",_x, _y++);
    text::printTextPosition("|  ||||  |", _x, _y++);
    text::printTextPosition("|  ----  |", _x, _y++);
    text::printTextPosition("|        |", _x, _y++);
    text::printTextPosition("|________|", _x, _y++);
}

void _logo::drawLogo(int _x, int _y)
{
    text::printTextPosition("           ...           ", _x, _y++);
    text::printTextPosition("        .        .       ", _x, _y++);
    text::printTextPosition("      .    . .    .      ", _x, _y++);
    text::printTextPosition("     .    .   .    .     ", _x, _y++);
    text::printTextPosition("    .               .    ", _x, _y++);
    text::printTextPosition("   .     .     .     .   ", _x, _y++);
    text::printTextPosition("        .       .        ", _x, _y++);
    text::printTextPosition("  .     ...    ..     .  ", _x, _y++);
    text::printTextPosition("       .....  ....       ", _x, _y++);
    text::printTextPosition(" .    ...... ......    . ", _x, _y++);
    text::printTextPosition("     . ..........  .     ", _x, _y++);
    text::printTextPosition("    .    .......    .    ", _x, _y++);
    text::printTextPosition(".   . .   ....    . .   .", _x, _y++);
    text::printTextPosition(".  ...     ...     ...  .", _x, _y++);
    text::printTextPosition(".  ....     .     ....  .", _x, _y++);
    text::printTextPosition(".  . ..           .. .  .", _x, _y++);
    text::printTextPosition(".  .  .           .  .  .", _x, _y++);
    text::printTextPosition("       ...     ...       ", _x, _y++);
    text::printTextPosition("    .  ....   ....  .    ", _x, _y++);
    text::printTextPosition("     ................    ", _x, _y++);
    text::printTextPosition(" .    . .........        ", _x, _y++);
    text::printTextPosition("       .   ...   .    .  ", _x, _y++);
    text::printTextPosition("  .     .   .   .    .   ", _x, _y++);
    text::printTextPosition("   .                     ", _x, _y++);
    text::printTextPosition("    .    .     .    .    ", _x, _y++);
    text::printTextPosition("     .    .   .    .     ", _x, _y++);
    text::printTextPosition("       .   . .   .       ", _x, _y++);
    text::printTextPosition("         .      .        ", _x, _y++);
    text::printTextPosition("           ...           ", _x, _y++);
}
