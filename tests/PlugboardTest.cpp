#include "../catch.hpp"
#include "../Plugboard.hpp"

TEST_CASE("Parse empty plugboard file", "[plugboard]") {
  Plugboard plugboard("./plugboards/null.pb");
}

TEST_CASE("Parse plugboard file", "[plugboard]") {
  Plugboard plugboard("./plugboards/V.pb");
}
