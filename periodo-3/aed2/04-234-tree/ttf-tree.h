#include <stdbool.h>

#ifndef TTF_TREE_H
#define TTF_TREE_H

const int VALUES_AMOUNT = 3;
const int CHILDREN_AMOUNT = VALUES_AMOUNT + 4;

typedef struct ttf {
    int values[VALUES_AMOUNT];
    ttf *children[CHILDREN_AMOUNT];
} ttf;

ttf *ttfFactory();
bool ttfAppendValue(ttf **source, int value);
bool ttfAppendChild(ttf **dest, ttf *source);

#endif
