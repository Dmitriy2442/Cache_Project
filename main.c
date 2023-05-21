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
    long long a = 0, b = 0, page_number = 0, cache_hit = 0;

    front = calloc(1, sizeof(struct node_t *));
    end = calloc(1, sizeof(struct node_t *));
    S = calloc(1, sizeof(struct stack));
    hash = calloc(1, sizeof(struct hash));

    printf("Print cache size: ");
    if ((scanf("%lld", &a)) != 1) {
        printf("Incorrect input \n");
        return 1;
    }
    if (a < 0) {
        printf("Can't be negative number \n");
        return 1;
    }
    printf("Print HIR cache section size: ");
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
    accessed_block = hash_get_block(page_number, hash);

    *front = create_list(accessed_block);
    *end = *front;

    stack_create(S, 100);
    stack_push(S, accessed_block);

    accessed_block->HIR = 1;
    accessed_block->cache_residency = 1;

    for (int j = 1; j < b; j++)
    {
        if ((scanf("%lld", &page_number)) != 1) {
            printf("Incorrect input \n");
            return 3;
        }
        accessed_block = hash_get_block(page_number, hash);
        *end = push_to_end(accessed_block, *end);
        stack_push(S, accessed_block);
        if (accessed_block->cache_residency == 1)
            cache_hit++;
        accessed_block->HIR = 1;
        accessed_block->cache_residency = 1;
    }


    for (int i = b; i < a; ++i) {
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
    printf("%lld\n", cache_hit);
    return 0;
}
