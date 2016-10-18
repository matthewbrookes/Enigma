#include "Rotor.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <regex>

Rotor::Rotor(std::string fileName) {
  std::ifstream rotorFile;
  rotorFile.open(fileName);
  if (rotorFile.is_open()) {
    // Create forward and backward wheel mapping
    for (int i = 0; i < 26; i++) {
      forwardWheelMapping.insert({'A' + i, i});
      backwardWheelMapping.insert({'A' + i, i});
    }
    std::string line = "";
    char letter = 'A';
    int counter = 0;
    std::regex pair("(\\d+)");
    getline(rotorFile, line);
    for (std::sregex_iterator i = std::sregex_iterator(line.begin(),
                                                       line.end(),
                                                       pair);
         i != std::sregex_iterator();
         i++) {
      std::smatch m = *i;
      forwardCharMap.insert({counter, stoi(m.str()) + 'A'});
      backwardCharMap.insert({stoi(m.str()), counter + 'A'});
      counter++;
    }
  } else {
    std::cerr << "Unable to open rotor file " << fileName << std::endl;
    std::terminate();
  }
  rotorFile.close();
}

char Rotor::getForwardMappedCharacter(int index) {
  return forwardCharMap[index];
}

char Rotor::getBackwardMappedCharacter(int index) {
  return backwardCharMap.at(index);
}

char Rotor::encryptForward(char input) {
  int index = forwardWheelMapping[input];
  return getForwardMappedCharacter(index);
}

char Rotor::encryptBackward(char input) {
  int index = backwardWheelMapping[input];
  return getBackwardMappedCharacter(index);
}

bool Rotor::rotate(void) {
  // Returns true when completed a full rotation
  forwardWheelMapping.clear();
  backwardWheelMapping.clear();
  rotations++;
  for (char i='A'; i <= 'Z'; i++) {
    forwardWheelMapping.insert({i, i - 'A' + rotations});
    if (i - rotations - 'A' < 0) {
      backwardWheelMapping.insert({i, 26 - rotations + i - 'A'});
    } else {
      backwardWheelMapping.insert({i, (i - 'A' - rotations)});
    }
  }
  std::unordered_map<int, char> newForwardCharMap;
  newForwardCharMap[0] = forwardCharMap[25];
  for (int i = 1; i <= 25; i++) {
    newForwardCharMap[i] = forwardCharMap[i - 1];
  }
  forwardCharMap = newForwardCharMap;
  std::unordered_map<int, char> newBackwardCharMap;
  for (int i = 0; i < 25; i++) {
    newBackwardCharMap[i] = backwardCharMap[i + 1];
  }
  newBackwardCharMap[25] = backwardCharMap[0];
  backwardCharMap = newBackwardCharMap;
  if (rotations == 26) {
    rotations = 0;
    return true;
  }
  return false;
}
