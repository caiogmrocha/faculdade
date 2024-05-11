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

ttf *ttfFactory();
bool ttfAppendValue(ttf **source, unsigned int value);
bool ttfAppendChild(ttf **dest, ttf *source);

#endif
