#include "objPos.h"

objPos::objPos() // default constructor
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym)  // extra inputs constructor
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos::objPos(const objPos & rhs)  // copy constructor
{
    pos = new Pos;
    pos->x = rhs.pos->x;
    pos->y = rhs.pos->y;
    symbol = rhs.symbol;
}

objPos & objPos::operator=(const objPos & rhs) // copy assignment operator
{
    if (this == &rhs) {
        return *this;
    }
    if (pos) {
        delete pos;
    }
    pos = new Pos;
    pos->x = rhs.pos->x;
    pos->y = rhs.pos->y;
    symbol = rhs.symbol;
    return *this;
}

objPos::~objPos() // destructor
{
    delete pos;
}

void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;

    return returnPos;
}

char objPos::getSymbol() const
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
