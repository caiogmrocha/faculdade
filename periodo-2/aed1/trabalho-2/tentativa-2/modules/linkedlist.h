#ifndef H_LINKEDLIST
#define H_LINKEDLIST

struct LinkedListNode {
    void *value;
    struct LinkedListNode *next;
};

void addFirst(struct LinkedListNode **list, void *value);
void addLast(struct LinkedListNode **list, void *value);
struct LinkedListNode *removeFirst(struct LinkedListNode **list);
struct LinkedListNode *removeLast(struct LinkedListNode **list);
struct LinkedListNode *peekFirst(struct LinkedListNode *list);
struct LinkedListNode *peekLast(struct LinkedListNode *list);

#endif
