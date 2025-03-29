#include <stdio.h>
#include <stdint.h>
#include "lut.h"

void write_lut_to_file(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) return;
    uint8_t lut[16][16];
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            uint8_t opcode = (i * j) & 0xF;
            lut[i][j] = opcode;
        }
    }
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            fprintf(fp, "0x%01X ", lut[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}
