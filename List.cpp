//
// Created by CJ on 2017-03-08.
//

#include "List.h"
// decriptions for the declarations in "List.h"

// constructor
List::List() {
    end = NULL;
}

// returns true if List is empty
bool List::isEmpty() {
    return end == NULL;
}

// insert data into the end of the List
void List::enqueue(ListItem *data) {

    Node *node = new Node(data);

    // if List is empty then data should point at it self
    // otherwise add to the end
    if(isEmpty())
        node->setNext(node);
    else{
        node->setNext(end->getNext());
        end->setNext(node);
    }
    end = node;
}

// returns Node at the start of the list
Node *List::front() {
    return end->getNext();
}

// changes the first element in the List to data
void List::setFrontData(ListItem *data) {
    if(!isEmpty())
        end->getNext()->setData(data);
}

// remove the element at the front of the list and delete it
Node *List::dequeue() {

    Node *front = NULL;

    if(!isEmpty()){
        front = end->getNext();
        // if there is only one node left empty the queue
        if(end->getNext() == end){
            delete end->getNext();
            end = NULL;
        }
        else
            end->setNext(end->getNext()->getNext());
    }
    return front;
}