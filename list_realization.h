#ifndef LIST_REALIZATION_H
#define LIST_REALIZATION_H

//Realization of first functions working with block structure and lists
struct node_t *create_list(struct block *first_block_pointer);                             //creates list with first node data being like in the argument of the function
struct node_t *push_to_front(struct block *pushed_block_pointer, struct node_t *old_node); //pushes node with new block_pointer as data to the existing list
void delete_list(struct node_t* top);                                                      //deletes existing list from the top in the argument
void print_list(struct node_t* node);                                                      //prints numbers of blocks from the existing list

#endif /*LIST_REALIZATION_H*/
