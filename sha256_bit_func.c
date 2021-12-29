
#include "sha256_bit_func.h"

uint32_t inv(uint32_t x) {
  return ~x;
}

uint32_t and(uint32_t x, uint32_t y) {
  return x & y;
}

uint32_t xor2(uint32_t x, uint32_t y) {
  return x ^ y;
}

uint32_t xor3(uint32_t x, uint32_t y, uint32_t z) {
  return x ^ y ^ z;
}

uint32_t add2(uint32_t x, uint32_t y) {
  return (uint32_t)(x + y);  // (x + y) mod 2^32
}

uint32_t add4(uint32_t x, uint32_t y, uint32_t z, uint32_t u) {
  return (uint32_t)(x + y + z + u);  // (x + y + z + u) mod 2^32
}

uint32_t add5(uint32_t x, uint32_t y, uint32_t z, uint32_t u, uint32_t v) {
  return (uint32_t)(x + y + z + u + v);  // (x + y + z + u + v) mod 2^32
}

uint32_t shr(uint32_t x, unsigned int n) {
  return x >> n;
}

uint32_t rotr(uint32_t x, unsigned int n) {
  return (x >> n) | (x << (32 - n));
}

uint32_t ch(uint32_t x, uint32_t y, uint32_t z) {
  return xor2(and(x, y), and(inv(x), z));
}

uint32_t maj(uint32_t x, uint32_t y, uint32_t z) {
  return xor3(and(x, y), and(x, z), and(y, z));
}

uint32_t large_sigma_0(uint32_t x) {
  return xor3(rotr(x, 2), rotr(x, 13), rotr(x, 22));
}

uint32_t large_sigma_1(uint32_t x) {
  return xor3(rotr(x, 6), rotr(x, 11), rotr(x, 25));
}

uint32_t small_sigma_0(uint32_t x) {
  return xor3(rotr(x, 7), rotr(x, 18), shr(x, 3));
}

uint32_t small_sigma_1(uint32_t x) {
  return xor3(rotr(x, 17), rotr(x, 19), shr(x, 10));
}

uint32_t swap_endianess(uint32_t x) {

  uint32_t y;

  y = 0;
  y += (x & 0x000000FFU) << 24;
  y += (x & 0x0000FF00U) <<  8;
  y += (x & 0x00FF0000U) >>  8;
  y += (x & 0xFF000000U) >> 24;
  return y;
}

