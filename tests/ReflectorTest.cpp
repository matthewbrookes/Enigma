#include "../catch.hpp"
#include "../Reflector.hpp"

TEST_CASE("Reflect letters A-Z", "[reflector]") {
  Reflector reflector;
  REQUIRE(reflector.reflect('A') == 'N' );
  REQUIRE(reflector.reflect('B') == 'O' );
  REQUIRE(reflector.reflect('M') == 'Z' );
  REQUIRE(reflector.reflect('N') == 'A' );
}
