#include "Enigma.hpp"
#include <iostream>
#include <fstream>
#include <regex>

int main(int argc, char **argv)
{
  std::vector<Rotor> rotorSet;
  Plugboard plugboard;
  Reflector reflector;

  std::regex rotorRegex(".*\\.rot");
  std::regex plugboardRegex(".*\\.pb");
  bool plugboardChosen = false;

  for (int i = 1; i < argc; i++) {
    // Iterate over each argument after program name
    char *arg = argv[i];
    if (std::regex_match(arg, rotorRegex)) {
      Rotor rotor(arg);
      rotorSet.push_back(rotor);
    } else if (std::regex_match(arg, plugboardRegex)) {
      if (!plugboardChosen) {
        plugboard = Plugboard(arg);
        plugboardChosen = true;
      } else {
        std::cerr << "Plugboard already specified" << std::endl;
        return 1;
      }
    }
  }
  if (!plugboardChosen) {
    std::cerr << "Plugboard not specified" << std::endl;
    return 1;
  }

  Enigma enigma(rotorSet, plugboard, reflector);
  std::string line;
  for (std::string line; std::getline(std::cin >> std::ws, line);) {
    // Walk string checking all letters uppercase
    for (char letter: line) {
      if (!(isupper(letter) || isspace(letter))) {
        std::cerr << "Entered invalid character" << std::endl;
        return 1;
      }
    }
    // Encrypt line and ouput on stdout
    std::cout << enigma.encrypt(line) << std::endl;
  }
  return 0;
}
