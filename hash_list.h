#ifndef HASH_LIST_H
#define HASH_LIST_H

struct hash_node_t
{
  struct hash_node_t *next;
  int data;
};

struct hash_node_t *add_data(int a, struct hash_node_t *old_node);
int print_list(struct hash_node_t* node);
struct hash_node_t *reverse_list(struct hash_node_t* old_node);
void delete_list(struct hash_node_t* top);

#endif /*HASH_LIST_H*/