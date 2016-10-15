#include "Rotor.hpp"
#include <string>
#include <iostream>
#include <fstream>

Rotor::Rotor(std::string fileName) {
  std::ifstream rotorFile;
  rotorFile.open(fileName);
  if (rotorFile.is_open()) {
    std::string line;
    char letter = 'A';
    while (getline(rotorFile, line, ' ')) {
      charMap.insert({letter, std::stoi(line) + 'A'});
      letter++;
    }
  } else {
    std::cerr << "Unable to open rotor file " << fileName << std::endl;
    std::terminate();
  }
  rotorFile.close();
}

char Rotor::getMappedCharacter(char input) {
  return charMap[input];
}
