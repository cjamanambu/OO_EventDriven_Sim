//
// Created by CJ on 2017-03-08.
//

#include "Process.h"
// descriptions for the declarations in "Process.h"
Process::Process() {}
Process::~Process() {}

Process::Process(int arrivalTime) {
    // initialize the instance variables of the Process class.
    // Sets the arrival time to the time passed in.
    this->arrivalTime = arrivalTime;
    id = 0;
    cpuTime = 0;
    io1Time = 0;
    io2Time = 0;
    waitTime = 0;
    exitTime = 0;
    bursts = new List;
}

// accessors and mutators of the instance variables for the Process objects
int Process::getID() {
    return id;
}
int Process::getTime() {
    return arrivalTime;
}
int Process::getExitTime(){
    return exitTime;
}
int Process::getWaitTime() {
    return waitTime;
}
int Process::getCPUTime() {
    return cpuTime;
}
int Process::getIO1Time() {
    return io1Time;
}
int Process::getIO2Time() {
    return io2Time;
}
List * Process::getBurstList() {
    return bursts;
}
void Process::setID(int id) {
    this->id = id;
}
void Process::setCPUTime(int time) {
    cpuTime = time;
}
void Process::setIO1Time(int time) {
    io1Time = time;
}
void Process::setIO2Time(int time) {
    io2Time = time;
}
void Process::setExitTime(int time) {
    exitTime = time;
}
void Process::setWaitTime(int time) {
    waitTime = time;
}

// add bursts to the end of the burst
void Process::addBursts(ListItem *burst){
    bursts->enqueue(burst);
}

// removes the element at the front of the queue of bursts and returns it
int Process::getNextBurst() {
    int value = 0;
    IntItem* val = dynamic_cast<IntItem*>(bursts->dequeue()->getData());
    if(val)
        value = val->getValue();
    return value;
}

// returns the element at the front of the queue of bursts without altering it
int Process::viewNextBurst() {
    int value = 0;
    IntItem* val = dynamic_cast<IntItem*>(bursts->front()->getData());
    if(val)
        value = val->getValue();
    return value;
}

// changes the element at the front of the parameter
void Process::setNextBurst(ListItem *burst) {
    bursts->setFrontData(burst);
}

void Process::print() {}