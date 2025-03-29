#include "memory.h"

#define MAX_DIM 16

static unsigned int matrixA[MAX_DIM][MAX_DIM];
static unsigned int matrixB[MAX_DIM][MAX_DIM];

void init_matrices(int n) {
    for (int i = 0; i < n && i < MAX_DIM; i++) {
        for (int j = 0; j < n && j < MAX_DIM; j++) {
            matrixA[i][j] = (i + j) & 0xF;
            matrixB[i][j] = (i * j) & 0xF;
        }
    }
}

unsigned int read_matrix_value(const char *matrix, int row, int col) {
    if (matrix[0] == 'A')
        return matrixA[row][col] & 0xF;
    else
        return matrixB[row][col] & 0xF;
}

