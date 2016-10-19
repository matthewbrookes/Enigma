#include "../catch.hpp"
#include "../Enigma.hpp"
#include "../Plugboard.hpp"
#include "../Rotor.hpp"
#include "../Reflector.hpp"

TEST_CASE("Encrypt string using rotor one without plugboard", "[enigma]") {
  Rotor rotor("./rotors/I.rot");
  Plugboard plugboard("./plugboards/null.pb");
  Reflector reflector;
  std::vector<Rotor> rotorSet;
  rotorSet.push_back(rotor);
  Enigma enigma(rotorSet, plugboard, reflector);
  REQUIRE(enigma.encrypt("AAAAAAAAAAAAAAAAAAAAAAAAAAAA") == "NNNNNNNNNNNNNNNNNNNNNNNNNNNN");
}

TEST_CASE("Encrypt string using rotor two without plugboard", "[enigma]") {
  Rotor rotor("./rotors/II.rot");
  Plugboard plugboard("./plugboards/null.pb");
  Reflector reflector;
  std::vector<Rotor> rotorSet;
  rotorSet.push_back(rotor);
  Enigma enigma(rotorSet, plugboard, reflector);
  REQUIRE(enigma.encrypt("AAAAAAAAAAAAAAAAAAAAAAAAAA") == "PLPLPLPLPLPLPLPLPLPLPLPLPL");
}

TEST_CASE("Encrypt string using rotor five without plugboard", "[enigma]") {
  Rotor rotor("./rotors/V.rot");
  Plugboard plugboard("./plugboards/null.pb");
  Reflector reflector;
  std::vector<Rotor> rotorSet;
  rotorSet.push_back(rotor);
  Enigma enigma(rotorSet, plugboard, reflector);
  REQUIRE(enigma.encrypt("KLKLKLKLKLKLKLKLKLKLKLKLKL") == "PKJSRUTBANMJIWVSRNMJISRVUQ");
}

TEST_CASE("Cascading rotos without plugboard", "[enigma]") {
  Rotor rotor1("./rotors/I.rot");
  Rotor rotor2("./rotors/II.rot");
  Plugboard plugboard("./plugboards/null.pb");
  Reflector reflector;
  std::vector<Rotor> rotorSet;
  rotorSet.push_back(rotor1);
  rotorSet.push_back(rotor2);
  Enigma enigma(rotorSet, plugboard, reflector);
  REQUIRE(enigma.encrypt("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA") == "LLLLLLLLLLLLLLLLLLLLLLLLLLPPPPPPPPPPPPPPPPPPPPPPPPPP");
}
