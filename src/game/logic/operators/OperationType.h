#ifndef ASM_OPERATIONTYPE_H
#define ASM_OPERATIONTYPE_H

enum OPERATION_TYPE {
	MOV,	// Move
	ADD,	// Add
	SUB,	// Subtract
	NOP,	// No operation
	JMP,	// Jump
	JMT,	// Jump if true
	JMF,	// Jump if false
	TEQ,	// Test equal
	TNE,	// Test not equal
	TLT,	// Jump less than
	TLE,	// Jump less than or equal
	TGT,	// Jump greater than
	TGE,	// Jump greater than or equal
	INVALID_OP
};

#endif