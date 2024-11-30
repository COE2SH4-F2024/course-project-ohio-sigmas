#include "Player.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPos.setObjPos(1, 1, '@');
    // more actions to be included
}

Player::~Player()
{
    // delete any heap members here
}

Player::Player(const Player & rhs) {
    mainGameMechsRef = rhs.mainGameMechsRef;
    playerPos = rhs.playerPos;
    myDir = rhs.myDir;
}

Player & Player::operator=(const Player & rhs) {
    playerPos = rhs.playerPos;
    myDir = rhs.myDir;
}

objPos Player::getPlayerPos() const
{
    return objPos(playerPos);
}

void Player::updatePlayerDir()
{
    char c = mainGameMechsRef->getInput();
    if (c >= 'a' && c <= 'z') {
        c += ('A' - 'a');
    }
    if (c == 'W') {
        myDir = UP;
    } else if (c == 'S') {
        myDir = DOWN;
    } else if (c == 'A') {
        myDir = LEFT;
    } else if (c == 'D') {
        myDir = RIGHT;
    } 
}

void Player::movePlayer()
{
    int n = mainGameMechsRef->getBoardSizeX(), m = mainGameMechsRef->getBoardSizeY();
    int y = playerPos.pos->y, x = playerPos.pos->x;
    if (myDir == UP) {
        --y;
        if (y == 0) {
            y = n - 1;
        }
    } else if (myDir == DOWN) {
        ++y;
        if (y == n) {
            y = 1;
        }
    } else if (myDir == RIGHT) {
        ++x;
        if (x == m) {
            x = 1;
        }
    } else if (myDir == LEFT) {
        --x;
        if (x == 0) {
            x = m - 1;
        }
    }
    playerPos.setObjPos(objPos(y, x, '@'));
}

// More methods to be added