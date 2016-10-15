#include "../catch.hpp"
#include "../Rotor.hpp"

TEST_CASE("Parse rotor file", "[rotor]") {
  Rotor rotor("./rotors/I.rot");
  REQUIRE(rotor.getMappedCharacter('A') == 'B');
  REQUIRE(rotor.getMappedCharacter('M') == 'N');
  REQUIRE(rotor.getMappedCharacter('Z') == 'A');
}

TEST_CASE("Rotate on encryption", "[rotor]") {
  Rotor rotor("./rotors/I.rot");
  REQUIRE(rotor.encrypt('A', true) == (std::pair<char, bool>('B', false)));
  REQUIRE(rotor.encrypt('A', true) == (std::pair<char, bool>('C', false)));
  REQUIRE(rotor.encrypt('C', true) == (std::pair<char, bool>('F', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('I', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('J', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('K', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('L', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('M', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('N', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('O', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('P', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('Q', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('R', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('S', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('T', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('U', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('V', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('W', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('X', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('Y', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('Z', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('A', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('B', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('C', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('D', false)));
  REQUIRE(rotor.encrypt('E', true) == (std::pair<char, bool>('E', true)));
}
