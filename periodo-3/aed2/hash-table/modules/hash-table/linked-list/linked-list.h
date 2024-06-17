#ifndef H_LINKED_LIST
#define H_LINKED_LIST

typedef struct ll {
    int value;
    struct ll *next;
} ll;

void llInsert(ll **list, int value);
void llRemove(ll **list, int value);
int  llSearch(ll *list, int value);

#endif