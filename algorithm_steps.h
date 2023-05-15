#ifndef ALGORITHM_STEPS_H
#define ALGORITHM_STEPS_H

//Functions for 3 cases of different block access

void LIR_access(struct block *accessed_block, struct Stack *S);
void HIR_resident_access(struct block *accessed_block, struct Stack *S, struct node_t **front, struct node_t **end);
void HIR_non_resident_access(struct block *accessed_block, struct Stack *S, struct node_t **front, struct node_t **end);

#endif /*ALGORITHM_STEPS_H*/