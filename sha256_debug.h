#ifndef SHA256_DEBUG_H
#define SHA256_DEBUG_H

#include <stdio.h>
#include <stdint.h>

void printS(char *s);

void printW_data(uint32_t *W);
void printW_full(uint32_t *W);

void printH(int t,
    uint32_t a,
    uint32_t b,
    uint32_t c,
    uint32_t d,
    uint32_t e,
    uint32_t f,
    uint32_t g,
    uint32_t h
  );

void print_digest(uint32_t *H);

#endif /* SHA256_DEBUG_H */

