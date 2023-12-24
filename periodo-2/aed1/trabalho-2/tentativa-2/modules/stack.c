#include <stdlib.h>
#include "linkedlist.h"
#include "stack.h"

void push(struct LinkedListNode **stack, int value) {
    addLast(stack, value);
}

void pop(struct LinkedListNode **stack) {
    removeLast(stack);
}

struct LinkedListNode *peek(struct LinkedListNode *stack) {
    return peekLast(stack);
}
