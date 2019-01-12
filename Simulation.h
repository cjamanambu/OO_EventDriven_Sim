//
// Created by CJ on 2017-03-08.
//

#ifndef INC_2150_A2_SIMULATION_H
#define INC_2150_A2_SIMULATION_H
#include "PriorityList.h"
#include "ListItem.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
//-----------------------------------------
// NAME		: Onyedika CJ Amanambu
// STUDENT NUMBER	: 7762828
// COURSE		: COMP 2150
// INSTRUCTOR	: Gord Boyer
// ASSIGNMENT	: assignment #2
// QUESTION	: question #1
//
// REMARKS: This implements a static Simulation object which runs our Simulation from a read in data file.
// It contains Lists for Process and Events and describes the Simulations properties.
//
//
//-----------------------------------------

using namespace std;

#define MAX 100

class Simulation {

private:
    // Lists for Processes and PriorityLists for Events
    static List * cpu;
    static List * io1;
    static List * io2;
    static List * processList;
    static PriorityList * eventList;
    static int value;
    static char buffer[MAX];
    static ifstream infile;

public:
    // run the simualtion, accessors and mutators for instance variables,
    // methods describing behaviour of Simulations
    static void runSimulation(char * file);
    static void getNextArrival();
    static void startCPUBurst(Process * process, int time);
    static void startTimeOut(Process * process, int time);
    static void startIO1(Process * process, int time);
    static void startIO2(Process * process, int time);
    static void startCompleteIO1(Process * process, int time);
    static void startCompleteIO2(Process * process, int time);
    static void startCompleteCPU(Process * process, int time);
    static void startExit(Process * process, int time);
    static void exitSim();

    static bool cpuFree();
    static bool io1Free();
    static bool io2Free();

    static List* getCPUList();
    static List* getProcessList();
    static List* getIO1List();
    static List* getIO2List();
    static List* getEventList();

};


#endif //INC_2150_A2_SIMULATION_H
