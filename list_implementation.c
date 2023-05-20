#include <stdlib.h>
#include <stdio.h>
#include "block_struct.h"
#include "list_implementation.h"

struct node_t *create_list(struct block *first_block_pointer)
{
    struct node_t* new_node = calloc(1, sizeof(struct node_t));
    new_node->block_pointer = first_block_pointer;
    return new_node;
}

struct node_t *push_to_front(struct block *pushed_block_pointer, struct node_t *old_node_front)
{
    struct node_t* new_node_front = calloc(1, sizeof(struct node_t));
    new_node_front->block_pointer = pushed_block_pointer;
    new_node_front->left = old_node_front;
    old_node_front->right = new_node_front;
    new_node_front->block_pointer->block_list_node = new_node_front;
    return new_node_front;
}

struct node_t *push_to_end(struct block *pushed_block_pointer, struct node_t *old_node_end)
{
    struct node_t* new_node_end = calloc(1, sizeof(struct node_t));
    new_node_end->block_pointer = pushed_block_pointer;
    new_node_end->right = old_node_end;
    old_node_end->left = new_node_end;
    new_node_end->block_pointer->block_list_node = new_node_end;
    return new_node_end;
}

void node_remove(struct node_t* removed_node)
{
    if (removed_node->left != NULL)
        removed_node->left->right = removed_node->right;
    if (removed_node->right != NULL)
        removed_node->right->left = removed_node->left;
    free(removed_node->block_pointer->block_list_node);
    free(removed_node);
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

    free(marker);
}

int list_size(struct node_t* front)
{
    struct node_t *marker = front;
    int i = 0;
    while (marker->left != NULL)
    {
        marker = marker->left;
        i++;
    }
    return i + 1;
}
