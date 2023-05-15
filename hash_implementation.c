#include "hash_list_implementation.c"
#include "hash_implementation.h"

#include <assert.h>


void hash_table_create(struct hash* hash_table, size_t size_hash)
{
    hash_table->capacity_hash = size_hash;
    hash_table->table = (struct hash_node_t**)calloc(sizeof(hash_node_t*), hash_table->capacity_hash);
    assert(hash_table->table != NULL && "piztec");
}

int hash_function(int number, struct hash* hash_table)
{
    return (number % hash_table->capacity_hash);
}

int hash_checking (struct block* element, struct hash* hash_table)
{
    int key = hash_function(element->number, hash_table);
    return hash_node_find(hash_table->table[key], element);
}


void hash_add (struct block* element, struct hash* hash_table)
{
    int key = hash_function(element->number, hash_table);
    if (hash_checking(element, hash_table) == 0)
    {
        hash_table->table[key] = (struct hash_node_t*)calloc(1, sizeof(hash_node_t));
        hash_table->table[key]->data = element;
        hash_table->table[key]->next = NULL;
       // printf("HIR IS %d\n", element->HIR);
       // printf("%d\n", hash_table[key]->data->HIR);
    }
    else
    {
        add_data(element, hash_table->table[key]);
    }
}

void hash_block_delete (struct block* element, struct hash* hash_table)
{
    int key = hash_function(element->number, hash_table);
    struct hash_node_t* top = hash_table->table[key];
    struct hash_node_t* node_to_delete;
    //printf("ooo");
    if (top->data == element)
    {
        //printf("ooo");
        hash_table->table[key] = top->next;
        node_to_delete = top;
        free(node_to_delete);
        //printf("aaa");
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


struct block* get_block(int number, struct hash* hash_table)
{
    int key = hash_function(number, hash_table);
    struct hash_node_t* top = hash_table->table[key];
    while (top)
    {
        if (top->data->number == number)
        {
            return top->data;
        }
        top = top->next;
    }
    return NULL;
}

void print_hash_table (struct hash* hash_table)
{
    for (int i = 0; i < hash_table->capacity_hash; i++)
    {
        if (hash_table->table[i])
        {
            //printf("a");
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
    for (int i = 0; i < hash_table->capacity_hash; i++)
    {
        if (hash_table->table[i])
        {
            delete_hash_list(hash_table->table[i]);
        }
    }
    free(hash_table->table);
}
