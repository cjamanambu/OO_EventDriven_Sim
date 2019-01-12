//
// Created by CJ on 2017-03-08.
//

#include "PriorityList.h"
// describes the declaration in header "PriorityList.h"

// implements a compare when two Events have the same times
int PriorityList::compare(Event * data, Event * curr){
    int result = 0;
    if(data->getTime() == curr->getTime()){
        // runs a comparison based on Event type otherwise it considers the IDs.
        // the conditions truth values determine the value of the result of the comparisons
        if(dynamic_cast<TimeoutEvent*>(data) && dynamic_cast<ArrivalEvent*>(curr))
            result = 1;
        else if(dynamic_cast<ArrivalEvent*>(data) && dynamic_cast<TimeoutEvent*>(curr))
            result = -1;
        else{
            if(data->getProcess()->getID() > curr->getProcess()->getID())
                result = 1;
            else if(data->getProcess()->getID() < curr->getProcess()->getID())
                result = -1;
        }
    }
    return result;
}

// implements an insert that prioritizes time
void PriorityList::enqueue(Event *data) {

    Node *node = new Node(data);
    Node *curr, *prev;
    bool found = false;
    int result = 0;
    Event * currEvent = NULL;

    if(isEmpty()){
        node->setNext(node);
        end = node;
    }
    else{
        curr = end->getNext();
        prev = end;
        // loop through the queue if it isn't empty
        do{
            currEvent = dynamic_cast<Event*>(curr->getData());
            // if the time of the Event to be inserted is less than the current Event in our iteration the loop ends,
            // otherwise if they are equal it runs extra comparisons, the loop is advanced a single step or not based on
            // where the insertion is to take place. The loop continues if none are the case.
            if(data->getTime() < currEvent->getTime())
                found = true;
            else if(data->getTime() == currEvent->getTime()){
                result = compare(data, currEvent);
                if(result > 0){
                    prev = curr;
                    curr = curr->getNext();
                } else
                    found = true;
            }
            else{
                prev = curr;
                curr = curr->getNext();
            }
        }while(curr != end->getNext() && !found);
        // always insert in front of curr and behind prev,
        // if the Event to be inserted has the largest time insert behind
        node->setNext(curr);
        prev->setNext(node);
        if(!found)
            end = node;
    }
}