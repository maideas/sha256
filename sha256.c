
#include <stdio.h>
#include "sha256.h"
#include "sha256_bit_func.h"
#include "sha256_debug.h"

static const uint32_t K[64] = {
  0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
  0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
  0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
  0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
  0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
  0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
  0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
  0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

static void get_data_block(data_t *data) {

  int n;

  // zero complete W
  for (n = 0; n < 64; n++) {
    data->w_u.W32[n] = 0;
  }

  // copy input data into W
  n = 0;
  while ((n < 64) && (*(data->s) != '\0')) {
    data->w_u.W8[n++] = *(data->s);
    data->s++;
    data->num_bits += 8;
  }

  // append single "1" bit (if there is space left
  // and it was not included in the previous block)
  if (n < 64) {
    if (!data->one_flag) {
      data->w_u.W8[n] = 0x80;
      data->one_flag = 1;
    }
  }

  // convert W32 to big-endian (including single "1")
  for (int k = 0; k < 16; k++) {
    data->w_u.W32[k] = swap_endianess(data->w_u.W32[k]);
  }

  if (n < 56) {
    // insert number of input data bits at the end of W
    data->w_u.W32[14] = (uint32_t)((data->num_bits >> 32) & 0xFFFFFFFFU);
    data->w_u.W32[15] = (uint32_t)((data->num_bits >>  0) & 0xFFFFFFFFU);
    data->last_block = 1;
  }
}

static void init_hash(data_t *data) {

  // initialize hash value with consts
  data->H[0] = 0x6a09e667;
  data->H[1] = 0xbb67ae85;
  data->H[2] = 0x3c6ef372;
  data->H[3] = 0xa54ff53a;
  data->H[4] = 0x510e527f;
  data->H[5] = 0x9b05688c;
  data->H[6] = 0x1f83d9ab;
  data->H[7] = 0x5be0cd19;
}

static void hash_data_block(data_t *data) {

  uint32_t a, b, c, d, e, f, g, h;
  uint32_t T1, T2;

  printW_data(data->w_u.W32);

  // prepare the message schedule (16..63)
  for (int t = 16; t < 64; t++) {
    data->w_u.W32[t] = add4(
      small_sigma_1(data->w_u.W32[t-2]),
      data->w_u.W32[t-7],
      small_sigma_0(data->w_u.W32[t-15]),
      data->w_u.W32[t-16]
    );
  }

  // initialize the 8 working variables
  a = data->H[0];
  b = data->H[1];
  c = data->H[2];
  d = data->H[3];
  e = data->H[4];
  f = data->H[5];
  g = data->H[6];
  h = data->H[7];

  // loop over all W values
  for (int t = 0; t < 64; t++) {
    T1 = add5(h, large_sigma_1(e), ch(e, f, g), K[t], data->w_u.W32[t]);
    T2 = add2(large_sigma_0(a), maj(a, b, c));
    h = g;
    g = f;
    f = e;
    e = add2(d, T1);
    d = c;
    c = b;
    b = a;
    a = add2(T1, T2);

    printH(t, a, b, c, d, e, f, g, h);
  }
  printf("\n");

  // compute intermediate hash value
  data->H[0] = add2(a, data->H[0]);
  data->H[1] = add2(b, data->H[1]);
  data->H[2] = add2(c, data->H[2]);
  data->H[3] = add2(d, data->H[3]);
  data->H[4] = add2(e, data->H[4]);
  data->H[5] = add2(f, data->H[5]);
  data->H[6] = add2(g, data->H[6]);
  data->H[7] = add2(h, data->H[7]);
}

void sha256(data_t *data) {

  data->num_bits = 0;
  data->last_block = 0;
  data->one_flag = 0;

  printS(data->s);

  init_hash(data);

  do {
    get_data_block(data);
    hash_data_block(data);
  } while (!data->last_block);
}

