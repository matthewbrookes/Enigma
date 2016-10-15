#include "Reflector.hpp"

char Reflector::reflect(char input) {
  // PRE: input is an upper case character
  char alphabeticalPosition = input - 'A';
  char reflectedPosition = (alphabeticalPosition + 13) % 26;
  char reflectedLetter = reflectedPosition + 'A';
  return reflectedLetter;
}
