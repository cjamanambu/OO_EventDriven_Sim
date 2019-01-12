//
// Created by CJ on 2017-03-08.
//

#include "Event.h"
#include "Simulation.h"
// describes the declarations in "Event.h"

// destructor
Event::~Event() {}

// defines mutators, accessors and other default methods
void Event::setTime(int time) {
    eventTime = time;
}
int Event::getTime(){
    return eventTime;
}
void Event::setProcess(Process * process) {
    currentProcess = process;
}
Process* Event::getProcess() {
    return currentProcess;
}
void Event::print() {}
void Event::runEvent() {}

ArrivalEvent::ArrivalEvent() {}
// running an arrival Event causes the next process to be read in,
// it starts a cpu event for the process if the cpu is free. It inserts the process into the cpu list
void ArrivalEvent::runEvent() {
    cout << "Time" << setw(6) << getTime() << ": Process" << setw(4) << getProcess()->getID();
    Simulation::getNextArrival();
    // if cpu list is empty run start cpu burst event
    if(Simulation::cpuFree()){
        cout << " arrives in system: CPU is free (process begins execution)" << endl;
        Simulation::startCPUBurst(getProcess(), getTime());
    }
    else
        cout << " arrives in system: CPU is busy (process will be queued)" << endl;
    Simulation::getCPUList()->enqueue(getProcess());
}

CPUEvent::CPUEvent() {}
int CPUEvent::rem = 0;
// running a cpu Event either starts a timeout or a complete cpu Event based on the current cpu burst
void CPUEvent::runEvent() {
    cout << "Time" << setw(6) << getTime() << ": Process" << setw(4) << getProcess()->getID();
    // view the next burst and find out if it exceeds our time quantum
    // if it does start a timeout Event otherwise start a complete cpu Event
    int cpuBurst = getProcess()->viewNextBurst();
    cout << " begins CPU burst of length " << cpuBurst << endl;
    rem = cpuBurst - TIME_QUANTUM;
    if(rem > 0){
        getProcess()->setCPUTime(getProcess()->getCPUTime() + TIME_QUANTUM);
        Simulation::startTimeOut(getProcess(), getTime() + TIME_QUANTUM);
    }
    else{
        getProcess()->setCPUTime(getProcess()->getCPUTime() + cpuBurst);
        Simulation::startCompleteCPU(getProcess(), getTime() + cpuBurst);
    }
}

TimeoutEvent::TimeoutEvent() {}
// running a timeout Event reduces the Processes' cpu burst by TIME_QUANTUM
// and moves the process to the end of the list.
void TimeoutEvent::runEvent(){
    cout << "Time" << setw(6) << getTime() << ": Process" << setw(4) << getProcess()->getID();
    getProcess()->setNextBurst(new IntItem(CPUEvent::rem));
    cout << " exhausts its time quantum (requires " << CPUEvent::rem << " units more)" << endl;
    Simulation::getCPUList()->dequeue();
    Simulation::getCPUList()->enqueue(getProcess());
    // if the cpu list is not empty start cpu Event for the first Process inside it
    if(!Simulation::cpuFree()){
        Simulation::startCPUBurst(dynamic_cast<Process*>(Simulation::getCPUList()->front()->getData()), getTime());
    }

}

IOEvent1::IOEvent1(){}
// running an i/o 1 Event starts a complete i/o1 Event
void IOEvent1::runEvent() {
    cout << "Time" << setw(6) << getTime() << ": Process" << setw(4) << getProcess()->getID();
    int ioBurst = getProcess()->getNextBurst();
    Simulation::startCompleteIO1(getProcess(), getTime()+ioBurst);
    cout << " begins I/O Device 1 burst of length " << ioBurst << endl;
    getProcess()->setIO1Time(getProcess()->getIO1Time() + ioBurst);
}

IOEvent2::IOEvent2(){}
// running an i/o 2 Event starts a complete 1/o2 Event
void IOEvent2::runEvent() {
    cout << "Time" << setw(6) << getTime() << ": Process" << setw(4) << getProcess()->getID();
    int ioBurst = getProcess()->getNextBurst();
    Simulation::startCompleteIO2(getProcess(), getTime()+abs(ioBurst));
    cout << " begins I/O Device 2 burst of length " << abs(ioBurst) << endl;
    getProcess()->setIO2Time(getProcess()->getIO2Time() + abs(ioBurst));
}

