#ifndef RB_H
#define RB_H

typedef enum colors { RED, BLACK, DB_BLACK } colors;

typedef struct rb {
    int value;
    colors color;
    struct rb *left, *right, *parent;
} rb;

rb *rbFactory(int value, rb *parent);

void rbInsert(rb **tree, int value, rb *parent);
void rbRemove(rb **tree, int value);

void rbFixup(rb **node);

void rbRotateLeft(rb **node);
void rbRotateRight(rb **node);
void rbRotateLeft(rb **node);
void rbRotateRight(rb **node);

int rbBalanceFactor(rb *tree);
int rbHeight(rb *tree);

#endif