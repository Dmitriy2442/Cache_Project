#ifndef STACK_IMPLEMENTATION_H
#define STACK_IMPLEMENTATION_H



// Realization of the first functions working with stack

#include "block_struct.h"

struct Stack
{
    int top_number;
    int bottom_number;
    size_t size;
    struct block** data;
};




void stack_create(struct Stack* stack_point);             //creates an empty stack

void stack_push(struct Stack* stack_point, block* x);     //push a new block into the stack

struct block* stack_pop(struct Stack* stack_point);       //pop the top element from the stack

struct block* stack_get(struct Stack* stack_point);       // returns the top element of the stack

void stack_print(struct Stack* stack_point);              //prints the stack elements in order, if the stack is empty outputs "Empty stack"

int  stack_size(struct Stack* stack_point);               //returns the stack size

void stack_delete(struct Stack* stack_point);             //delete the stack

void stack_print(struct Stack* stack_point);              // prints all available information about each stack element

void stack_pruning (struct Stack* stack_point);           // removes the HIR blocks in the bottom of the stack until an LIR block sits in the stack bottom



#endif /*STACK_IMPLEMENTATION_H*/
