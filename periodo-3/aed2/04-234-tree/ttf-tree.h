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
 * @return a new pointer of `ttf`.
*/
ttf *ttfFactory();

/**
 * Insert a `value` in `(*source)->values` with insertion sort algorithm.
 * 
 * @param source the double pointer to the 234 tree.
 * @param value the `value` to be inserted.
 * 
 * @return `true` if the element has been insert or `false` otherwise.
*/
bool ttfAppendValue(ttf **source, unsigned int value);

// bool ttfAppendChild(ttf **dest, ttf *source);

#endif
