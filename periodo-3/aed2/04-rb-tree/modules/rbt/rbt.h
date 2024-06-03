#ifndef RB_TREE_H
#define RB_TREE_H

typedef enum colors { RED, BLACK } colors;

typedef struct rbt {
    struct rbt *parent, *left, *right;
    int value;
    colors color;
} rbt;

void rbtInsert(rbt **tree, int value, rbt **parent, rbt **root);

#endif