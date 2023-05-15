#include <stdio.h>
#include <stdlib.h>
#include "algorithm_steps"
#include "stack_implementation.h"
#include "list_implementation.h"
#include "block_struct.h"
#include "hash_list.h"

int main()
{
    struct block *get_flag;
    struct node_t *hash;
    struct node_t *front;
    struct node_t *end;
    struct stack *stck;
    long long a = 0, b = 0, i = 0, cache_hit = 0;
    long long *input_arr = (long long *) calloc(a, sizeof(long long));
    FILE *file;
    file = fopen("input.txt", "r");
    fscanf(file, "%lld", &a);
    fscanf(file, "%lld", &b);
    while ((fscanf(file, "%lld", input_arr + 2 + i) != EOF)) {
        get_flag = get_block(hash, input_arr[2 + i]);
        if ((get_flag->HIR == 1) && (get_flag->cache_residency == 1)) {
            cache_hit++;
            HIR_resident_access(get_flag, stck, *front, *end);
        } else if ((get_flag->HIR == 1)
                   && (get_flag->cache_residency == 0)) {
            HIR_non_resident_access(get_flag, stck, *front, *end);
        } else if ((get_flag->HIR) == 0) {
            LIR_access(get_flag, stck);
        }
    }
    printf("%lld\n", cache_hit);
    return 0;
}
