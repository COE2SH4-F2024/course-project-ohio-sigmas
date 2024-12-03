#include "Player.h"
#include "MacUILib.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPos = new objPosArrayList;
    playerPos->insertTail(objPos(15, 7, 219)); // char(219) is special all white char
    mainGameMechsRef->generateFood(playerPos);
    int by = mainGameMechsRef->getBoardSizeY(), bx = mainGameMechsRef->getBoardSizeX();
    board = new char * [by];
    for (int i = 0; i < bx; ++i) {
        board[i] = new char[bx];
    }
    int _t = (by > bx) ? by : bx;

    for (int i = 0; i < by; ++i)
    {
        board[i][0] = '#';
        board[i][bx - 1] = '#';
    }
    for (int j = 0; j < bx; ++j)
    {
        board[0][j] = '#';
        board[by - 1][j] = '#';
    }
}

Player::~Player()
{
    delete playerPos;
    int by = mainGameMechsRef->getBoardSizeY(), bx = mainGameMechsRef->getBoardSizeX();
    for (int i = 0; i < by; ++i) {
        delete[] board[i];
    }
    delete[] board;
    // delete any heap members here
}

objPosArrayList * Player::getPlayerPos() const
{
    return playerPos;
}

void Player::updatePlayerDir()
{
    char c = mainGameMechsRef->getInput();
    if (c >= 'a' && c <= 'z') {
        c += ('A' - 'a');
    }
    if (c == 'W' && myDir != DOWN) {
        myDir = UP;
    } else if (c == 'S' && myDir != UP) {
        myDir = DOWN;
    } else if (c == 'A' && myDir != RIGHT) {
        myDir = LEFT;
    } else if (c == 'D' && myDir != LEFT) {
        myDir = RIGHT;
    }
}

void Player::movePlayer()
{
    int n = mainGameMechsRef->getBoardSizeY(), m = mainGameMechsRef->getBoardSizeX();
    int y = playerPos->getHeadElement().pos->y, x = playerPos->getHeadElement().pos->x;
    if (myDir == UP) {
        --y;
        if (y == 0) {
            y = n - 2;
        }
    } else if (myDir == DOWN) {
        ++y;
        if (y == n - 1) {
            y = 1;
        }
    } else if (myDir == RIGHT) {
        ++x;
        if (x == m - 1) {
            x = 1;
        }
    } else if (myDir == LEFT) {
        --x;
        if (x == 0) {
            x = m - 2;
        }
    }
    objPos nxt(x, y, 219), fp = mainGameMechsRef->getFoodPos(); // next position and food position
    int has_f = 0;
    if (nxt.pos->y == fp.pos->y && nxt.pos->x == fp.pos->x) {
        has_f = 1;
    }
    int s_f = 0; // self collission flag
    if (myDir != STOP) {
        for (int i = 0; i < playerPos->getSize(); ++i) {
            objPos t = playerPos->getElement(i);
            if (nxt.pos->y == t.pos->y && nxt.pos->x == t.pos->x) {
                s_f = 1;
                break;
            }
        }
    }
    playerPos->insertHead(objPos(x, y, 219));
    if (s_f) {
        mainGameMechsRef->setLoseFlag();
        mainGameMechsRef->setExitTrue();
    } else if (has_f) {
        mainGameMechsRef->incrementScore();
        mainGameMechsRef->generateFood(playerPos);
    } else {
        playerPos->removeTail();
    }
}

void Player::updScreen() // update movement
{
    int n = mainGameMechsRef->getBoardSizeY(), m = mainGameMechsRef->getBoardSizeX();
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            board[i][j] = ' ';
        }
    }
    int y, x;
    for (int i = 0; i < playerPos->getSize(); ++i) {
        y = playerPos->getElement(i).pos->y, x = playerPos->getElement(i).pos->x;
        board[y][x] = playerPos->getElement(i).symbol;
    }
    y = mainGameMechsRef->getFoodPos().pos->y, x = mainGameMechsRef->getFoodPos().pos->x;
    board[y][x] = mainGameMechsRef->getFoodPos().symbol;
}

void Player::drawScreen() // drawing the scren
{
    MacUILib_printf("Ohio Sigma's Snake Game\n");
    updScreen();
    int n = mainGameMechsRef->getBoardSizeY(), m = mainGameMechsRef->getBoardSizeX();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            MacUILib_printf("%c", board[i][j]);
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Use the wasd keys to control the snake.\n");
    MacUILib_printf("Eat the food '$' to increase your score!\n");
    MacUILib_printf("Your Score: %d\n", mainGameMechsRef->getScore());
}