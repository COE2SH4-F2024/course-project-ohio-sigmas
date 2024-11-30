#include "objPosArrayList.h"
// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.

objPosArrayList::objPosArrayList() {
    arrayCapacity = 20 + 3;
    aList = new objPos[arrayCapacity];
    listSize = 0;
}

objPosArrayList::~objPosArrayList() {
    delete[] aList;
}

void objPosArrayList::_A() {
    // allocates new memory in case old vector does not have enough space
    arrayCapacity *= 2; // sets new vector size to 2 times old vector size
    objPos *t = new objPos[arrayCapacity]; // get temporary vector to hold array elements
    for (int i = 0; i < listSize; ++i) { // for all elements
        t[i] = aList[i]; // sets elements
    }
    delete[] aList; // delete former list
    aList = t; // sets pointer to be the same
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
}

void objPosArrayList::removeTail() {
    --listSize;
}

objPos objPosArrayList::getHeadElement() const {
    return aList[0];
}

objPos objPosArrayList::getTailElement() const {
    return aList[listSize - 1];
}

objPos objPosArrayList::getElement(int ind) const {
    return aList[ind];
}