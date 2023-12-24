#ifndef H_LINKEDLIST
#define H_LINKEDLIST

struct LinkedListNode {
    int value;
    struct LinkedListNode *next;
};

void addFirst(struct LinkedListNode **list, int value);
void addLast(struct LinkedListNode **list, int value);
void removeFirst(struct LinkedListNode **list);
void removeLast(struct LinkedListNode **list);

#endif
