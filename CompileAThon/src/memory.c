#include "memory.h"

unsigned int compute_memory_address(const char *matrix, int row, int col) {
    unsigned int base = (matrix[0] == 'A') ? 0x10 : 0x80;
    int stride = 10;  
    return base + row * stride + col;
}
