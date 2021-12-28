
#include <stdio.h>
#include "sha256.h"
#include "sha256_debug.h"

int main(int argc, char *argv[]) {

  data_t data;

#if 1
  data.s = "";
  sha256(&data);
  print_digest(data.H);
#endif

#if 1
  data.s = "abc";
  sha256(&data);
  print_digest(data.H);
#endif

#if 1
  data.s = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
  sha256(&data);
  print_digest(data.H);
#endif

#if 1
  data.s = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq1234567";
  sha256(&data);
  print_digest(data.H);
#endif

#if 1
  data.s = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq12345678";
  sha256(&data);
  print_digest(data.H);
#endif

#if 1
  data.s = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq123456789";
  sha256(&data);
  print_digest(data.H);
#endif

  return 0;
}

