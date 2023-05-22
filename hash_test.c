#include <stdio.h>
#include <stdlib.h>
#include "hash_implementation.h"


int main()
{
    struct hash hash_table;
    hash_table_create(&hash_table, 100);
    int a;
    FILE *test = fopen("hash_test.txt", "r");
    fscanf(test, "%d", &a);
    if (a == 0)
    {
        return 0;
    }
    struct block* page = (block*)calloc(a ,sizeof(block));
    for (int i = 0; i < a; i++)
    {
        fscanf(test, "%d%d%d%d", &(page[i].number), &(page[i].HIR), &(page[i].cache_residency), &(page[i].stack_residency));
    }

    for (int i = 0; i < a; i++)
    {
        hash_add (page+i, &hash_table);
    }
    print_hash_table(&hash_table);

    hash_block_delete(page+1, &hash_table);

    printf("%d\n", hash_get_block(78, &hash_table)->number);
    printf("%d\n", hash_get_block(101, &hash_table)->number);
    printf("%d\n", hash_get_block(111, &hash_table)->number);
    printf("%d\n", hash_get_block(1001, &hash_table)->number);

    print_hash_table(&hash_table);

    hash_delete(&hash_table);
    //print_hash_table(NULL);


    return 0;
}
