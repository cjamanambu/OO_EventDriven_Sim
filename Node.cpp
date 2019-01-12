//
// Created by CJ on 2017-03-08.
//

#include "Node.h"

Node::Node(){}

Node::~Node(){}

Node::Node(ListItem *data) {
    this->data = data;
}

ListItem *Node::getData() {
    return data;
}

Node * Node::getNext() {
    return next;
}

void Node::setNext(Node *next) {
    this->next = next;
}

void Node::setData(ListItem *data) {
    this->data = data;
}