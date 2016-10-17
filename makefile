ENIGMAOBJECTS = Rotor.o Reflector.o Plugboard.o
TESTOBJECTS   = ReflectorTest.o RotorTest.o PlugboardTest.o

enigma: Main.o $(ENIGMAOBJECTS)
	g++ -std=c++11 -o enigma $(ENIGMAOBJECTS)

Main.o: Main.cpp
	g++ -std=c++11 -c Main.cpp

clean:
	rm -rf enigma test *.o

test: catch.o $(ENIGMAOBJECTS) $(TESTOBJECTS)
	g++ -std=c++11 -o test catch.o $(ENIGMAOBJECTS) $(TESTOBJECTS)
	
catch.o: catch.cpp

ReflectorTest.o: ./tests/ReflectorTest.cpp Reflector.hpp Reflector.cpp catch.o
	g++ -std=c++11 ./tests/ReflectorTest.cpp Reflector.hpp Reflector.cpp catch.o -o ReflectorTest.o

Reflector.o: Reflector.cpp Reflector.hpp
	g++ -std=c++11 -c Reflector.cpp Reflector.hpp

Rotor.o: Rotor.cpp Rotor.hpp
	g++ -std=c++11 -c Rotor.cpp Rotor.hpp

RotorTest.o: ./tests/RotorTest.cpp Rotor.hpp Rotor.cpp catch.o
	g++ -std=c++11 ./tests/RotorTest.cpp Rotor.hpp Rotor.cpp catch.o -o RotorTest.o

Plugboard.o: Plugboard.cpp Plugboard.hpp
	g++ -std=c++11 -c Plugboard.cpp Plugboard.hpp

PlugboardTest.o: ./tests/PlugboardTest.cpp Plugboard.hpp Plugboard.cpp catch.o
	g++ -std=c++11 ./tests/PlugboardTest.cpp Plugboard.hpp Plugboard.cpp catch.o -o PlugboardTest.o

.PHONY: clean
