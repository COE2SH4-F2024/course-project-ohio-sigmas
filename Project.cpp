#include <iostream>
#include "Player.h"

using namespace std;

#define DELAY_CONST 80000

GameMechs * _g;
Player * p;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{
    Initialize();
    while(_g->getExitFlagStatus() == false)
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }
    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    srand(time(NULL));
    _g = new GameMechs;
    p = new Player(_g);
}

void GetInput(void)
{
    if (MacUILib_hasChar()) {
        char c = MacUILib_getChar();
        _g->setInput(c);
    } else {
        _g->clearInput();
    }

}

void RunLogic(void)
{
    p->updatePlayerDir();
    p->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    p->drawScreen();
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void)
{
    MacUILib_clearScreen();
    if (_g->getLoseFlagStatus()) {
        MacUILib_printf("you LOST ?!?! sucks for u haha\nfinallllll score is = %d", _g->getScore());
    }
    delete _g;
    delete p;
    MacUILib_uninit();
}