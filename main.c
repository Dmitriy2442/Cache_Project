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
    struct stack *stck;
    long long a = 0, b = 0, i = 0, page_number = 0, cache_hit = 0;

    if ((scanf("%lld", &a)) != 1) {
        printf("Incorrect input \n");
        return 1;
    }
    if (a < 0) {
        printf("Can't be negative number \n");
        return 1;
    }
    if ((scanf("%lld", &b)) != 1) {
        printf("Incorrect input \n");
        return 2;
    }
    if (b < 0) {
        printf("Can't be negative number \n");
        return 2;
    }

    if ((scanf("%lld", &page_number)) != 1) {
        printf("Incorrect input \n");
        return 3;
    }
    hash_table_create(hash, 100);
    get_block(page_number, hash);


    for (i = 1; i < a; ++i) {
        if ((scanf("%lld", &page_number)) != 1) {
            printf("Incorrect input \n");
            return 3;
        }
        accessed_block = get_block(page_number, hash);
        if ((accessed_block->HIR == 1) && (accessed_block->cache_residency == 1)) {
            cache_hit++;
            HIR_resident_access(accessed_block, stck, front, end);
        } else if ((accessed_block->HIR == 1)
                   && (accessed_block->cache_residency == 0)) {
            HIR_non_resident_access(accessed_block, stck, front, end);
        } else if ((accessed_block->HIR) == 0) {
            LIR_access(accessed_block, stck);
        }
    }
    printf("%lld\n", cache_hit);
    return 0;
}
