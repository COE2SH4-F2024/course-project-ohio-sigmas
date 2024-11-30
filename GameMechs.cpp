#include "GameMechs.h"
#include "stdlib.h"

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
    input = 0;
    exitFlag = 0;
    loseFlag = 0;
    score = 0;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
    input = 0;
    exitFlag = 0;
    loseFlag = 0;
    score = 0;
}

// do you need a destructor? no
GameMechs::~GameMechs()
{
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
    return *this;
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
    chk_esc();
}

void GameMechs::chk_esc() {
    if (input == 27) {
        setExitTrue();
    }
}

void GameMechs::clearInput()
{
    input = 0;
}

void GameMechs::generateFood(const objPosArrayList * arr) {
    int f = 0, y, x;
    while (!f) {
        f = 1;
        y = rand() % (boardSizeY - 2) + 1, x = rand() % (boardSizeX - 2) + 1;
        for (int i = 0; i < arr->getSize(); ++i) {
            objPos t = arr->getElement(i);
            int ty = t.pos->y, tx = t.pos->x;
            if (ty == y && tx == x) {
                f = 0;
                break;
            }
        }
    }
    food = objPos(x, y, '$');
}

objPos GameMechs::getFoodPos() const {
    return objPos(food);
}