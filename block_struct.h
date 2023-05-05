#ifndef BLOCK_STRUCT_H
#define BLOCK_STRUCT_H

struct block
{
    int number;          //page number without hash-function used
    int IRR;             //IRR of the block
    int HIR;             //LIR/HIR block status flag, 0 - LIR, 1 - HIR
    int residency;       //cache residency flag, 0 - non-resident block, 1 - resident block
    int last_access;     //the "time" that was on the counter last time this block got accessed
};

#endif /*BLOCK_STRUCT_H*/