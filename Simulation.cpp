//
// Created by CJ on 2017-03-08.
//

#include "Simulation.h"
// descriptions of the declarations in the header file "Simulation.h"

// initialize the static variables of the Simulation
int Process::processID = 1;
List * Simulation::cpu = new List;
List * Simulation::io1 = new List;
List * Simulation::io2 = new List;
List * Simulation::processList = new List;
PriorityList * Simulation::eventList = new PriorityList;
int Simulation::value;
char Simulation::buffer[MAX];
ifstream Simulation::infile;

// return true or false if the Process Lists are empty
bool Simulation::cpuFree() {
    return cpu->isEmpty();
}
bool Simulation::io1Free() {
    return io1->isEmpty();
}
bool Simulation::io2Free() {
    return io2->isEmpty();
}

// accessors for the Lists in the Simulation
List * Simulation::getCPUList() {
    return cpu;
}
List * Simulation::getEventList() {
    return eventList;
}
List * Simulation::getIO1List() {
    return io1;
}
List * Simulation::getIO2List() {
    return io2;
}
List * Simulation::getProcessList() {
    return processList;
}

// runs the Simulation
void Simulation::runSimulation(char * file){
    Event * temp;
    infile.open(file);
    // read new arrival and run simulation as long as the event list is empty then exits the simulation
    getNextArrival();
    while(!eventList->isEmpty()){
        temp  = dynamic_cast<Event*>(eventList->dequeue()->getData());
        if(temp)
            temp->runEvent();
        delete temp;
    }
    exitSim();
}

// reads and creates the next Process from the data file,
// creates an arrival Event for the Process and inserts them into their respective Lists
void Simulation::getNextArrival() {
    Process * newProcess;
    Event * arrival;
    if(!infile.eof()) {
        infile.getline(buffer, MAX);
        if(buffer[0] != ' '){
            stringstream line(buffer);
            line >> value;
            newProcess = new Process(value);
            while (!line.eof()) {
                // populate the Processes burst List
                line >> value;
                newProcess->addBursts(new IntItem(value));
            }
            newProcess->setID(Process::processID);
            Process::processID++;
            processList->enqueue(newProcess);

            arrival = new ArrivalEvent;
            arrival->setProcess(newProcess);
            arrival->setTime(newProcess->getTime());
            eventList->enqueue(arrival);
        }
    }
}

// queues up the start cpu Event for the Process parameter at the time parameter
void Simulation::startCPUBurst(Process *process, int time) {
    Event * cpuBurst = new CPUEvent;
    cpuBurst->setProcess(process);
    cpuBurst->setTime(time);
    eventList->enqueue(cpuBurst);
}

// queues up the timeout Event for the Process parameter at the time parameter
void Simulation::startTimeOut(Process *process, int time) {
    Event * timeout = new TimeoutEvent;
    timeout->setTime(time);
    timeout->setProcess(process);
    eventList->enqueue(timeout);
}

// queues up the start i/o 1 Event for the Process parameter at the time parameter
void Simulation::startIO1(Process *process, int time) {
    Event * io1 = new IOEvent1;
    io1->setTime(time);
    io1->setProcess(process);
    eventList->enqueue(io1);
}

// queues up the start i/o 2 Event for the Process parameter at the time parameter
void Simulation::startIO2(Process *process, int time) {
    Event * io2 = new IOEvent2;
    io2->setTime(time);
    io2->setProcess(process);
    eventList->enqueue(io2);
}

// queues up the complete cpu Event for the Process parameter at the time parameter
void Simulation::startCompleteCPU(Process *process, int time) {
    Event * completeCPU = new CompleteCPUEvent;
    completeCPU->setProcess(process);
    completeCPU->setTime(time);
    eventList->enqueue(completeCPU);
}

// queues up the complete i/o 1 Event for the Process parameter at the time parameter
void Simulation::startCompleteIO1(Process *process, int time) {
    Event * completeIO1 = new CompleteIOEvent1;
    completeIO1->setProcess(process);
    completeIO1->setTime(time);
    eventList->enqueue(completeIO1);
}

// queues up the complete i/o 2 Event for the Process parameter at the time parameter
void Simulation::startCompleteIO2(Process *process, int time) {
    Event * completeIO2 = new CompleteIOEvent2;
    completeIO2->setProcess(process);
    completeIO2->setTime(time);
    eventList->enqueue(completeIO2);
}

// queues up the exit Event for the Process parameter at the time parameter
void Simulation::startExit(Process *process, int time) {
    Event * exit = new ExitEvent;
    exit->setProcess(process);
    exit->setTime(time);
    eventList->enqueue(exit);
}

// prints all the Processes variables, emptying the List of Processes and closes the data file
void Simulation::exitSim() {
    Process * curr;
    cout << endl;
    cout << "... All Processes complete. Final Summary: " << endl;
    cout << endl;
    cout << "   Process\t Arrival\t   CPU\t\t\tI/O Time\t\tExit\t\tWait" << endl;
    cout << "         #\t    Time\t  Time\t\tDev 1\t\t  Dev 2\t\tTime\t\tTime" << endl;
    cout << "----------------------------------------------------------------------------------------------------"<<endl;
    while(!getProcessList()->isEmpty()){
        curr = dynamic_cast<Process*>(getProcessList()->dequeue()->getData());
        cout << setw(10) << curr->getID();
        cout << setw(14) << curr->getTime();
        cout << setw(14) << curr->getCPUTime();
        cout << setw(15) << curr->getIO1Time();
        cout << setw(16) << curr->getIO2Time();
        cout << setw(15) << curr->getExitTime();
        cout << setw(16) << curr->getWaitTime();
        cout << endl;
        delete curr;
    }
    cout << "----------------------------------------------------------------------------------------------------"<<endl;
    Simulation::infile.close();
}