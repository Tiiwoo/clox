#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
    OP_CONSTANT, // load constant for use
    OP_RETURN,   // return from function
} OpCode;

typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    int* lines; // store each bytecode's line number
    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);

void freeChunk(Chunk* chunk);

void writeChunk(Chunk* chunk, uint8_t byte, int line);

int addConstant(Chunk* chunk, Value value);

#endif