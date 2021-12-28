#ifndef SHA256_BIT_FUNC_H
#define SHA256_BIT_FUNC_H

#include <stdint.h>

uint32_t and (uint32_t x, uint32_t y);
uint32_t or  (uint32_t x, uint32_t y);
uint32_t xor2(uint32_t x, uint32_t y);
uint32_t xor3(uint32_t x, uint32_t y, uint32_t z);
uint32_t not (uint32_t x);

uint32_t add2(uint32_t x, uint32_t y);
uint32_t add4(uint32_t x, uint32_t y, uint32_t z, uint32_t u);
uint32_t add5(uint32_t x, uint32_t y, uint32_t z, uint32_t u, uint32_t v);

uint32_t shl (uint32_t x, int n);
uint32_t shr (uint32_t x, int n);
uint32_t rotl(uint32_t x, int n);
uint32_t rotr(uint32_t x, int n);

uint32_t ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t maj(uint32_t x, uint32_t y, uint32_t z);

uint32_t large_sigma_0(uint32_t x);
uint32_t large_sigma_1(uint32_t x);
uint32_t small_sigma_0(uint32_t x);
uint32_t small_sigma_1(uint32_t x);

uint32_t swap_endianess(uint32_t x);

#endif /* SHA256_BIT_FUNC_H */

