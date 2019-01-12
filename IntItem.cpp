//
// Created by CJ on 2017-03-08.
//

#include "IntItem.h"
// descriptors for the header file declarations in IntItem.h
IntItem::IntItem() {}

IntItem::~IntItem() {}

IntItem::IntItem(int value) {
    this->value = value;
}

int IntItem::getValue() {
    return value;
}

void IntItem::print() {
    cout << value << endl;
}