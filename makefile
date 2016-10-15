ENIGMAOBJECTS = Rotor.o Reflector.o
TESTOBJECTS   = ReflectorTest.o RotorTest.o

enigma: Main.o $(ENIGMAOBJECTS)
	g++ -o enigma $(ENIGMAOBJECTS)

Main.o: Main.cpp
	g++ -c Main.cpp

clean:
	rm -rf enigma test *.o

test: catch.o $(ENIGMAOBJECTS) $(TESTOBJECTS)
	g++ -o test catch.o $(ENIGMAOBJECTS) $(TESTOBJECTS)
	
catch.o: catch.cpp

ReflectorTest.o: ./tests/ReflectorTest.cpp Reflector.hpp Reflector.cpp
	g++ -c ./tests/ReflectorTest.cpp -o ReflectorTest.o

Reflector.o: Reflector.cpp Reflector.hpp
	g++ -c Reflector.cpp Reflector.hpp

Rotor.o: Rotor.cpp Rotor.hpp
	g++ -c Rotor.cpp Rotor.hpp

RotorTest.o: ./tests/RotorTest.cpp Rotor.hpp Rotor.cpp
	g++ -c ./tests/RotorTest.cpp -o RotorTest.o

.PHONY: clean
