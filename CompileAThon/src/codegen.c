#include <stdio.h>
#include "codegen.h"
#include "memory.h"
#include "instructions.h"

void generate_instruction_sequence(const MatrixIR *ir, const OptimizedInfo *opt) {
    (void)opt;
    for (int i = 0; i < ir->rows_A; i++) {
        for (int j = 0; j < ir->cols_B; j++) {
            for (int k = 0; k < ir->cols_A; k++) {
                Instruction inst_read_A = assemble_instruction(INST_NOP, 0, 1, 0, compute_memory_address("A", i, k));
                printf("READ A[%d][%d]: 0x%06X\n", i, k, inst_read_A);
                Instruction inst_read_B = assemble_instruction(INST_NOP, 0, 1, 0, compute_memory_address("B", k, j));
                printf("READ B[%d][%d]: 0x%06X\n", k, j, inst_read_B);
                Instruction inst_prog = assemble_instruction(INST_PROG, 0x0A, 0, 0, 0);
                printf("PROG: 0x%06X\n", inst_prog);
                Instruction inst_exe = assemble_instruction(INST_EXE, 0x14, 0, 0, 0);
                printf("EXE: 0x%06X\n", inst_exe);
                Instruction inst_end = assemble_instruction(INST_END, 0, 0, 0, 0);
                printf("END: 0x%06X\n", inst_end);
            }
        }
    }
}
