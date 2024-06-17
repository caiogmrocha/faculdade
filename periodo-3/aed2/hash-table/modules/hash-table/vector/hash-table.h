#ifndef H_VECTOR_HASH_TABLE
#define H_VECTOR_HASH_TABLE

#define HTV_TABLE_LENGTH 31
#define HTV_NULL_VALUE 0

typedef int htv[HTV_TABLE_LENGTH];

void htvBootstrap(htv table);
int htvHash(int key);
void htvInsert(htv table, int value);
void htvRemove(htv table, int value);
void htvSearch(htv table, int value);
void htvTraversal(htv table, void cb(int value));

#endif