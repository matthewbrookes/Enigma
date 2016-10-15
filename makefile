# edit this makefile so that running make compiles your enigma program

enigma: Main.o
	g++ -o enigma Main.o

Main.o: Main.cpp
	g++ -c Main.cpp

clean:
	rm -rf enigma test *.o

test: catch.o ReflectorTest.o Reflector.o
	g++ -o test catch.o ReflectorTest.o Reflector.o
	
catch.o: catch.cpp

ReflectorTest.o: ./tests/ReflectorTest.cpp
	g++ -c ./tests/ReflectorTest.cpp -o ReflectorTest.o

Reflector.o: Reflector.cpp Reflector.hpp
	g++ -c Reflector.cpp Reflector.hpp

.PHONY: clean
