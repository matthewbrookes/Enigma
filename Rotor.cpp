#include "Rotor.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <regex>

Rotor::Rotor(std::string fileName) {
  std::ifstream rotorFile;
  rotorFile.open(fileName);
  if (rotorFile.is_open()) {
    int counter = 0;
    std::regex pair("(\\d+)");
    std::string line;
    getline(rotorFile, line);
    for (std::sregex_iterator i = std::sregex_iterator(line.begin(),
                                                       line.end(),
                                                       pair);
         i != std::sregex_iterator();
         i++) {
      std::smatch m = *i;
      wiringPairs.insert({counter, stoi(m.str())});
      counter++;
    }
  } else {
    std::cerr << "Unable to open rotor file " << fileName << std::endl;
    std::terminate();
  }
  rotorFile.close();
}

char Rotor::encryptForward(char input) {
  return wiringPairs[input - 'A'] + 'A';
}

char Rotor::encryptBackward(char input) {
  for (int i = 0; i < wiringPairs.size(); i++) {
    if (wiringPairs[i] == input - 'A') {
      return i + 'A';
    }
  }
}

int wrapAroundZeroBasedAlphabet(int x) {
  int range_size = 26;
  if (x < 0) {
    x += range_size * ((-x) / range_size + 1);
  }
  return x % range_size;
}

bool Rotor::rotate(void) {
  std::unordered_map<int, int> newWiringPairs;
  for (int i = 0; i < 26; i++) {
    int newTarget = wrapAroundZeroBasedAlphabet(
                        wiringPairs[wrapAroundZeroBasedAlphabet(i + 1)] - 1);
    newWiringPairs.insert({i, newTarget});
  }
  wiringPairs = newWiringPairs;
  rotations++;
  if (rotations == 26) {
    rotations = 0;
    return true;
  }
  return false;
}
