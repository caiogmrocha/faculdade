#ifndef H_STACK
#define H_STACK

#include "linkedlist.h"

void push(struct LinkedListNode **stack, void *value);
struct LinkedListNode *pop(struct LinkedListNode **stack);
struct LinkedListNode *peek(struct LinkedListNode *stack);

#endif