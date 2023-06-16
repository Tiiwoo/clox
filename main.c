#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char* argv[]) {
    Chunk chunk;
    initChunk(&chunk);

    int constant = addConstant(&chunk, 1.2); // add constant to the constant array(pool) and get the index
    writeChunk(&chunk, OP_CONSTANT, 123); // add opcode to the chunk
    writeChunk(&chunk, constant, 123); // add constant index to the chunk

    writeChunk(&chunk, OP_RETURN, 123);

    disassembleChunk(&chunk, "test chunk");

    freeChunk(&chunk);
    return 0;
}