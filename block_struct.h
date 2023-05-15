#ifndef BLOCK_STRUCT_H
#define BLOCK_STRUCT_H
#include "list_implementation.h"

struct block
{
    int number;                            //page number without hash-function used
    int HIR;                               //LIR/HIR block status flag, 0 - LIR, 1 - HIR
    int cache_residency;                   //cache residency flag, 0 - non-resident block, 1 - resident block
    int stack_residency;                   //stack_residency
    struct node_t *block_list_node;        //pointer on the node of the block in list Q
};

#endif /*BLOCK_STRUCT_H*/