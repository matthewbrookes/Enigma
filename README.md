# Enigma
C++ implementation of a German Enigma Machine allowing encryption/decryption of a message using an arbitrary number of configurable rotors and a configurable plugboard. This Enigma machine uses a fixed reflector.
## Using Enigma
Build the Enigma executable
```sh
$ make
```
Specify the paths to rotor and plugboard files as arguments to the executable. Rotors must be specified in the order to be used for encryption and the plugboard path is the final argument.
```sh
$ ./enigma rotors/I.rot rotors/III.rot plugboard/II.pb
```
Enter text to encrypt/decrypt in capital letters and press Ctrl-D on a new line.
## Configuring Enigma
There are sample rotor configuration files in rotors/
and plugboard configuration files in plugboards/
### Configuring Rotors
Rotors are defined by mapping each letter to another using a zero-based index of the alphabet i.e. 0 = 'A', 1 = 'B'...

A rotor configuration file specifies the index to map to for each letter in turn. The indexes are separated by spaces.
```
3 4 1 25...
```
Would map 'A' to D', 'B' to 'E', 'C' to 'B' and 'D' to 'Z'. Each letter requires a unique mapping.
### Configuring Plugboards
Plugboards are defined by pairing letters together using a zero-based index of the alphabet.

A plugboard configuration file specifies the pairs of letters to connect. Each letter within a pair is separated by a space and each pair is separated by a space.
```
3 4 1 25...
```
Would pair 'D' to 'E' and 'B' to 'Z'. Each letter can only be paired to a single other letter but there is no requirement for all letters to be paired.
