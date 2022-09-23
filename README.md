# AESEncryption
AES Encryption Algorithm for 128, 196, and 256 bit key.

## Compiling code
* gcc AES.c -o AES

## Running cipher
* In the command line run:
* ./AES 0 input(characters of hex) key(characters of hex)
* Ex:  ./AES 0 00112233445566778899aabbccddeeff 000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f

## Running decypher
* In command line run:
* ./AES 1 input(characters of hex) key(characters of hex)
* Ex: ./AES 1 69c4e0d86a7b0430d8cdb78070b4c55a 000102030405060708090a0b0c0d0e0f

## Additional Information 
### FIPS Processing Standard 197
https://nvlpubs.nist.gov/nistpubs/fips/nist.fips.197.pdf
