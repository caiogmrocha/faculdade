#include <stdlib.h>
#include <stdbool.h>
#include "ttf-tree.h"

ttf *ttfFactory() {
    ttf *newTtf = (ttf *) malloc(sizeof(ttf));

    for (short i = 0; i < TTF_VALUES_AMOUNT; i++) {
        newTtf->values[i] = TTF_NULL_VALUE;
    }

    for (short i = 0; i < TTF_CHILDREN_AMOUNT; i++) {
        newTtf->children[i] = NULL;
    }

    return newTtf;
}

void ttfInsert(ttf **tree, unsigned int value, ttf **parent) {
    if (*tree == NULL) {
        *tree = ttfFactory();

        ttfAppendValue(tree, value);
    } else if (!ttfValuesIsFulfilled(*tree)) {
        ttfAppendValue(tree, value);
    } else if (parent == NULL) {
        *parent = ttfFactory();
        ttf *right = ttfFactory();

        ttfAppendValue(parent, (*tree)->values[1]);
        (*tree)->values[1] = TTF_NULL_VALUE;

        ttfAppendValue(&right, (*tree)->values[2]);
        (*tree)->values[2] = TTF_NULL_VALUE;

        (*parent)->children[0] = *tree;
        (*parent)->children[1] = right;

        *tree = *parent;
    } else {
        // ...
    }
}

bool ttfAppendValue(ttf **source, unsigned int value) {
    if ((*source)->values[TTF_VALUES_AMOUNT - 1] != TTF_NULL_VALUE) {
        return false;
    }
    
    for (int i = 0; i < TTF_VALUES_AMOUNT; i++) {
        if ((*source)->values[i] != -1) {
            if (value < (*source)->values[i]) {
                for (int j = TTF_VALUES_AMOUNT-1; j > i; j--) {
                    (*source)->values[j] = (*source)->values[j-1];
                }

                (*source)->values[i] = value;

                break;
            }
        } else {
            (*source)->values[i] = value;

            break;
        }
    }

    return true;
}

bool ttfAppendChild(ttf **dest, ttf *source) {
    for (int i = 0; i < TTF_CHILDREN_AMOUNT; i++) {
        if ((*dest)->children[i] == NULL) {
            (*dest)->children[i] = source;

            return true;
        }
    }

     return false;
}

bool ttfIsLeaf(ttf *tree) {
    return tree->children[0] == NULL;
}

bool ttfValuesIsEmpty(ttf *tree) {
    return tree->values[0] == TTF_NULL_VALUE;
}

bool ttfValuesIsFulfilled(ttf *tree) {
    return tree->values[TTF_VALUES_AMOUNT - 1] != -1;
}

bool ttfPointersIsEmpty(ttf *tree) {
    return tree->children[0] == NULL;
}

bool ttfPointersIsFulfilled(ttf *tree) {
    return tree->children[TTF_CHILDREN_AMOUNT - 1] != NULL;
}
