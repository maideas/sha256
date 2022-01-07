# SHA-256 Implementation

* [FIPS PUB 180-4 Secure Hash Standard](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf)
* [SHA-256 Reference Examples](https://csrc.nist.gov/CSRC/media/Projects/Cryptographic-Standards-and-Guidelines/documents/examples/SHA256.pdf)

## make compare

```
# -----------------------------------------
echo -n "" | sha256sum
e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855  -
# -----------------------------------------
echo -n "abc" | sha256sum
ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad  -
# -----------------------------------------
echo -n "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq" | sha256sum
248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1  -
# -----------------------------------------
echo -n "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq1234567" | sha256sum
9c7a7597d90e2dc4fdc45a824bd9462e926773f04bf90e5a7d6d5b325cfe662d  -
# -----------------------------------------
echo -n "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq12345678" | sha256sum
e07f00c1d434c9dc0274407d0d3f26651e64145e2ffb07824601582e38fed622  -
# -----------------------------------------
echo -n "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq123456789" | sha256sum
b370b7fdfadafa7d8adfa8d973afa4e82f4574c0534a63128ca2e1d2a07c49fa  -
# -----------------------------------------
rm -f main
gcc -Wall -I. -o main main.c sha256.c sha256_bit_func.c sha256_debug.c
./main | grep digest
digest: 0xE3B0C442 0x98FC1C14 0x9AFBF4C8 0x996FB924 0x27AE41E4 0x649B934C 0xA495991B 0x7852B855 
digest: 0xBA7816BF 0x8F01CFEA 0x414140DE 0x5DAE2223 0xB00361A3 0x96177A9C 0xB410FF61 0xF20015AD 
digest: 0x248D6A61 0xD20638B8 0xE5C02693 0x0C3E6039 0xA33CE459 0x64FF2167 0xF6ECEDD4 0x19DB06C1 
digest: 0x9C7A7597 0xD90E2DC4 0xFDC45A82 0x4BD9462E 0x926773F0 0x4BF90E5A 0x7D6D5B32 0x5CFE662D 
digest: 0xE07F00C1 0xD434C9DC 0x0274407D 0x0D3F2665 0x1E64145E 0x2FFB0782 0x4601582E 0x38FED622 
digest: 0xB370B7FD 0xFADAFA7D 0x8ADFA8D9 0x73AFA4E8 0x2F4574C0 0x534A6312 0x8CA2E1D2 0xA07C49FA 
```

# HMAC Implementation

* [FIPS PUB 198-1 The Keyed-Hash Message Authentication Code](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.198-1.pdf)
* [MAC-SHA-256 Reference Examples](https://csrc.nist.gov/CSRC/media/Projects/Cryptographic-Standards-and-Guidelines/documents/examples/HMAC_SHA256.pdf)

