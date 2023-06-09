#ifndef STACK_IMPLEMENTATION_H
#define STACK_IMPLEMENTATION_H



// Realization of the functions working with stack

#include "block_struct.h"

struct stack
{
    int top_number;
    int bottom_number;
    int remains;
    size_t size;
    struct block** data;
};

void stack_create(struct stack* stack_point, size_t stack_memory);   //creates an empty stack

void stack_push(struct stack* stack_point,struct block* x);     //push a new block into the stack

struct block* stack_pop(struct stack* stack_point);       //pop the top element from the stack

struct block* stack_get(struct stack* stack_point);       // returns the top element of the stack

int  stack_size(const struct stack* stack_point);         //returns the stack size

void stack_delete(struct stack* stack_point);             //delete the stack

void stack_print(struct stack* stack_point);              // prints all available information about each stack element

void stack_pruning (struct stack* stack_point);           // removes the HIR blocks in the bottom of the stack until an LIR block sits in the stack bottom



#endif /*STACK_IMPLEMENTATION_H*/
