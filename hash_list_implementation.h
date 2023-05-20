#ifndef HASH_LIST_IMPLEMENTATION_H
#define HASH_LIST_IMPLEMENTATION_H

struct hash_node_t
{
  struct hash_node_t *next;
  struct block* data;
};

struct hash_node_t *add_data(struct block* a, struct hash_node_t *old_node);
struct hash_node_t *reverse_list(struct hash_node_t* old_node);
void delete_hash_list(struct hash_node_t* top);
int hash_node_find(struct hash_node_t* top, struct block* looking_for_data);






#endif /*HASH_LIST_IMPLEMENTATION_H*/
