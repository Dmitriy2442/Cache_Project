#include <stdio.h>
#include <stdlib.h>
#include "stack_implementation.h"
#include "hash_implementation.h"
#include "hash_list_implementation.h"
#include <assert.h>



void hash_table_create(struct hash* hash_table, size_t size_hash)
{
    assert(hash_table != NULL && "TRY TO USE NULL POINTER");
    hash_table->capacity_hash = size_hash;
    hash_table->table = (struct hash_node_t**)calloc(sizeof(struct hash_node_t*), hash_table->capacity_hash);
    assert(hash_table->table != NULL && "CALLOC RETURN NULL POINTER");
}

int hash_function(int number, struct hash* hash_table)
{
    assert(hash_table->table != NULL && "TRY TO USE NULL POINTER");
    return (number % hash_table->capacity_hash);
}

int hash_checking (struct block* element, struct hash* hash_table)
{
    assert(hash_table->table != NULL && "TRY TO USE NULL POINTER");
    int key = hash_function(element->number, hash_table);
    return hash_node_find(hash_table->table[key], element);
}


void hash_add (struct block* element, struct hash* hash_table)
{
    assert(hash_table->table != NULL && "TRY TO USE NULL POINTER");
    int key = hash_function(element->number, hash_table);
    if (hash_checking(element, hash_table) == 0)
    {
        hash_table->table[key] = (struct hash_node_t*)calloc(1, sizeof(struct hash_node_t));
        hash_table->table[key]->data = element;
        hash_table->table[key]->next = NULL;
    }
    else
    {
        add_data(element, hash_table->table[key]);
    }
}

void hash_block_delete (struct block* element, struct hash* hash_table)
{
    assert(hash_table->table != NULL && "TRY TO USE NULL POINTER");
    int key = hash_function(element->number, hash_table);
    struct hash_node_t* top = hash_table->table[key];
    struct hash_node_t* node_to_delete;
    if (top->data == element)
    {
        hash_table->table[key] = top->next;
        node_to_delete = top;
        free(node_to_delete);
    }
    else
    {
        while (top)
        {
            if (top->next->data == element)
            {
                node_to_delete = top->next->next;
                top->next = top->next->next;
                free(node_to_delete);
                break;
            }
            top = top->next;
        }
    }
}


struct block* hash_get_block(int number, struct hash* hash_table)
{
    assert(hash_table->table != NULL && "TRY TO USE NULL POINTER");
    int key = hash_function(number, hash_table);
    struct hash_node_t* top = hash_table->table[key];
    if (top == NULL)
    {
        struct block* new_block = (struct block*)calloc(1, sizeof(struct hash_node_t));
        new_block->number = number;
        new_block->HIR = 1;
        new_block->cache_residency = 0;
        new_block->stack_residency = 0;
        new_block->block_list_node = NULL;
        struct hash_node_t* new_node = (struct hash_node_t*)calloc(1, sizeof(struct hash_node_t));
        new_node->data = new_block;
        free(new_node->next);

        hash_table->table[key] = new_node;

        return new_node->data;

    }
    if(top->data->number == number)
    {
        return top->data;
    }
    while (top->next != NULL)
    {
        if (top->next->data->number == number)
        {
            return top->next->data;
        }
        top = top->next;
    }
    struct block* new_block = (struct block*)calloc(1, sizeof(struct hash_node_t));
    new_block->number = number;
    new_block->HIR = 1;
    new_block->cache_residency = 0;
    new_block->stack_residency = 0;
    new_block->block_list_node = NULL;
    struct hash_node_t* new_node = (struct hash_node_t*)calloc(1, sizeof(struct hash_node_t));
    top->next = new_node;
    new_node->data = new_block;
    free(new_node->next);


    return new_block;

}

void print_hash_table (const struct hash* hash_table)
{
    assert(hash_table->table != NULL && "TRY TO USE NULL POINTER");    
    for (int i = 0; i < hash_table->capacity_hash; i++)
    {
        if (hash_table->table[i])
        {
            struct hash_node_t* top = hash_table->table[i];
            while (top)
            {
                printf("key is %d: number %d HIR %d residency %d last_access %d\n", i, top->data->number, top->data->HIR, top->data->cache_residency, top->data->stack_residency);
                top = top->next;
            }
        }

    }
}

void hash_delete (struct hash* hash_table)
{
    assert(hash_table->table != NULL && "TRY TO USE NULL POINTER"); 
    for (int i = 0; i < hash_table->capacity_hash; i++)
    {
        if (hash_table->table[i])
        {
            delete_hash_list(hash_table->table[i]);
        }
    }
    free(hash_table->table);
}
