#include "Enigma.hpp"
#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "Rotor.hpp"
#include <vector>
#include <iostream>

Enigma::Enigma(std::vector<Rotor> &rotorSet, 
               Plugboard &plugboard, 
               Reflector &reflector)
  : m_rotorSet(rotorSet), m_plugboard(plugboard), m_reflector(reflector) {
}

std::string Enigma::encrypt(std::string plaintext) {
  std::string cipherText;
  for (char letter: plaintext) {
    char afterPlugboard = m_plugboard.encrypt(letter);
    char rotorLetter = afterPlugboard;
    for (auto it = m_rotorSet.begin(); 
         it != m_rotorSet.end(); 
         ++it) {
      rotorLetter = it->encryptForward(rotorLetter);
    }
    char reflectedLetter = m_reflector.reflect(rotorLetter);
    
    rotorLetter = reflectedLetter;
    for (auto it = m_rotorSet.rbegin(); 
         it != m_rotorSet.rend(); 
         ++it) {
      rotorLetter = it->encryptBackward(rotorLetter);
    }
    bool rotateRotor = true;
    for (auto it = m_rotorSet.begin(); 
         it != m_rotorSet.end(); 
         ++it) {
      if (rotateRotor) {
        rotateRotor = it->rotate();
      }
    }

    char cipherChar = m_plugboard.encrypt(rotorLetter);
    cipherText.push_back(cipherChar);
  }
  return cipherText;
}
