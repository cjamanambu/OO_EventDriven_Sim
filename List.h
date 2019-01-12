//
//-----------------------------------------
// NAME		: Onyedika CJ Amanambu
// STUDENT NUMBER	: 7762828
// COURSE		: COMP 2150
// INSTRUCTOR	: Gord Boyer
// ASSIGNMENT	: assignment #2
// QUESTION	: question #1
//
// REMARKS: This implements a Queue-like List object as a circular linked list with a pointer to the end.
// It also describes and implements the parent behaviour for the Priority List class.
//
//-----------------------------------------//
#include "Node.h"
#include <cstdlib>
#ifndef INC_2150_A2_LIST_H
#define INC_2150_A2_LIST_H


class List{
protected:
    // pointer to the end of the List
    Node *end;

public:
    // List creators, destructors and other behaviours
    List();
    ~List();
    void enqueue(ListItem *data);
    virtual bool isEmpty();
    Node *front();
    void setFrontData(ListItem *data);
    Node *dequeue();
};


#endif //INC_2150_A2_LIST_H
