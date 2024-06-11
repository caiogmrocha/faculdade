// "rbt" means "red-black tree"

#ifndef RBT_H
#define RBT_H

typedef enum colors { RED, BLACK, DOUBLE_BLACK } colors;

typedef struct rbt {
    struct rbt *parent, *left, *right;
    int value;
    colors color;
} rbt;

extern rbt *DB_NULL;

void rbtBootstrap();
void rbtInsert(rbt **tree, int value);
void rbtRemove(rbt **tree, int value, rbt **root);

#endif