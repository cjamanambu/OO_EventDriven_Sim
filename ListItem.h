
//-----------------------------------------
// NAME		: Onyedika CJ Amanambu
// STUDENT NUMBER	: 7762828
// COURSE		: COMP 2150
// INSTRUCTOR	: Gord Boyer
// ASSIGNMENT	: assignment #2
// QUESTION	: question #1
//
// REMARKS: This program implements the abstract parent class for 3 subclasses; IntItem, Process, Event
// and provides a declaration of their general behaviour
//
//
//-----------------------------------------//
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

#ifndef INC_2150_A2_LISTITEM_H
#define INC_2150_A2_LISTITEM_H


class ListItem {

public:
    // pure abstract variable, default constructors and destructors for sub class implementation
    virtual void print() = 0;
    ListItem();
    virtual ~ListItem();
};

#endif //INC_2150_A2_LISTITEM_H
