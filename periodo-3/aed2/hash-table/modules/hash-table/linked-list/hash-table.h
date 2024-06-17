#include "linked-list.h"

#ifndef H_LINKED_LIST_HASH_TABLE
#define H_LINKED_LIST_HASH_TABLE

#define HTV_EXPECTED_TABLE_LENGTH 20
#define HTLL_TABLE_LENGTH 41
#define HTLL_NULL_VALUE 0

typedef ll *htll[HTLL_TABLE_LENGTH];

void htllBootstrap(htll table);
int  htllHash(int key);
void htllInsert(htll table, int value);
void htllRemove(htll table, int value);
int  htllSearch(htll table, int value);
void htllTraversal(htll table, void cb(int value));

#endif