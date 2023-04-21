#include <stdlib.h>
#include <stdio.h>
//To do: #include block_library

/*struct block
{
    int number;
    char *text;
};*/

struct node_t 
{
    struct node_t *next;
    struct block *block_pointer;
};

struct node_t *create_list(struct block *first_block_pointer)
{
    struct node_t* new_node = calloc(1, sizeof(struct node_t));
    new_node->block_pointer = first_block_pointer;
    return new_node;
}

struct node_t *push_to_list(struct block *pushed_block_pointer, struct node_t *old_node)
{
    struct node_t* new_node = calloc(1, sizeof(struct node_t));
    new_node->block_pointer = pushed_block_pointer;
    new_node->next = old_node;
    return new_node;
}

void delete_list(struct node_t* top)
{
    while (top != NULL)
    {
        struct node_t* newtop = top->next;
        free(top);
        top = newtop;
    }
}

void print_list(struct node_t* node)
{
    struct node_t* marker = node;
    while (marker != NULL)
    {
        printf("%d ", marker->block_pointer->number);
        marker = marker->next;
    }

    printf("%d \n", marker->block_pointer->number);

    free(marker);
}