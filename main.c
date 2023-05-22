#include <stdio.h>
#include <stdlib.h>
#include "stack_implementation.h"
#include "algorithm_steps.h"
#include "list_implementation.h"
#include "block_struct.h"
#include "hash_list_implementation.h"
#include "hash_implementation.h"

int main()
{
    struct block *accessed_block;
    struct hash *hash;
    struct node_t **front;
    struct node_t **end;
    struct stack *S;
    long long cache_size = 0, HIR_section_size = 0, page_number = 0, cache_hit = 0, page_amount = 0;
    struct block *first_pseudo_block = calloc(1, sizeof(struct block));

    front = calloc(1, sizeof(struct node_t *));
    end = calloc(1, sizeof(struct node_t *));
    S = calloc(1, sizeof(struct stack));
    hash = calloc(1, sizeof(struct hash));

    printf("Print cache size: ");
    if ((scanf("%lld", &cache_size)) != 1) {
        printf("Incorrect input \n");
        return 1;
    }
    if (cache_size < 0) {
        printf("Can't be negative number \n");
        return 1;
    }
    printf("Print HIR cache section size: ");
    if ((scanf("%lld", &HIR_section_size)) != 1) {
        printf("Incorrect input \n");
        return 2;
    }
    if (HIR_section_size < 0) {
        printf("Can't be negative number \n");
        return 2;
    }

    printf("Print amount of pages: ");
    if ((scanf("%lld", &page_amount)) != 1) {
        printf("Incorrect input \n");
        return 2;
    }
    if (page_amount < 0) {
        printf("Can't be negative number \n");
        return 2;
    }

    if ((scanf("%lld", &page_number)) != 1) {
        printf("Incorrect input \n");
        return 3;
    }
    hash_table_create(hash, 100);                                                 //creation of hash table
    accessed_block = hash_get_block(page_number, hash);

    stack_create(S, 100);                                                         //creation of stack
    stack_push(S, accessed_block);

    accessed_block->HIR = 0;                                                      //first block management
    accessed_block->cache_residency = 1;

    for (int j = 1; j < cache_size - HIR_section_size; j++)                       //filling cache with LIR blocks
    {
        if ((scanf("%lld", &page_number)) != 1) {
            printf("Incorrect input \n");
            return 3;
        }
        accessed_block = hash_get_block(page_number, hash);
        stack_push(S, accessed_block);
        if (accessed_block->cache_residency == 1)
            cache_hit++;
        accessed_block->HIR = 0;
        accessed_block->cache_residency = 1;
    }

    first_pseudo_block->number = (-1)*HIR_section_size;                           //creating pseudo-empty list
    *front = create_list(first_pseudo_block);
    *end = *front;

    for (int i = 1; i < HIR_section_size; i++)
    {
        struct block *pseudo_block = calloc(1, sizeof(struct block));
        pseudo_block->number = (-1)*i;
        *front = push_to_front(pseudo_block, *front);
    }

    for (int i = cache_size-HIR_section_size; i < page_amount; i++) {             //main cycle
        if ((scanf("%lld", &page_number)) != 1) {
            printf("Incorrect input \n");
            return 3;
        }
        accessed_block = hash_get_block(page_number, hash);
        if ((accessed_block->HIR == 1) && (accessed_block->cache_residency == 1)) {
            cache_hit++;
            HIR_resident_access(accessed_block, S, front, end);
        } else if ((accessed_block->HIR == 1)
                   && (accessed_block->cache_residency == 0)) {
            HIR_non_resident_access(accessed_block, S, front, end);
        } else if ((accessed_block->HIR) == 0) {
            cache_hit++;
            LIR_access(accessed_block, S);
        }
    }
    printf("Cache hits amount: %lld\n", cache_hit);
    return 0;
}
