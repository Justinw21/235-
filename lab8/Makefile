main: main.o funcs.o
	g++ -o main main.o funcs.o
	
tests: tests.o funcs.o
	g++ -o tests tests.o funcs.o

funcs.o: funcs.cpp funcs.h
	g++ -c -std=c++11 funcs.cpp

main.o: main.cpp funcs.h
	g++ -c -std=c++11 main.cpp

tests.o: tests.cpp doctest.h funcs.h
	g++ -c -std=c++11 tests.cpp

clean:
	rm -f *.o main tests