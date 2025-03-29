#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "parser.h"

typedef struct {
    int rows_A;
    int cols_A;
    int cols_B;
} MatrixIR;

MatrixIR perform_semantic_analysis(ParsedInfo pinfo);

#endif
