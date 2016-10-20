#include "Enigma.hpp"
#include <iostream>
#include <fstream>
#include <regex>

int main(int argc, char **argv)
{
  std::vector<Rotor> rotorSet;
  Reflector reflector;

  for (int i = 1; i < argc - 1; i++) {
    // Iterate over arguments pointing to rotors
    char *arg = argv[i];
    Rotor rotor(arg);
    rotorSet.push_back(rotor);
  }

  Plugboard plugboard(argv[argc - 1]);

  Enigma enigma(rotorSet, plugboard, reflector);

  std::string plaintext;
  for (std::string line; std::getline(std::cin >> std::ws, line);) {
    // Walk string checking all letters uppercase
    for (char letter: line) {
      if (isupper(letter)) {
        plaintext.push_back(letter);
      } else if (!isspace(letter)) {
        std::cerr << "Entered invalid character" << std::endl;
        return 1;
      }
    }
  }
  // Encrypt and output on stdout
  std::cout << enigma.encrypt(plaintext) << std::endl;
  return 0;
}
