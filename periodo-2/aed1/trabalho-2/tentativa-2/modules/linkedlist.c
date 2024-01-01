#include <stdlib.h>
#include "linkedlist.h"

void addFirst(struct LinkedListNode **list, void *value) {
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

void addLast(struct LinkedListNode **list, void *value) {
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

struct LinkedListNode *removeFirst(struct LinkedListNode **list) {
    if (*list == NULL) return NULL;

    struct LinkedListNode *temp = *list;

    *list = (*list)->next;

    return temp;
}

struct LinkedListNode *removeLast(struct LinkedListNode **list) {
    if (*list == NULL) return NULL;

    struct LinkedListNode *iterator = *list;

    while (iterator->next->next != NULL) {
        iterator = iterator->next;
    }
 
    struct LinkedListNode *temp = iterator->next;

    iterator->next = NULL;

    return temp;
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
