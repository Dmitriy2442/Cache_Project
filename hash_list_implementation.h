#ifndef HASH_LIST_IMPLEMENTATION_H
#define HASH_LIST_IMPLEMENTATION_H

// Realization of the functions working with hash list

struct hash_node_t                                                              // hash list structure which is a singly linked list
{
  struct hash_node_t *next;
  struct block* data;
};

struct hash_node_t *add_data(struct block* a, struct hash_node_t *old_node);   // adds a node to the list
struct hash_node_t *reverse_list(struct hash_node_t* old_node);                // flips the list from the end to the beginning
void delete_hash_list(struct hash_node_t* top);                                // deletes the entire list and frees up memory
int hash_node_find(struct hash_node_t* top, struct block* looking_for_data);   // returns 1 if it found a node in the list and 0 if not






#endif /*HASH_LIST_IMPLEMENTATION_H*/
