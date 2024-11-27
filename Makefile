NQueensProblem: NQueensProblem.o
	g++ -g -o NQueensProblem.exe NQueensProblem.o -pthread    

NQueensProblem.o: NQueensProblem/NQueensProblem.cpp
	g++ -g  -c -pthread NQueensProblem/NQueensProblem.cpp
