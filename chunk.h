#ifndef clox_chunk_h
#define clox_chunk_h

#include "value.h"
#include "common.h"

typedef enum
{
  OP_ADD,
  OP_SUBTRACT,
  OP_MULTIPLY,
  OP_DIVIDE,
  OP_NEGATE,
  OP_CONSTANT,
  OP_RETURN,
} OpCode;

typedef struct
{
  int count;
  int capacity;
  uint8_t *code;
  int *lines;
  ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk);

void writeChunk(Chunk *chunk, uint8_t byte, int line);

void freeChunk(Chunk *chunk);

int addConstant(Chunk *chunk, Value value);

#endif