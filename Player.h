#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "MacUILib.h"


class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();
        Player(const Player & rhs) {assert(false);} // should only have one player
        Player & operator=(const Player & rhs) {assert(false); return *this;} // big big no no
        objPosArrayList * getPlayerPos() const; // Upgrade this in iteration 3.
        void updatePlayerDir();
        void movePlayer();
        void updScreen();
        void drawScreen();

        // More methods to be added here

    private:
        objPosArrayList * playerPos; // Upgrade this in iteration 3.
        enum Dir myDir;
        char ** board;
        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif