#include "instructions.h"

Instruction assemble_instruction(unsigned int instr_type, unsigned int pointer_value, int read_flag, int write_flag, unsigned int row_addr) {
    unsigned int exec_bits = (instr_type << 2) | (pointer_value & POINTER_MASK);
    unsigned int mem_bits = ((read_flag & 0x1) << 9) | ((write_flag & 0x1) << 8) | (row_addr & ROWADDR_MASK);
    Instruction instr = (exec_bits << EXEC_SHIFT) | (mem_bits << MEM_SHIFT);
    return instr;
}
