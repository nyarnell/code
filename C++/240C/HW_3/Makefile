lawnsim: sim.o lawn.o crew.o main.cc
	g++ -Wall *.o main.cc -o lawnsim -ggdb
sim.o: sim.h sim.cc
	g++ -c -Wall sim.cc
lawn.o: lawn.h lawn.cc
	g++ -c -Wall lawn.cc
crew.o: crew.h crew.cc
	g++ -c -Wall crew.cc

clean:
	rm *~ *.o lawnsim
