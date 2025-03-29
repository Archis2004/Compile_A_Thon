#include "semantic.h"
#include "parser.h"

MatrixIR perform_semantic_analysis(ParsedInfo pinfo) {
    MatrixIR ir;
    ir.rows_A = pinfo.rows;
    ir.cols_A = pinfo.cols;
    ir.cols_B = pinfo.cols;
    return ir;
}
