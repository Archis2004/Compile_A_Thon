#include <stdio.h>
#include "memory.h"

int main(void) {
    unsigned int addrA00 = compute_memory_address("A", 0, 0);
    unsigned int addrA10 = compute_memory_address("A", 1, 0);
    unsigned int addrB00 = compute_memory_address("B", 0, 0);
    unsigned int addrB11 = compute_memory_address("B", 1, 1);
    if (addrA00 != 0x10) { printf("Test failed for A[0][0]\n"); return 1; }
    if (addrA10 != 0x10 + 10) { printf("Test failed for A[1][0]\n"); return 1; }
    if (addrB00 != 0x80) { printf("Test failed for B[0][0]\n"); return 1; }
    if (addrB11 != 0x80 + 11) { printf("Test failed for B[1][1]\n"); return 1; }
    printf("All memory tests passed\n");
    return 0;
}

