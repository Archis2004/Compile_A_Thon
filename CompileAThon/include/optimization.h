#ifndef OPTIMIZATION_H
#define OPTIMIZATION_H

#include "semantic.h"

typedef struct {
    int mac_steps;       
    int partial_mults;   
} OptimizedInfo;

OptimizedInfo optimize_ir(const MatrixIR *ir);

#endif 
