#include <stdio.h>
#include "codegen.h"
#include "memory.h"
#include "instructions.h"

void generate_instruction_sequence(const MatrixIR *ir, const OptimizedInfo *opt) {
    (void)opt;
    FILE *file = fopen("output.isa", "w");
    if (!file) {
        fprintf(stderr, "Error: Could not open output.isa for writing.\n");
        return;
    }
    #pragma omp parallel
    {
        #pragma omp for collapse(2) nowait
        for (int i = 0; i < ir->rows_A; i++) {
            for (int j = 0; j < ir->cols_B; j++) {
                #pragma omp critical
                {
                    fprintf(file, "Processing C[%d][%d]\n", i, j);
                }
                for (int k = 0; k < ir->cols_A; k++) {
                    unsigned int valA = read_matrix_value("A", i, k);
                    unsigned int valB = read_matrix_value("B", k, j);
                    Instruction inst_read_A = assemble_instruction(INST_NOP, 0, 1, 0, valA);
                    Instruction inst_read_B = assemble_instruction(INST_NOP, 0, 1, 0, valB);
                    #pragma omp critical
                    {
                        fprintf(file, "READ A[%d][%d] (4-bit value 0x%X): 0x%06X\n", i, k, valA, inst_read_A);
                        fprintf(file, "READ B[%d][%d] (4-bit value 0x%X): 0x%06X\n", k, j, valB, inst_read_B);
                    }
                }
                #pragma omp critical
                {
                    Instruction inst_prog = assemble_instruction(INST_PROG, 0x0A, 0, 0, 0);
                    Instruction inst_exe = assemble_instruction(INST_EXE, 0x14, 0, 0, 0);
                    Instruction inst_end = assemble_instruction(INST_END, 0, 0, 0, 0);
                    fprintf(file, "PROG: 0x%06X\n", inst_prog);
                    fprintf(file, "EXE: 0x%06X\n", inst_exe);
                    fprintf(file, "END: 0x%06X\n", inst_end);
                }
            }
        }
    }
    fclose(file);
    printf("Instruction sequence generated and saved to output.isa\n");
}
