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

std::pair<char, bool> Rotor::encrypt(char input, bool shouldRotate) {
  // Returns a pair consisting of the encrypted character and a boolean
  // which is true iff the rotor has completed a full rotation
  char encryptedChar = getMappedCharacter(
          ((input - 'A' + rotations) % 26) + 'A');
  if (shouldRotate) {
    rotate();
  }
  if (rotations == 26) {
    rotations = 0;
    return std::pair<char, bool>(encryptedChar, true);
  }
  return std::pair<char, bool>(encryptedChar, false);
}

void Rotor::rotate(void) {
  rotations++;
}
