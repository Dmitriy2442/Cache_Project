#include <stdio.h>
#include <stdlib.h>
#include "stack_implementation.h"
#include <assert.h>

void stack_create(struct stack* stack_point, size_t stack_memory)
{
    stack_point->top_number = -1;
    stack_point->bottom_number = 0;
    stack_point->size = stack_memory;
    stack_point->remains = stack_memory;
    stack_point->data = (struct block**)calloc(sizeof(struct block*), stack_memory);
    //stack_point->flag = 0;

}

void stack_push(struct stack* stack_point, struct block* x)
{
    (stack_point->top_number)++;
    (stack_point->remains)--;
    if (stack_point->top_number == stack_point->size)
    {
        stack_point->top_number = 0;
        //stack_point->flag = 1;
    }
   // if (stack_point->top_number - stack_point->bottom_number == -1 || (stack_point->top_number == stack_point->size-1 && stack_point->bottom_number == 0))
     //   printf("gfghgj");
    assert(stack_point->remains >= 0 && "ERROR: stack is full");
    stack_point->data[stack_point->top_number] = x;
    x->stack_residency = 1;
    //printf("\nPUSH %d %d\n", stack_point->top_number, stack_point->bottom_number);
}

struct block* stack_pop(struct stack* stack_point)
{
    stack_point->top_number--;
    (stack_point->remains)++;
    if (stack_point->top_number < 0)
    {
        stack_point->top_number == stack_point->size - 1;
        //stack_point->flag = 0;
    }
    assert(stack_point->remains <= stack_point->size && "ERROR: attempt to delete in an empty stack");
    stack_point->data[stack_point->top_number + 1]->stack_residency = 0;
    return stack_point->data[stack_point->top_number + 1];
}

struct block* stack_get(struct stack* stack_point)
{
    return stack_point->data[stack_point->top_number + 1];
}

void stack_print(struct stack* stack_point)
{
    int j = stack_point->bottom_number;
    if  (stack_point->remains == stack_point->size)
        printf("Empty stack\n");
    else
    {
        for (int i = 0; i < stack_point->size - stack_point->remains; i++)
        {
            printf("stack element %d: number %d HIR %d cache_residency %d stack_residency %d\n",
                        i+1, stack_point->data[i+j]->number,
                        stack_point->data[i+j]->HIR, stack_point->data[i+j]->cache_residency,
                        stack_point->data[i+j]->stack_residency);
            if (i+j == stack_point->size - 1)  j -= stack_point->size;
        }
    }
}

int  stack_size(const struct stack* stack_point)
{
    return stack_point->size;
}

int  stack_count_element(const struct stack* stack_point)
{
    return stack_point->size - stack_point->remains;
}


void stack_delete(struct stack* stack_point)
{
    assert(stack_point->data != NULL && "ERROR: attempt to free null pointer");
    stack_point->top_number= -1;
    stack_point->bottom_number= -1;
    free(stack_point->data);
}

void stack_pruning (struct stack* stack_point)
{
    int count = 0;
    //stack_print(stack_point);
    printf("\n pruning %d   %d   %d\n", stack_point->bottom_number, stack_point->top_number, stack_point->remains);
    for(int i = stack_point->bottom_number; stack_point->data[i]->HIR == 1;)
    {
        count += 1;
        stack_point->data[i]->stack_residency = 0;
        stack_point->remains++;
        printf("is %d\n", stack_point->remains);
        assert(stack_point->remains < stack_point->size &&
        "ERROR: attempt to delete in an empty stack, maybe because there was no LIR in the glass");
        i++;
        i = i%stack_point->size;

    }
    stack_point->bottom_number += count;
    //printf("\n pruning end %d   %d   %d\n", stack_point->bottom_number, stack_point->top_number, stack_point->remains);
    //printf("\n%d %d\n", stack_point->top_number, stack_point->bottom_number);
    if (stack_point->bottom_number >= stack_point->size)
        stack_point->bottom_number -= stack_point->size;

}
