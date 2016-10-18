#include "../catch.hpp"
#include "../Rotor.hpp"
#include <iostream>

TEST_CASE("Encrypt forward", "[rotor]") {
  Rotor rotor("./rotors/I.rot");
  for (char letter = 'A'; letter < 'Z'; letter++) {
    REQUIRE(rotor.encryptForward(letter) == letter + 1);
  }
  REQUIRE(rotor.encryptForward('Z') == 'A');
}

TEST_CASE("Encrypt backward", "[rotor]") {
  Rotor rotor("./rotors/I.rot");
  for (char letter = 'Z'; letter > 'A'; letter--) {
    REQUIRE(rotor.encryptBackward(letter) == (letter - 'A' - 1) % 26 + 'A');
  }
  REQUIRE(rotor.encryptBackward('A') == 'Z');
}

TEST_CASE("Complete full rotation after 26 rotates", "[rotor]") {
  Rotor rotor("./rotors/I.rot");
  for (int i = 0; i < 25; i++) {
    REQUIRE(rotor.rotate() == false);
  }
  REQUIRE(rotor.rotate() == true);
}
TEST_CASE("Encrypt forward rotation", "[rotor]") {
  Rotor rotor("./rotors/I.rot");
  REQUIRE(rotor.encryptForward('A') == 'B');
  rotor.rotate();
  REQUIRE(rotor.encryptForward('A') == 'B');
  rotor.rotate();
  REQUIRE(rotor.encryptForward('A') == 'B');
  rotor.rotate();
  REQUIRE(rotor.encryptForward('A') == 'B');
  rotor.rotate();
  REQUIRE(rotor.encryptForward('A') == 'B');
  rotor.rotate();
  REQUIRE(rotor.encryptForward('A') == 'B');
  rotor.rotate();
}


TEST_CASE("Backward encrypt with rotations", "[rotor]") {
  Rotor rotor("./rotors/I.rot");
  REQUIRE(rotor.encryptBackward('B') == 'A');
  rotor.rotate();
  REQUIRE(rotor.encryptBackward('A') == 'Z');
  rotor.rotate();
  REQUIRE(rotor.encryptBackward('O') == 'N');
  rotor.rotate();
  REQUIRE(rotor.encryptBackward('O') == 'N');
  rotor.rotate();
  REQUIRE(rotor.encryptBackward('P') == 'O');
  rotor.rotate();
  REQUIRE(rotor.encryptBackward('Q') == 'P');
}
