ENIGMAOBJECTS = Rotor.o Reflector.o Plugboard.o Enigma.o
TESTOBJECTS   = ReflectorTest.o RotorTest.o PlugboardTest.o EnigmaTest.o
COMPILEFLAGS  = -std=c++11 -Wall -pedantic

enigma: Main.o $(ENIGMAOBJECTS)
	g++ $(COMPILEFLAGS) -o enigma Main.o $(ENIGMAOBJECTS)

Main.o: Main.cpp
	g++ $(COMPILEFLAGS) -c Main.cpp

clean:
	rm -rf enigma test *.o

test: catch.o $(ENIGMAOBJECTS) $(TESTOBJECTS)
	g++ $(COMPILEFLAGS) -o test catch.o $(ENIGMAOBJECTS) $(TESTOBJECTS)
	
catch.o: catch.cpp

ReflectorTest.o: ./tests/ReflectorTest.cpp
	g++ $(COMPILEFLAGS) -c ./tests/ReflectorTest.cpp -o ReflectorTest.o

Reflector.o: Reflector.cpp Reflector.hpp
	g++ $(COMPILEFLAGS) -c Reflector.cpp Reflector.hpp

Rotor.o: Rotor.cpp Rotor.hpp
	g++ $(COMPILEFLAGS) -c Rotor.cpp Rotor.hpp

RotorTest.o: ./tests/RotorTest.cpp
	g++ $(COMPILEFLAGS) -c ./tests/RotorTest.cpp -o RotorTest.o

Plugboard.o: Plugboard.cpp Plugboard.hpp
	g++ $(COMPILEFLAGS) -c Plugboard.cpp Plugboard.hpp

PlugboardTest.o: ./tests/PlugboardTest.cpp
	g++ $(COMPILEFLAGS) -c ./tests/PlugboardTest.cpp -o PlugboardTest.o

Enigma.o: Enigma.cpp Enigma.hpp
	g++ $(COMPILEFLAGS) -c Enigma.cpp Enigma.hpp

EnigmaTest.o: ./tests/EnigmaTest.cpp
	g++ $(COMPILEFLAGS) -c tests/EnigmaTest.cpp
.PHONY: clean
