# OO_EventDriven_Sim

- Run make from within the cmake-build-debug directory to build an executable called A2
- Run the program with command ./ A2 <"filename.ext"> in the command line

The program simulates an Event driven simulation on several Processes using Object Orientation concepts. 

The program initially calls a static Simulation runSimulation method which accepts a filename as a command-line argument.
This in-turn calls getNextArrival, which reads Processes from the file and runs the arrival Event on the Processes.
Running an arrival Event queues up the CPU Event for the Process on the eventList which causes either an exit Event or a
Timeout/Complete CPU Event to be queued up and so on. 

The Program uses a circular linked list ADT with queue-like behaviour to store Processes. Events are stored in a child of
this ADT which prioritizes time when storing the objects. The Processes and Events are subclasses of the ListItem class 
which is a data member of the Node class used to build the ADTs. 

When the simulation concludes, the statistics of all the Processes are printed before they are each deleted. 
The data file is then closed at this point.  
