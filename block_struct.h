#ifndef BLOCK_STRUCT_H
#define BLOCK_STRUCT_H

struct block
{
    int number;             //page number without hash-function used
    int HIR;                //LIR/HIR block status flag, 0 - LIR, 1 - HIR
    int cache_residency;    //cache residency flag, 0 - non-resident block, 1 - resident block
    int stack_residency;    //stack_residency
};

#endif /*BLOCK_STRUCT_H*/