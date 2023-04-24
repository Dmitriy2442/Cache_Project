#ifndef STACK_REALIZATION_H
#define STACK_REALIZATION_H

// Realization of the first functions working with stack

void stack_create(struct block* stack_point);             //creates an empty stack

void stack_push(struct Stack* stack_point, block x);      //push a new block into the stack

block stack_pop(struct Stack* stack_point);               //pop the top element from the stack

block stack_get(struct Stack* stack_point);               // returns the top element of the stack

void stack_print(struct Stack* stack_point);              //prints the stack elements in order, if the stack is empty outputs "Empty stack"

int  stack_size(struct Stack* stack_point);               //returns the stack size

void stack_clear(struct Stack* stack_point);              //clears the stack

#endif /*STACK_REALIZATION_H*/