#ifndef CENIGMA_MB5715_ROTOR_HPP
#define CENIGMA_MB5715_ROTOR_HPP

#include <string>
#include <unordered_map>

class Rotor {
  public:
    Rotor(std::string fileName);
    char encryptForward(char input);
    char encryptBackward(char input);
    bool rotate(void);
  private:
    int rotations = 0;
    std::unordered_map<int, int> wiringPairs;
};


#endif //CENIGMA_MB5715_ROTOR_HPP
