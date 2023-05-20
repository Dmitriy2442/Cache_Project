#include <stdlib.h>
#include <stdio.h>
#include "block_struct.h"
#include "list_implementation.h"
#include "stack_implementation.h"
#include "algorithm_steps.h"

void LIR_access(struct block *accessed_block, struct stack *S)
{
    stack_push(S, accessed_block);
    if (S->data[S->bottom_number + 1]->HIR == 0)
        stack_pruning(S);
}

void HIR_resident_access(struct block *accessed_block, struct stack *S, struct node_t **front, struct node_t **end)
{
    stack_push(S, accessed_block);
    if (accessed_block->stack_residency > 1)
    {
        accessed_block->HIR = 0;
        node_remove(accessed_block->block_list_node);
        *end = push_to_end(S->data[S->bottom_number + 1], *end);
        S->data[S->bottom_number]->HIR = 1;
        stack_pruning(S);
    }
    else
    {
        node_remove(accessed_block->block_list_node);
        *end = push_to_end(accessed_block, *end);
    }
}

void HIR_non_resident_access(struct block *accessed_block, struct stack *S, struct node_t **front, struct node_t **end)
{
    (*front)->block_pointer->cache_residency = 0;
    (*front)->block_pointer = accessed_block;
    stack_push(S, accessed_block);
    if (accessed_block->stack_residency > 1)
    {
        accessed_block->HIR = 0;
        *end = push_to_end(S->data[S->bottom_number + 1], *end);
        stack_pruning(S);
    }
    else
        *end = push_to_end(accessed_block, *end);
}