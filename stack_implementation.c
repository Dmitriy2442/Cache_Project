#include <stdio.h>
#include <stdlib.h>
#include "stack_implementation.h"



void stack_create(struct Stack* stack_point, size_t stack_memory)
{
    stack_point->top_number = -1;
    stack_point->bottom_number = 0;
    stack_point->size = stack_memory;
    stack_point->data = (struct block**)calloc(sizeof(struct block), stack_memory);

}

void stack_push(struct Stack* stack_point,struct block* x)
{
    (stack_point->top_number)++;
    if (stack_point->top_number == stack_point->size)
        stack_point->top_number -= stack_point->size;
    if (stack_point->top_number - stack_point->bottom_number == -1)
        printf("ERROR STACK IS FULL");

    stack_point->data[stack_point->top_number] = x;
}

struct block* stack_pop(struct Stack* stack_point)
{
    stack_point->top_number--;
    if (stack_point->bottom_number < 0)
        stack_point->bottom_number == stack_point->size - 1;
    if (stack_point->top_number == stack_point->bottom_number)
        printf("ERROR: there are no elements in the stack");
    return stack_point->data[stack_point->top_number + 1];
}

struct block* stack_get(struct Stack* stack_point)
{
    return stack_point->data[stack_point->top_number + 1];
}

void stack_print(struct Stack* stack_point)
{
    if  (stack_point->top_number == -1)
        printf("Empty stack\n");
    else
    {
        for (int i = stack_point->bottom_number; i <= (stack_point->top_number); i++)
        {
            printf("stack element %d: number %d IRR %d HIR %d residency %d last_access %d\n", i-stack_point->bottom_number+1, stack_point->data[i]->number, stack_point->data[i]->IRR, stack_point->data[i]->HIR, stack_point->data[i]->residency, stack_point->data[i]->last_access);
        }
    }
}

int  stack_size(struct Stack* stack_point)
{
    return stack_point->top_number + 1 - stack_point->bottom_number;
}



void stack_delete(struct Stack* stack_point)
{
    stack_point->top_number= -1;
    stack_point->bottom_number= -1;
    free(stack_point->data);
}

void stack_pruning (struct Stack* stack_point)
{
    int count = 0;
    for(int i = stack_point->bottom_number; stack_point->data[i]->HIR == 1; i++)
    {
        count += 1;
    }
    stack_point->bottom_number += count;
    if (stack_point->bottom_number >= stack_point->size)
        stack_point->bottom_number -= stack_point->size;

}
