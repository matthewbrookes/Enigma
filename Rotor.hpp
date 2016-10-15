#ifndef CENIGMA_MB5715_ROTOR_HPP
#define CENIGMA_MB5715_ROTOR_HPP

#include <string>
#include <unordered_map>

class Rotor {
  public:
    Rotor(std::string fileName);
    char getMappedCharacter(char input);
    std::pair<char, bool> encrypt(char input, bool shouldRotate);
  private:
    void rotate(void);
    std::unordered_map<char, char> charMap;
    char rotations = 0;
};


#endif //CENIGMA_MB5715_ROTOR_HPP
