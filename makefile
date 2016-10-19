ENIGMAOBJECTS = Rotor.o Reflector.o Plugboard.o Enigma.o
TESTOBJECTS   = ReflectorTest.o RotorTest.o PlugboardTest.o EnigmaTest.o

enigma: Main.o $(ENIGMAOBJECTS)
	g++ -std=c++11 -o enigma $(ENIGMAOBJECTS)

Main.o: Main.cpp
	g++ -std=c++11 -c Main.cpp

clean:
	rm -rf enigma test *.o

test: catch.o $(ENIGMAOBJECTS) $(TESTOBJECTS)
	g++ -std=c++11 -o test catch.o $(ENIGMAOBJECTS) $(TESTOBJECTS)
	
catch.o: catch.cpp

ReflectorTest.o: ./tests/ReflectorTest.cpp
	g++ -std=c++11 -c ./tests/ReflectorTest.cpp -o ReflectorTest.o

Reflector.o: Reflector.cpp Reflector.hpp
	g++ -std=c++11 -c Reflector.cpp Reflector.hpp

Rotor.o: Rotor.cpp Rotor.hpp
	g++ -std=c++11 -c Rotor.cpp Rotor.hpp

RotorTest.o: ./tests/RotorTest.cpp
	g++ -std=c++11 -c ./tests/RotorTest.cpp -o RotorTest.o

Plugboard.o: Plugboard.cpp Plugboard.hpp
	g++ -std=c++11 -c Plugboard.cpp Plugboard.hpp

PlugboardTest.o: ./tests/PlugboardTest.cpp
	g++ -std=c++11 -c ./tests/PlugboardTest.cpp -o PlugboardTest.o

Enigma.o: Enigma.cpp Enigma.hpp
	g++ -std=c++11 -c Enigma.cpp Enigma.hpp

EnigmaTest.o: ./tests/EnigmaTest.cpp
	g++ -std=c++11 -c tests/EnigmaTest.cpp
.PHONY: clean
