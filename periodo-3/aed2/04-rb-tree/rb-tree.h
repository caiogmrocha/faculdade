#include <stdlib.h>

typedef enum rbcolors { RED, BLACK } rbcolors;

typedef struct rbtree {
    int value;
    struct rbtree *left, *right, *parent;
    rbcolors color;
} rbtree;

typedef rbtree rbt;

void rbtInsert(rbtree **tree, int value);
void rbtRotateLeft(rbtree **tree);
void rbtRotateRight(rbtree **tree);
void rbtRotateLeftRight(rbtree **tree);
void rbtRotateRightLeft(rbtree **tree);
void rbtRemove(rbtree **tree, int value);