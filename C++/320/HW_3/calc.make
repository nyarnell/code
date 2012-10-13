Parser: syntactic_analyzer.o LexicalAnalyzer.o main.cc
	g++ *.o main.cc -o Parser
syntactic_analyzer.o: syntactic_analyzer.h syntactic_analyzer.cc LexicalAnalyzer.h
	g++ -c syntactic_analyzer.cc
LexicalAnalyzer.o: LexicalAnalyzer.h LexicalAnalyer.cc
	g++ -c LexicalAnalyzer.cc

	//how do makefiles work lol