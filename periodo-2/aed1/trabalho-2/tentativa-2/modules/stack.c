#include <stdlib.h>
#include "linkedlist.h"
#include "stack.h"

void push(struct LinkedListNode **stack, void *value) {
    addLast(stack, value);
}

struct LinkedListNode *pop(struct LinkedListNode **stack) {
    return removeLast(stack);
}

struct LinkedListNode *peek(struct LinkedListNode *stack) {
    return peekLast(stack);
}
