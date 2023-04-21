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
    struct node_t *left;
    struct node_t *right;
    struct block *block_pointer;
};

struct node_t *create_list(struct block *first_block_pointer)
{
    struct node_t* new_node = calloc(1, sizeof(struct node_t));
    new_node->block_pointer = first_block_pointer;
    return new_node;
}

struct node_t *push_to_front(struct block *pushed_block_pointer, struct node_t *old_node)
{
    struct node_t* new_node = calloc(1, sizeof(struct node_t));
    new_node->block_pointer = pushed_block_pointer;
    new_node->left = old_node;
    old_node->right = new_node;
    return new_node;
}

void delete_list(struct node_t* front)
{
    while (front != NULL)
    {
        struct node_t* new_front = front->left;
        free(front);
        front = new_front;
    }
}

void print_list(struct node_t* front)
{
    struct node_t* marker = front;
    while (marker != NULL)
    {
        printf("%d ", marker->block_pointer->number);
        marker = marker->left;
    }

    printf("%d \n", marker->block_pointer->number);

    free(marker);
}