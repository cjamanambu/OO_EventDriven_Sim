//-----------------------------------------
// NAME		: Onyedika CJ Amanambu
// STUDENT NUMBER	: 7762828
// COURSE		: COMP 2150
// INSTRUCTOR	: Gord Boyer
// ASSIGNMENT	: assignment #2
// QUESTION	: question # 1
//
// REMARKS: This program simulates an event driven simulation on several processes.
// The processes occur at unique times and queue up events according to this time.
// Most Events usually lead to other events being queued up and all are tracked by a queue-like circular linked list
//
//-----------------------------------------


#include <iostream>
#include <cstdlib>
#include "Simulation.h"

using namespace std;

int main(int argc, char *argv[]){
  if(argc < 2){
    cout << "Usage: " << argv[0] << " <file name>\n";
    exit(1);
  }
  cout << "Simulation begins...\n";
  Simulation::runSimulation(argv[1]);
  cout << "\nEnd of processing.\n";
  return 0;
}// main
