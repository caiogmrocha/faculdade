#ifndef H_STACK
#define H_STACK

#include "linkedlist.h"

void push(struct LinkedListNode **stack, int value);
void pop(struct LinkedListNode **stack);
struct LinkedListNode *peek(struct LinkedListNode *stack);

#endif