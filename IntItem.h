//
//-----------------------------------------
// NAME		: Onyedika CJ Amanambu
// STUDENT NUMBER	: 7762828
// COURSE		: COMP 2150
// INSTRUCTOR	: Gord Boyer
// ASSIGNMENT	: assignment #2
// QUESTION	: question #1
//
// REMARKS: This implements the Integer Item child of the ListItem parent object.
// It accepts an integer value and creates its corresponding Integer object.
//
//
//-----------------------------------------
//

#include "ListItem.h"
#ifndef INC_2150_A2_INTITEM_H
#define INC_2150_A2_INTITEM_H


class IntItem:public ListItem{

private:
    // describes the integer value to be created
    int value;

public:
    // constructors, destructor and accessors
    IntItem();
    IntItem(int value);
    ~IntItem();
    int getValue();
    void print();
};


#endif //INC_2150_A2_INTITEM_H
