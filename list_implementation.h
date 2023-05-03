#ifndef LIST_IMPLEMENTATION_H
#define LIST_IMPLEMENTATION_H

struct block
{
    int number;
    int IRR;
    int recency;
};

struct node_t 
{
    struct node_t *left;
    struct node_t *right;
    struct block *block_pointer;
};

//Implementation of first functions working with block structure and lists
struct node_t *create_list(struct block *first_block_pointer);                                        //creates list with first node data being like in the argument of the function
struct node_t *push_to_front(struct block *pushed_block_pointer, struct node_t *old_node_front);      //pushes node with new block_pointer as data to the front of the existing list
struct node_t *push_to_end(struct block *pushed_block_pointer, struct node_t *old_node_end);          //pushes node with new block_pointer as data to the end of the existing list
void delete_list(struct node_t* top);                                                                 //deletes existing list from the top in the argument
void print_list(struct node_t* node);                                                                 //prints numbers of blocks from the existing list
int list_size(struct node_t* front);                                                                  //returns size of the list

#endif /*LIST_IMPLEMENTATION_H*/
