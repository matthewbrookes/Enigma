#include "Plugboard.hpp"
#include <iostream>
#include <fstream>
#include <regex>

Plugboard::Plugboard(std::string fileName) {
  // Create a hash map mapping from each character to itself
  for (char letter = 'A'; letter <= 'Z'; letter++) {
    charMap.insert({letter, letter});
  }
  // Open plugboard file
  std::ifstream plugboardFile;
  plugboardFile.open(fileName);
  if (plugboardFile.is_open()) {
    // Match each pair of numbers
    std::string line;
    std::regex pair("(\\d+ \\d+)");
    while (getline(plugboardFile, line)) {
      for (std::sregex_iterator i = std::sregex_iterator(line.begin(),
                                                         line.end(),
                                                         pair);
          i != std::sregex_iterator();
          ++i) {
        std::smatch m = *i;
        // Tokenise each match by space character
        std::vector<std::string> tokens;
        std::stringstream matchString(m.str());
        std::string temp;
        while (getline(matchString, temp, ' ')) {
          tokens.push_back( temp );
        }
        // Update character mapping
        char firstLetter = std::stoi(tokens[0]) + 'A';
        char secondLetter = std::stoi(tokens[1]) + 'A';
        charMap[firstLetter] = secondLetter;
        charMap[secondLetter] = firstLetter;
      }
    }
  } else {
    std::cerr << "Unable to open plugboard file " << fileName << std::endl;
    std::terminate();
  }
  plugboardFile.close();
}
