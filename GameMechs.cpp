#include "GameMechs.h"

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor? no
GameMechs::~GameMechs()
{
    //retur
}

GameMechs::GameMechs(const GameMechs & rhs) {
    boardSizeX = rhs.boardSizeX;
    boardSizeY = rhs.boardSizeY;
    input = rhs.input;
    exitFlag = rhs.exitFlag;
    loseFlag = rhs.loseFlag;
    score = rhs.score;
    food = rhs.food;
}

GameMechs & GameMechs::operator=(const GameMechs & rhs) {
    boardSizeX = rhs.boardSizeX;
    boardSizeY = rhs.boardSizeY;
    input = rhs.input;
    exitFlag = rhs.exitFlag;
    loseFlag = rhs.loseFlag;
    score = rhs.score;
    food = rhs.food;
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    ++score;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = 1;
}

void GameMechs::setLoseFlag()
{
    loseFlag = 1;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here