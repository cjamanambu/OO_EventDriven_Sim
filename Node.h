//
// Created by CJ on 2017-03-08.
//

#include <cstdlib>
#include "ListItem.h"

#ifndef INC_2150_A2_NODE_H
#define INC_2150_A2_NODE_H


class Node{

private:
    ListItem* data;
    Node *next;

public:
    Node();
    ~Node();
    Node(ListItem* data);
    ListItem *getData();
    Node *getNext();
    void setNext(Node *next);
    void setData(ListItem* data);
};


#endif //INC_2150_A2_NODE_H
