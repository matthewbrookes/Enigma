#include "../catch.hpp"
#include "../Rotor.hpp"

TEST_CASE("Parse rotor file", "[rotor]") {
  Rotor rotor("./rotors/I.rot");
  REQUIRE(rotor.getMappedCharacter('A') == 'B');
  REQUIRE(rotor.getMappedCharacter('M') == 'N');
  REQUIRE(rotor.getMappedCharacter('Z') == 'A');
}
