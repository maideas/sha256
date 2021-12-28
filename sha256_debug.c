
#include "sha256_debug.h"

void printS(char *s) {
  printf("input string: \"%s\"\n\n", s);
}

void printW_data(uint32_t *W) {

  for (int n = 0; n < 16; n++) {
    printf("W[%2d] = 0x%08X\n", n, W[n]);
  }
  printf("\n");
}

void printW_full(uint32_t *W) {  // little endian

  uint8_t  *W_8_ptr;

  W_8_ptr = (uint8_t *)W;
  for (int j = 0; j < 4; j++) {
    for (int k = 0; k < 8; k++) {
      for (int m = 0; m < 8; m++) {
        printf("0x%02X ", *W_8_ptr++);
      }
      printf("\n");
    }
    printf("\n");
  }
}

void printH(int t,
    uint32_t a,
    uint32_t b,
    uint32_t c,
    uint32_t d,
    uint32_t e,
    uint32_t f,
    uint32_t g,
    uint32_t h
  ) {

  if (t == -1) {
    printf("digest: ");
  } else {
    printf("t=%2d: ", t);
  }
  printf("0x%08X ", a);
  printf("0x%08X ", b);
  printf("0x%08X ", c);
  printf("0x%08X ", d);
  printf("0x%08X ", e);
  printf("0x%08X ", f);
  printf("0x%08X ", g);
  printf("0x%08X ", h);
  printf("\n");
}

void print_digest(uint32_t *H) {

  printH(-1, H[0], H[1], H[2], H[3], H[4], H[5], H[6], H[7]);
  printf("\n========================================\n");
}

