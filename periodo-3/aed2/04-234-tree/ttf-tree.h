#include <stdbool.h>

#ifndef TTF_TREE_H
#define TTF_TREE_H

#define TTF_VALUES_AMOUNT 3
#define TTF_CHILDREN_AMOUNT (TTF_VALUES_AMOUNT + 4)
#define TTF_NULL_VALUE -1

typedef struct ttf {
    unsigned int values[TTF_VALUES_AMOUNT];
    struct ttf *children[TTF_CHILDREN_AMOUNT];
} ttf;

/**
 * Generate a 234 tree with default values.
 * 
 * @returns a new pointer of `ttf`.
*/
ttf *ttfFactory();

/**
 * 
*/
void ttfInsert(ttf **tree, unsigned int value, ttf **parent);

/**
 * Insert a `value` in `(*source)->values` with insertion sort algorithm.
 * 
 * @param source that is the double pointer to the 234 tree.
 * @param value to be inserted.
 * 
 * @returns `true` if the element has been insert or `false` otherwise.
*/
bool ttfAppendValue(ttf **source, unsigned int value);

/**
 * Insert a `source` in `(*dest)->children`.
 * 
 * @param dest that is the double pointer to the 234 tree to receive the new child.
 * @param source is the child to be inserted.
 * 
 * @returns `true` if the element has been insert or `false` otherwise.
*/
bool ttfAppendChild(ttf **dest, ttf *source);

/**
 * Check if a 234 tree is a leaf.
 * 
 * @param tree is the 234 tree to be checked.
 * 
 * @returns `true` if `tree` is a leaf or `false` otherwise.
*/
bool ttfIsLeaf(ttf *tree);

/**
 * Check if the `tree` values list is empty.
 * 
 * @param tree is the 234 tree to be checked.
 * 
 * @returns `true` if the values list of `tree` is empty or `false` otherwise.
*/
bool ttfValuesIsEmpty(ttf *tree);

/**
 * Check if the `tree` values list is fulfilled.
 * 
 * @param tree is the 234 tree to be checked.
 * 
 * @returns `true` if the values list of `tree` is empty or `false` otherwise.
*/
bool ttfValuesIsFulfilled(ttf *tree);

/**
 * Check if the `tree` children list is empty.
 * 
 * @param tree is the 234 tree to be checked.
 * 
 * @returns `true` if the children list of `tree` is empty or `false` otherwise.
*/
bool ttfPointersIsEmpty(ttf *tree);

/**
 * Check if the `tree` children list is fulfilled.
 * 
 * @param tree is the 234 tree to be checked.
 * 
 * @returns `true` if the values list of `tree` is empty or `false` otherwise.
*/
bool ttfPointersIsFulfilled(ttf *tree);

#endif
