all: tester

tester: test.cc tree.o
	g++ -o tester test.cc tree.o

tree.o: tree.cc tree.h
	g++ -o tree.o -c tree.cc
