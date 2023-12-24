#include <stdlib.h>
#include "linkedlist.h"

void addFirst(struct LinkedListNode **list, int value) {
    if (*list == NULL) {
        *list = (struct LinkedListNode *) malloc(sizeof(struct LinkedListNode));
        (*list)->value = value;
        (*list)->next = NULL;
    } else {
        struct LinkedListNode *newNode = (struct LinkedListNode *) malloc(sizeof(struct LinkedListNode));
        newNode->value = value;
        newNode->next = *list;
        *list = newNode;
    }
}

void addLast(struct LinkedListNode **list, int value) {
    if (*list == NULL) {
        *list = (struct LinkedListNode *) malloc(sizeof(struct LinkedListNode));
        (*list)->value = value;
        (*list)->next = NULL;
    } else {
        struct LinkedListNode *iterator = *list;

        while (iterator->next != NULL) {
            iterator = iterator->next;
        }

        struct LinkedListNode *newNode = (struct LinkedListNode *) malloc(sizeof(struct LinkedListNode));
        newNode->value = value;
        newNode->next = NULL;
        iterator->next = newNode;   
    }
}

void removeFirst(struct LinkedListNode **list) {
    if (*list == NULL) return;

    struct LinkedListNode *temp = *list;

    *list = (*list)->next;

    free(temp);
}

void removeLast(struct LinkedListNode **list) {
    if (*list == NULL) return;

    struct LinkedListNode *iterator = *list;

    while (iterator->next->next != NULL) {
        iterator = iterator->next;
    }

    free(iterator->next);

    iterator->next = NULL;
}

struct LinkedListNode *peekFirst(struct LinkedListNode *list) {
    return list;
}

struct LinkedListNode *peekLast(struct LinkedListNode *list) {
    struct LinkedListNode *iterator = list;

    while (iterator->next != NULL) {
        iterator = iterator->next;
    }

    return iterator;
}
