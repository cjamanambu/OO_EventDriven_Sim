# a sample Makefile

CC = clang++
CFLAGS = -g -Wall

PROG = A2
HDRS = Event.h IntItem.h List.h ListItem.h Node.h PriorityList.h Process.h Simulation.h
SRCS = A2main.cpp Event.cpp IntItem.cpp List.cpp ListItem.cpp Node.cpp PriorityList.cpp Process.cpp Simulation.cpp

OBJDIR = object
OBJS = $(OBJDIR)/A2main.o $(OBJDIR)/Event.o $(OBJDIR)/IntItem.o $(OBJDIR)/List.o $(OBJDIR)/ListItem.o $(OBJDIR)/Node.o $(OBJDIR)/PriorityList.o $(OBJDIR)/Process.o $(OBJDIR)/Simulation.o

# compiling rules

# WARNING: *must* have a tab before each definition
$(PROG): $(OBJS) $(OBJDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROG)

$(OBJDIR)/A2main.o: A2main.cpp $(HDRS) $(OBJDIR)
	$(CC) $(CFLAGS) -c A2main.cpp -o $(OBJDIR)/A2main.o
	
$(OBJDIR)/Event.o: Event.cpp $(HDRS) $(OBJDIR)
	$(CC) $(CFLAGS) -c Event.cpp -o $(OBJDIR)/Event.o

$(OBJDIR)/IntItem.o: IntItem.cpp $(HDRS) $(OBJDIR)
	$(CC) $(CFLAGS) -c IntItem.cpp -o $(OBJDIR)/IntItem.o

$(OBJDIR)/List.o: List.cpp $(HDRS) $(OBJDIR)
	$(CC) $(CFLAGS) -c List.cpp -o $(OBJDIR)/List.o
	
$(OBJDIR)/ListItem.o: ListItem.cpp $(HDRS) $(OBJDIR)
	$(CC) $(CFLAGS) -c ListItem.cpp -o $(OBJDIR)/ListItem.o

$(OBJDIR)/Node.o: Node.cpp $(HDRS) $(OBJDIR)
	$(CC) $(CFLAGS) -c Node.cpp -o $(OBJDIR)/Node.o

$(OBJDIR)/PriorityList.o: PriorityList.cpp $(HDRS) $(OBJDIR)
	$(CC) $(CFLAGS) -c PriorityList.cpp -o $(OBJDIR)/PriorityList.o
	
$(OBJDIR)/Process.o: Process.cpp $(HDRS) $(OBJDIR)
	$(CC) $(CFLAGS) -c Process.cpp -o $(OBJDIR)/Process.o

$(OBJDIR)/Simulation.o: Simulation.cpp $(HDRS) $(OBJDIR)
	$(CC) $(CFLAGS) -c Simulation.cpp -o $(OBJDIR)/Simulation.o

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -f $(PROG) $(OBJS)
