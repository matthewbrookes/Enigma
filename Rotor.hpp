#ifndef CENIGMA_MB5715_ROTOR_HPP
#define CENIGMA_MB5715_ROTOR_HPP

#include <string>
#include <unordered_map>

class Rotor {
  public:
    Rotor(std::string fileName);
    char getMappedCharacter(char input);
  private:
    std::unordered_map<char, char> charMap;
};


#endif //CENIGMA_MB5715_ROTOR_HPP
