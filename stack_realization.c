#include <stdio.h>

//typedef int block;

struct Stack
{
    int top_number;
    block data[100];
};


void stack_create(struct Stack* stack_point)
{
    stack_point->top_number = -1;
}

void stack_push(struct Stack* stack_point, block x)
{
    (stack_point->top_number)++;
    stack_point->data[stack_point->top_number] = x;
}

block stack_pop(struct Stack* stack_point)
{
    stack_point->top_number--;
    return stack_point->data[stack_point->top_number + 1];
}

block stack_get(struct Stack* stack_point)
{
    return stack_point->data[stack_point->top_number + 1];
}

void stack_print(struct Stack* stack_point)
{
    if  (stack_point->top_number == -1)
        printf("Empty stack\n");
    else
    {
        for (int i = 0; i < (stack_point->top_number); i++)
        {
            printf("%d ", stack_point->data[i]);
        }
        printf("%d\n", stack_point->data[stack_point->top_number]);
    }
}

int  stack_size(struct Stack* stack_point)
{
    return stack_point->top_number + 1;
}

void stack_clear(struct Stack* stack_point)
{
    stack_point->top_number = -1;
}
