#ifndef CENIGMA_MB5715_PLUGBOARD_HPP
#define CENIGMA_MB5715_PLUGBOARD_HPP

#include <unordered_map>

class Plugboard {
  public:
    Plugboard(std::string fileName);
  private:
    std::unordered_map<char, char> charMap;
};


#endif //CENIGMA_MB5715_PLUGBOARD_HPP
