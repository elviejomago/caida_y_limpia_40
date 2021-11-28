#ifndef WORDS_H_INCLUDED
#define WORDS_H_INCLUDED

namespace _letter
{
    namespace up
    {
        void drawLetterA(int _x, int _y);
        void drawLetterC(int _x, int _y);
        void drawLetterD(int _x, int _y);
        void drawLetterI(int _x, int _y);
        void drawLetterL(int _x, int _y);
        void drawLetterM(int _x, int _y);
        void drawLetterP(int _x, int _y);
        void drawLetterY(int _x, int _y);
    }

    namespace bottom
    {
        void drawLetterD(int _x, int _y);
        void drawLetterE(int _x, int _y);
        void drawLetterG(int _x, int _y);
        void drawLetterJ(int _x, int _y);
        void drawLetterU(int _x, int _y);
        void drawLetterO(int _x, int _y);
    }

}

namespace _number
{
    namespace bottom
    {
        void drawNumber4(int _x, int _y);
        void drawNumber0(int _x, int _y);
    }
}

namespace _logo
{
        void drawLogo(int _x, int _y);
}


#endif // WORDS_H_INCLUDED
