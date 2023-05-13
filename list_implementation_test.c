#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list_implementation.h"
#include "block_struct.h"

int main()
{
    int a = 0;
    struct node_t *new_front;
    struct block *b = calloc(1, sizeof(struct block));
    struct node_t *front = calloc(1, sizeof(struct node_t));

    FILE *test = fopen("list_test.txt", "r");
    fscanf(test, "%d", &a);
    b->number = a;
    front->block_pointer = b;
    while((fscanf(test, "%d", &a) == 1))
    {
        struct block *c = calloc(1, sizeof(struct block));
        c->number = a;
        front = push_to_front(c, front);
    }
//    assert(front->right != NULL);
//    assert(front == front->left);
    printf("Size of the list: %d \n", list_size(front));
    printf("Numbers of the pages in the list (going from the front to the end): ");
    print_list(front);
    printf("\n");
    node_remove(front->left);
    printf("Numbers of the pages in the list (going from the front to the end): ");
    print_list(front);
    printf("\n");
}