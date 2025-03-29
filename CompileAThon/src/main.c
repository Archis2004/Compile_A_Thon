#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "semantic.h"
#include "optimization.h"
#include "codegen.h"
#include "lut.h"
#include "memory.h"

#define MAX_SOURCE_SIZE 1024

int main(void) {
    int n;
    printf("Enter matrix dimension n (max 16): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 16) {
        fprintf(stderr, "Invalid dimension.\n");
        return 1;
    }
    init_matrices(n);
    char source_code[MAX_SOURCE_SIZE];
    snprintf(source_code, MAX_SOURCE_SIZE,
        "void matmul(int A[%d][%d], int B[%d][%d], int C[%d][%d]) { \n"
        "    for (int i = 0; i < %d; i++) { \n"
        "       for (int j = 0; j < %d; j++) { \n"
        "          C[i][j] = 0; \n"
        "          for (int k = 0; k < %d; k++) { \n"
        "              C[i][j] += A[i][k] * B[k][j]; \n"
        "          } \n"
        "       } \n"
        "    } \n"
        "}\n",
        n, n, n, n, n, n, n, n, n);
    printf("Generated Source Code:\n%s\n", source_code);
    ParsedInfo parsed = parse_source(source_code, n);
    printf("Parsed: rows=%d, cols=%d\n", parsed.rows, parsed.cols);
    MatrixIR ir = perform_semantic_analysis(parsed);
    printf("IR: A is %dx%d, B is %dx%d\n", ir.rows_A, ir.cols_A, ir.cols_A, ir.cols_B);
    OptimizedInfo opt = optimize_ir(&ir);
    printf("Optimized: MAC steps=%d, partial mults=%d\n", opt.mac_steps, opt.partial_mults);
    generate_instruction_sequence(&ir, &opt);
    write_lut_to_file("lut.txt");
    return 0;
}
