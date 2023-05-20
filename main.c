#include <stdio.h>
#include <stdlib.h>
#include "stack_implementation.h"
#include "algorithm_steps.h"
#include "list_implementation.h"
#include "block_struct.h"
#include "hash_list_implementation.h"

int main()
{
    struct block *get_flag;
    struct node_t *hash;
    struct node_t *front;
    struct node_t *end;
    struct stack *stck;
    long long a = 0, b = 0, i = 0, page_number = 0, cache_hit = 0;
    if ((scanf("%lld", &a)) != 1) {
        printf("Incorrect input");
        return 1;
    }
    if (a < 0) {
        printf("Can't be negative number");
        return 1;
    }
    if ((scanf("%lld", &b)) != 1) {
        printf("Incorrect input");
        return 2;
    }
    if (b < 0) {
        printf("Can't be negative number");
        return 2;
    }
    for (i = 0; i < a; ++i) {
        if ((scanf("%lld", &page_number)) != 1) {
            printf("Incorrect input");
            return 3;
        }
        get_flag = get_block(hash, page_number);
        if ((get_flag->HIR == 1) && (get_flag->cache_residency == 1)) {
            cache_hit++;
            HIR_resident_access(get_flag, stck, **front, **end);
        } else if ((get_flag->HIR == 1)
                   && (get_flag->cache_residency == 0)) {
            HIR_non_resident_access(get_flag, stck, **front, **end);
        } else if ((get_flag->HIR) == 0) {
            LIR_access(get_flag, stck);
        }
    }
    printf("%lld\n", cache_hit);
    return 0;
}
