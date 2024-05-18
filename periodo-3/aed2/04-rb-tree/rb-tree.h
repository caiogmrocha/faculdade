#include <stdlib.h>

typedef enum rbcolors { RED, BLACK } rbcolors;
typedef struct rbtree {
    int value;
    struct rbtree *left, *right, *parent;
    rbcolors color;
} rbtree;