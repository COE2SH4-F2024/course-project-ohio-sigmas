#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200 // our gameboard is 30x15 so we are not using this

#include "objPos.h"
#include "cassert"

class objPosArrayList
{
    private:
        objPos* aList;
        int listSize;
        int arrayCapacity;
        void _A();
    public:
        objPosArrayList();
        ~objPosArrayList();
        // big no no
        objPosArrayList(const objPosArrayList & rhs) {assert(false);}
        objPosArrayList & operator=(const objPosArrayList & rhs) {assert(false); return *this;}

        int getSize() const;
        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);
        void push_back(const objPos & t);
        void removeHead();
        void removeTail();

        objPos getHeadElement() const;
        objPos getTailElement() const;
        objPos getElement(int index) const;
};

#endif