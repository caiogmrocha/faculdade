#include <stdlib.h>
#include <stdbool.h>
#include "ttf-tree.h"

ttf *ttfFactory() {
    ttf *newTtf = (ttf *) malloc(sizeof(ttf));

    newTtf->parent = NULL;

    for (short i = 0; i < TTF_VALUES_AMOUNT; i++) {
        newTtf->values[i] = TTF_NULL_VALUE;
    }

    for (short i = 0; i < TTF_CHILDREN_AMOUNT; i++) {
        newTtf->children[i] = NULL;
    }

    return newTtf;
}

void ttfInsert(ttf **tree, unsigned int value) {
    if (*tree == NULL) {
        *tree = ttfFactory();

        ttfAppendValue(tree, value);
    } else if (!ttfValuesIsFulfilled(*tree) && ttfIsLeaf(*tree)) {
        ttfAppendValue(tree, value);
    } else if ((*tree)->parent == NULL && ttfIsLeaf(*tree)) {
        ttf *newParent = ttfFactory();
        ttf *right = ttfFactory();

        ttfAppendValue(&newParent, (*tree)->values[1]);
        (*tree)->values[1] = TTF_NULL_VALUE;

        ttfAppendValue(&right, (*tree)->values[2]);
        (*tree)->values[2] = TTF_NULL_VALUE;

        ttfAppendChild(&newParent, *tree);
        ttfAppendChild(&newParent, right);

        *tree = newParent;
    } else if ((*tree)->parent != NULL && ttfIsLeaf(*tree)) {
        ttfAppendValue(&(*tree)->parent, (*tree)->values[1]);
        (*tree)->values[1] = TTF_NULL_VALUE;

        ttf *right = ttfFactory();

        ttfAppendValue(&right, (*tree)->values[2]);
        (*tree)->values[2] = TTF_NULL_VALUE;

        ttfAppendChild(tree, right);
    } else {
        int i;

        for (i = 0; i < TTF_VALUES_AMOUNT; i++) {
            if (value < (*tree)->values[i]) {
                ttfInsert(&(*tree)->children[i], value);

                return;
            }
        }

        ttfInsert(&(*tree)->children[TTF_CHILDREN_AMOUNT - 1], value);
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
    source->parent = *dest;

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

bool ttfChildrenIsEmpty(ttf *tree) {
    return tree->children[0] == NULL;
}

bool ttfChildrenIsFulfilled(ttf *tree) {
    return tree->children[TTF_CHILDREN_AMOUNT - 1] != NULL;
}
