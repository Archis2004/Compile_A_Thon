#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#define INST_NOP   0x0
#define INST_PROG  0x1
#define INST_EXE   0x2
#define INST_END   0x3

#define EXEC_SHIFT 16
#define MEM_SHIFT  6
#define POINTER_MASK 0x03
#define ROWADDR_MASK 0xFF

typedef unsigned int Instruction;

Instruction assemble_instruction(unsigned int instr_type, unsigned int pointer_value, int read_flag, int write_flag, unsigned int row_addr);

#endif
