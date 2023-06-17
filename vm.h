#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "value.h"

#define STACK_MAX 256

typedef struct {
    Chunk* chunk;
    uint8_t* ip; // instruction pointer, store in VM for other functions access, point to the next instruction
    Value stack[STACK_MAX];
    Value* stackTop; // point to the next empty position
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR,
} InterpretResult;

void initVM();

void freeVM();

// InterpretResult interpret(Chunk* chunk);
InterpretResult interpret(const char* source);

void push(Value value);

Value pop();

#endif