//
//-----------------------------------------
// NAME		: Onyedika CJ Amanambu
// STUDENT NUMBER	: 7762828
// COURSE		: COMP 2150
// INSTRUCTOR	: Gord Boyer
// ASSIGNMENT	: assignment #2
// QUESTION	: question #1
//
// REMARKS: This implements a Priority Queue object child of a List object.
// It only stores Event and describes an enqueue that inserts by prioritizing Event times.
//
//-----------------------------------------//

#ifndef INC_2150_A2_PRIORITYLIST_H
#define INC_2150_A2_PRIORITYLIST_H
#include "List.h"
#include "Event.h"

class PriorityList:public List{

private:
    // compare two events when their times are the same
    int compare(Event * node, Event * curr);
public:
    // insert based on prioritize
    void enqueue(Event *data);

};


#endif //INC_2150_A2_PRIORITYLIST_H
