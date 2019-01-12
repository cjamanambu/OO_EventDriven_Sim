//
//-----------------------------------------
// NAME		: Onyedika Amanambu
// STUDENT NUMBER	: 7762828
// COURSE		: COMP 2150
// INSTRUCTOR	: Gord Boyer
// ASSIGNMENT	: assignment #2
// QUESTION	: question #1
//
// REMARKS: This program implements the Process child of the ListItem parent.
// It describes the id, the arrival time of the process, how long it waits to be processed through,
// the time it exits, the total number of bursts under each category and a List of the bursts.
//
//-----------------------------------------//


#include "List.h"
#include "IntItem.h"
#ifndef INC_2150_A2_PROCESS_H
#define INC_2150_A2_PROCESS_H


class Process:public ListItem{

private:
    // instance variables that help describe Process behaviour
    int id;
    int arrivalTime, waitTime, exitTime, cpuTime, io1Time, io2Time;
    List * bursts;

public:
    static int processID;

    // Process constructors and destructor
    Process();
    Process(int arrivalTime);
    ~Process();

    // accessors for instance variables
    int getID();
    int getTime();
    int getCPUTime();
    int getIO1Time();
    int getIO2Time();
    int getWaitTime();
    int getExitTime();
    int getNextBurst();
    int viewNextBurst();
    List * getBurstList();

    // mutators for the instance variables
    void setID(int id);
    void setNextBurst(ListItem *burst);
    void setCPUTime(int time);
    void setIO1Time(int time);
    void setIO2Time(int time);
    void setWaitTime(int time);
    void setExitTime(int time);

    // add to the burst list
    void addBursts(ListItem *burst);

    void print();
};



#endif //INC_2150_A2_PROCESS_H
