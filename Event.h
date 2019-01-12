//
//-----------------------------------------
// NAME		: Onyedika CJ Amanambu
// STUDENT NUMBER	: 7762828
// COURSE		: COMP 2150
// INSTRUCTOR	: Gord Boyer
// ASSIGNMENT	: assignment #2
// QUESTION	: question #1
//
// REMARKS: This implements an Event child of a ListItem parent as an abstract parent of 9 Event subclasses.
// It describes the behaviour of each Event when it is run in the Simulation. It defines all 9 sub classes.
//
//
//-----------------------------------------//

#ifndef INC_2150_A2_EVENT_H
#define INC_2150_A2_EVENT_H

#include "ListItem.h"
#include "Process.h"
#define TIME_QUANTUM 4 // maximum time the cpu can run a burst for


class Event:public ListItem {

private:
    // instance variables of each Event
    int eventTime;
    Process * currentProcess;

public:
    // Event behaviour, destructor, accessors and mutators
    virtual void runEvent() = 0;
    virtual ~Event();
    void print();
    virtual void setTime(int time);
    virtual int getTime();
    virtual Process* getProcess();
    virtual void setProcess(Process * process);

};

// sub class descriptions
class ArrivalEvent:public Event{
public:
    ArrivalEvent();
    void runEvent();
};

class CPUEvent:public Event{
public:
    CPUEvent();
    void runEvent();
    static int rem;
};

class TimeoutEvent:public Event{
public:
    TimeoutEvent();
    void runEvent();
};

class IOEvent1:public Event{
public:
    IOEvent1();
    void runEvent();
};

class IOEvent2:public Event{
public:
    IOEvent2();
    void runEvent();
};

class CompleteCPUEvent:public Event{
public:
    CompleteCPUEvent();
    void runEvent();
};

class CompleteIOEvent1:public Event{
public:
    CompleteIOEvent1();
    void runEvent();
};

class CompleteIOEvent2:public Event{
public:
    CompleteIOEvent2();
    void runEvent();
};

class ExitEvent:public Event{
public:
    ExitEvent();
    void runEvent();
};

#endif //INC_2150_A2_EVENT_H