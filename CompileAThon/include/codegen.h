#ifndef CODEGEN_H
#define CODEGEN_H

#include "semantic.h"
#include "optimization.h"
#include "instructions.h"

void generate_instruction_sequence(const MatrixIR *ir, const OptimizedInfo *opt);

#endif 
