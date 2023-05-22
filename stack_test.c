#include <stdio.h>
#include <stdlib.h>
#include "stack_implementation.h"




int main()
{

    int a;
    FILE *test = fopen("stack_test.txt", "r");
    fscanf(test, "%d", &a);

    if (a == 0)
    {
        return 0;
    }
    struct block* page = (block*)calloc(a ,sizeof(block));


    for (int i = 0; i < a; i++)
    {
        fscanf(test, "%d%d%d%d", &(page[i].number), &(page[i].HIR),
                                 &(page[i].cache_residency), &(page[i].stack_residency));
    }
    struct stack stack_test;
    stack_create(&stack_test, 2);
    for (int i = 0; i<a; i++)
    {
        stack_push(&stack_test, page+i);
    }

    stack_print((const struct stack*)(&stack_test));

    struct block* block1;
   /* printf("test 1\n");
    block1 = stack_pop(&stack_test);
    block1 = stack_pop(&stack_test);

    for (int i = 0; i < a; i++)
    {
        fscanf(test, "%d%d%d%d", &(page[i].number), &(page[i].HIR),
                                 &(page[i].cache_residency), &(page[i].stack_residency));
    }
    for (int i = 0; i<a; i++)
    {
        stack_push(&stack_test, page+i);
    }


    printf("test 2\n");
    stack_pruning(&stack_test);
    stack_print(&stack_test);

    stack_print(&stack_test);
    stack_delete(&stack_test);
    stack_create(&stack_test, 2);   */
    printf("test 3\n");

    for (int k = 0; k < 6; k++)
    {
        stack_pruning(&stack_test);
        block1 = stack_pop(&stack_test);
        for (int i = 0; i < a; i++)
        {
            fscanf(test, "%d%d%d%d", &(page[i].number), &(page[i].HIR),
                                    &(page[i].cache_residency), &(page[i].stack_residency));
        }

        for (int i = 0; i<a; i++)
        {
            stack_push(&stack_test, page+i);
        }
        stack_print((const struct stack*)(&stack_test));
    }

    return 0;
}



