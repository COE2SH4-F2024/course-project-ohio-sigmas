#include <iostream>
#include "MacUILib.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs * _g;

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
    _g = new GameMechs;
}

void GetInput(void)
{
    if (MacUILib_hasChar()) {
        char c = MacUILib_getChar();
        _g->setInput(c);
    }
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    // MacUILib_clearScreen();    
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    // MacUILib_clearScreen();    

    MacUILib_uninit();
}
