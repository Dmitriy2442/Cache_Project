#ifndef HASH_LIST_IMPLEMENTATION_H
#define HASH_LIST_IMPLEMENTATION_H
#include "block_struct.h"
struct hash_node_t
{
  struct hash_node_t *next;
  block* data;
};

struct hash_node_t *add_data(block* a, struct hash_node_t *old_node);
struct hash_node_t *reverse_list(struct hash_node_t* old_node);
void delete_hash_list(struct hash_node_t* top);
int hash_node_find(struct hash_node_t* top, block* looking_for_data);






#endif /*HASH_LIST_IMPLEMENTATION_H*/