CompleteCPUEvent::CompleteCPUEvent() {}
// running a complete cpu Event removes the first Process in the cpu List and either starts an exit Event or an i/o Event.
// it checks for remaining Processes on the cpu List and starts its cpu Event if any
void CompleteCPUEvent::runEvent() {
    cout << "Time" << setw(6) << getTime() << ": Process" << setw(4) << getProcess()->getID();
    cout << " completes CPU burst.";
    // remove first Process in cpu List, get the next Process burst but if it doesn't exist start an exit Event
    // otherwise start an i/o1 or i/o2 Event based on the burst
    Simulation::getCPUList()->dequeue();
    getProcess()->getNextBurst();
    if(getProcess()->getBurstList()->isEmpty()){
        cout << endl;
        Simulation::startExit(getProcess(), getTime());
    }
    else{
        if(getProcess()->viewNextBurst() < 0){
            cout << " Queueing for I/O Device 2" << endl;
            if(Simulation::io2Free())
                Simulation::startIO2(getProcess(), getTime());
            Simulation::getIO2List()->enqueue(getProcess());
        }
        else if(getProcess()->viewNextBurst() > 0){
            cout << " Queueing for I/O Device 1" << endl;
            if(Simulation::io1Free())
                Simulation::startIO1(getProcess(), getTime());
            Simulation::getIO1List()->enqueue(getProcess());
        }
    }
    // if the cpu list is not empty start cpu Event for the first Process inside it
    if(!Simulation::cpuFree()){
        Simulation::startCPUBurst(dynamic_cast<Process*>(Simulation::getCPUList()->front()->getData()), getTime());
    }
}

CompleteIOEvent1::CompleteIOEvent1(){}
// running a complete i/o1 Event either starts an exit Event or a cpu Event.
// it starts the next i/o1 Event on the eventList
void CompleteIOEvent1::runEvent() {
    cout << "Time" << setw(6) << getTime() << ": Process" << setw(4) << getProcess()->getID();
    cout << " completes I/O Device 1 burst.";
    Simulation::getIO1List()->dequeue();

    if(getProcess()->getBurstList()->isEmpty()){
        cout << endl;
        Simulation::startExit(getProcess(), getTime());
    }
    else{
        cout << " Queueing for CPU." << endl;
        if(Simulation::cpuFree())
            Simulation::startCPUBurst(getProcess(), getTime());
        Simulation::getCPUList()->enqueue(getProcess());
    }
    if(!Simulation::io1Free())
        Simulation::startIO1(dynamic_cast<Process*>(Simulation::getIO1List()->front()->getData()), getTime());
}

CompleteIOEvent2::CompleteIOEvent2() {}
// running a complete i/o2 Event either starts an exit Event or a cpu Event.
// it starts the next i/o2 Event on the eventList
void CompleteIOEvent2::runEvent(){
    cout << "Time" << setw(6) << getTime() << ": Process" << setw(4) << getProcess()->getID();
    cout << " completes I/O Device 2 burst.";
    Simulation::getIO2List()->dequeue();

    if(getProcess()->getBurstList()->isEmpty()){
        cout << endl;
        Simulation::startExit(getProcess(), getTime());
    }
    else{
        cout << " Queueing for CPU." << endl;
        if(Simulation::cpuFree())
            Simulation::startCPUBurst(getProcess(), getTime());
        Simulation::getCPUList()->enqueue(getProcess());
    }
    if(!Simulation::io2Free())
        Simulation::startIO2(dynamic_cast<Process*>(Simulation::getIO2List()->front()->getData()), getTime());
}

ExitEvent::ExitEvent() {}
// running an exit Event calculates the closing statistics for the Process
void ExitEvent::runEvent(){
    cout << "Time" << setw(6) << getTime() << ": Process" << setw(4) << getProcess()->getID();
    int total = getProcess()->getTime() + getProcess()->getCPUTime() + getProcess()->getIO1Time() + getProcess()->getIO2Time();
    getProcess()->setExitTime(getTime());
    getProcess()->setWaitTime(getTime() - total);
    cout << " complete. Total wait time is: " << getProcess()->getWaitTime() << endl;
}