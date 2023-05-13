#include <stdlib.h>
#include <stdio.h>
#include "hash_list.h"

struct hash_node_t *add_data(int a, struct hash_node_t *old_node)
{
    struct hash_node_t* new_node = calloc(1, sizeof(struct hash_node_t));
    new_node->data = a;
    new_node->next = old_node;
    return new_node;
}

int print_list(struct hash_node_t* node)
{
    struct hash_node_t* marker = node;
    while (marker->next != NULL)
    {
        printf("%d ", marker->data);
        marker = marker->next;
    }

    printf("%d \n", marker->data);

    free(marker);
    return 0;
}

struct hash_node_t *reverse_list(struct hash_node_t* old_node)
{   
    struct hash_node_t* old_node_marker = old_node;
    struct hash_node_t* new_node = calloc(1, sizeof(struct hash_node_t));

    if (old_node == NULL)
        return NULL;

    new_node->data = old_node_marker->data;

    if (old_node_marker->next == NULL)
        return new_node;

    old_node_marker = old_node_marker->next;

    while (old_node_marker->next != NULL)
    {
        new_node = add_data(old_node_marker->data, new_node);
        old_node_marker = old_node_marker->next;
    }

    new_node = add_data(old_node_marker->data, new_node);

    free(old_node_marker);
    return new_node;
}

void delete_list(struct hash_node_t* top)
{
    while (top != NULL)
    {
        struct hash_node_t* newtop = top->next;
        free(top);
        top = newtop;
    }
}
