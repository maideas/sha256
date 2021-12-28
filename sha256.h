#ifndef SHA256_H
#define SHA256_H

#include <stdint.h>

typedef struct {
  char *s;        // input data string
  uint32_t H[8];  // digest (hash result)

  // internal struct members ...
  union {
    uint32_t W32[64];
    uint8_t  W8[256];
  } w_u;
  uint64_t num_bits;
  int last_block;
  int one_flag;
} data_t;

void sha256(data_t *data);

#endif /* SHA256_H */

