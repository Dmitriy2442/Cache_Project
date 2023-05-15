#ifndef HASH_IMPLEMENTATION_H
#define HASH_IMPLEMENTATION_H
#include <stdio.h>
#include <stdlib.h>
#include "block_struct.h"

struct hash
{
    struct hash_node_t** table;
    size_t capacity_hash;
};


int hash_function(int number, struct hash* hash_table);

void hash_table_create(struct hash* hash_table, size_t size_hash);

int hash_checking (struct block* element, struct hash* hash_table);

void hash_add (struct block* element, struct hash* hash_table);

void hash_block_delete (struct block* element, struct hash* hash_table);

struct block* get_block(int number, struct hash* hash_table);

void print_hash_table (struct hash* hash_table);

void hash_delete (struct hash* hash_table);


#endif /*HASH_IMPLEMENTATION_H*/
