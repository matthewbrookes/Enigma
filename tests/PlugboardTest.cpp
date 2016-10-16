#include "../catch.hpp"
#include "../Plugboard.hpp"

TEST_CASE("Parse empty plugboard file", "[plugboard]") {
  Plugboard plugboard("./plugboards/null.pb");
}

TEST_CASE("Parse plugboard file", "[plugboard]") {
  Plugboard plugboard("./plugboards/V.pb");
}

TEST_CASE("No change in mapping for empty plugboard", "[plugboard]") {
  Plugboard plugboard("./plugboards/null.pb");
  for (char letter = 'A'; letter <= 'Z'; letter++) {
    REQUIRE(plugboard.encrypt(letter) == letter);
  }
}

TEST_CASE("Plugboard maps characters together", "[plugboard]") {
  Plugboard plugboard("./plugboards/III.pb");
  REQUIRE(plugboard.encrypt('X') == 'I');
  REQUIRE(plugboard.encrypt('I') == 'X');
  REQUIRE(plugboard.encrypt('U') == 'W');
  REQUIRE(plugboard.encrypt('W') == 'U');
  REQUIRE(plugboard.encrypt('S') == 'Q');
  REQUIRE(plugboard.encrypt('Q') == 'S');
  REQUIRE(plugboard.encrypt('Y') == 'C');
  REQUIRE(plugboard.encrypt('C') == 'Y');
  REQUIRE(plugboard.encrypt('J') == 'M');
  REQUIRE(plugboard.encrypt('M') == 'J');
  REQUIRE(plugboard.encrypt('A') == 'A');
  REQUIRE(plugboard.encrypt('B') == 'B');
  REQUIRE(plugboard.encrypt('V') == 'V');
  REQUIRE(plugboard.encrypt('Z') == 'Z');
}
