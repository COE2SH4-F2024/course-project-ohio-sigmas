#include "objPosArrayList.h"
#include "cassert"
#include "stdlib.h"
// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.

objPosArrayList::objPosArrayList() {
    arrayCapacity = 450 + 3;
    aList = new objPos[arrayCapacity];
    listSize = 0;
}

objPosArrayList::~objPosArrayList() {
    delete[] aList;
}

void objPosArrayList::_A() {
    arrayCapacity *= 2;
    objPos *t = new objPos[arrayCapacity];
    for (int i = 0; i < listSize; ++i) {
        t[i] = aList[i];
    }
    delete[] aList;
    aList = t;
}

int objPosArrayList::getSize() const {
    return listSize;
}

void objPosArrayList::insertHead(objPos r) {
    if (arrayCapacity == listSize) {
        _A();
    }
    for (int i = listSize; i > 0; --i) {
        aList[i] = aList[i - 1];
    }
    aList[0] = r;
    ++listSize;
}

void objPosArrayList::push_back(const objPos & r) {
    if (arrayCapacity == listSize) {
        _A();
    }
    aList[listSize] = r;
    ++listSize;
}

void objPosArrayList::insertTail(objPos r) {
    push_back(r);
}

void objPosArrayList::removeHead() {
    if (arrayCapacity == listSize) {
        _A();
    }
    for (int i = 0; i < listSize - 1; ++i) {
        aList[i] = aList[i + 1];
    }
    --listSize;
    listSize += (listSize < 0);
}

void objPosArrayList::removeTail() {
    --listSize;
    listSize += (listSize < 0);
}

objPos objPosArrayList::getHeadElement() const {
    return aList[0];
}

objPos objPosArrayList::getTailElement() const {
    return aList[listSize - 1];
}

objPos objPosArrayList::getElement(int ind) const {
    if (ind >= 0 && ind < listSize) {
        return aList[ind];
    } else {
        // if out of bounds return random element :) ) ) ) )
        return aList[rand() % listSize];
    }
}