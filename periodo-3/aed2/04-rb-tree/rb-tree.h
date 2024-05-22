#include <stdlib.h>

typedef enum rbcolors { RED, BLACK } rbcolors;

typedef struct rbtree {
    int value;
    struct rbtree *left, *right, *parent;
    rbcolors color;
} rbtree;

typedef rbtree rbt;

/**
 * Inserts a `value` into a red-black `tree`.
 * 
 * @param tree to be considered.
 * @param value to be inserted in `tree`.
*/
void rbtInsert(rbtree **tree, int value, rbtree *parent);


/**
 * Rotates the grandparent node of `tree` to the left
 * and re-paint that accordingly.
 * 
 * @param tree the node to be rotated.
*/
void rbtRotateLeft(rbtree **node);


/**
 * Rotates the grandparent node of `tree` to the right
 * and re-paint that accordingly.
 * 
 * @param tree the node to be rotated.
*/
void rbtRotateRight(rbtree **node);

/**
 * Removes a node of `tree`, rebalance and repaint the
 * `tree` accordingly.
 * 
 * @param tree to be considered.
 * @param value to be removed from `tree`.
*/
void rbtRemove(rbtree **tree, int value);
