#ifndef CENIGMA_MB5715_ROTOR_HPP
#define CENIGMA_MB5715_ROTOR_HPP

#include <string>
#include <unordered_map>

class Rotor {
  public:
    Rotor(std::string fileName);
    char getForwardMappedCharacter(int index);
    char getBackwardMappedCharacter(int index);
    char encryptForward(char input);
    char encryptBackward(char input);
    bool rotate(void);
    int rotations = 0;
  private:
    std::unordered_map<char, int> forwardWheelMapping;
    std::unordered_map<char, int> backwardWheelMapping;
    std::unordered_map<int, char> forwardCharMap;
    std::unordered_map<int, char> backwardCharMap;
};


#endif //CENIGMA_MB5715_ROTOR_HPP
