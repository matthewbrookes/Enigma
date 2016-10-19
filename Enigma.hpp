#ifndef CENIGMA_MB5715_ENIGMA_HPP
#define CENIGMA_MB5715_ENIGMA_HPP

#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "Rotor.hpp"
#include <vector>

class Enigma {
public:
    Enigma(std::vector<Rotor> &rotorSet, Plugboard &plugboard, Reflector &reflector);
    std::string encrypt(std::string plaintext);
private:
    std::vector<Rotor> &m_rotorSet;
    Plugboard m_plugboard;
    Reflector m_reflector;
};


#endif //CENIGMA_MB5715_ENIGMA_HPP
