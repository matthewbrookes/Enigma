# edit this makefile so that running make compiles your enigma program

enigma: Main.o
	g++ -o enigma Main.o

Main.o: Main.cpp
	g++ -c Main.cpp

clean:
	rm -rf enigma test *.o

test: test.o
	g++ -o test test.o
	
test.o: 
	g++ -c catch.cpp -o test.o

.PHONY: clean
