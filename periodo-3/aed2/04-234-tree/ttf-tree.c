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
