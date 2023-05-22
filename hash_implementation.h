#ifndef HASH_IMPLEMENTATION_H
#define HASH_IMPLEMENTATION_H
#include <stdio.h>
#include <stdlib.h>
#include "block_struct.h"

// Realization of the functions working with hash table

struct hash                                                               //create this structure so that you have a hash table
{
    struct hash_node_t** table;
    size_t capacity_hash;
};


int hash_function(int number, struct hash* hash_table);                   //counts the hash number

void hash_table_create(struct hash* hash_table, size_t size_hash);        //creates a hash table that you can work with

int hash_checking (struct block* element, struct hash* hash_table);       //checks the presence of a block in the hash table

void hash_add (struct block* element, struct hash* hash_table);           //adds an element in hash table

void hash_block_delete (struct block* element, struct hash* hash_table);  //removes a block from the hash table

struct block* hash_get_block(int number, struct hash* hash_table);        /*returns a pointer to the block if its number is known.
                                                                            if the block was not found, creates a new block,
                                                                            inserts it into the hash table and returns a pointer to it */

void print_hash_table (const struct hash* hash_table);                    /*prints the key number of the page, HIR, cache_residency,
                                                                            stack_residency of all the elements in the hash table    */


void hash_delete (struct hash* hash_table);                               /*deletes the hash table
                                                                            be sure to use it after you stop working with it */


#endif /*HASH_IMPLEMENTATION_H*/
