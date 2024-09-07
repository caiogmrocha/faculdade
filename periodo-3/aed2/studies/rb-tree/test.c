#include <stdio.h>
#include <stdlib.h>

typedef enum colors { BLACK, RED, DB_BLACK } colors;

typedef struct rbt {
    int value;
    struct rbt *left, *right, *parent;
    colors color;
} rbt;

rbt *DB_NULL;

rbt *rbtFactory(int value, colors color) {
    rbt *node = (rbt *) malloc(sizeof(rbt));

    node->value = value;
    node->color = color;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    return node;
}

int checkSixthRemoveFixupCase(rbt *tree) {
    return (
        tree != NULL &&
        tree->color == DB_BLACK &&
        tree->parent != NULL &&
        tree->parent->right != NULL &&
        tree->parent->right->color == BLACK &&
        tree->parent->right->right != NULL &&
        tree->parent->right->right->color == RED
    );
}

void sixthRemoveFixup(rbt **tree) {
    rbt *n = *tree;
    rbt *p = n->parent;
    rbt *s = p->right;
    rbt *x = s->left;
    rbt *y = s->right;

    *tree = NULL;
    s->color = p->color;
    p->color = BLACK;
    y->color = BLACK;

    p->right = s->left;
    p->right->parent = p;
    s->parent = p->parent;
    p->parent = s;
    s->left = p;

    rbt *temp = NULL;
}


int main(int argc, char **argv) {
    DB_NULL = rbtFactory(-1, DB_BLACK);

    rbt *tree = DB_NULL;

    DB_NULL->parent = rbtFactory(20, BLACK);
    DB_NULL->parent->left = DB_NULL;

    DB_NULL->parent->right = rbtFactory(25, BLACK);
    DB_NULL->parent->right->parent = DB_NULL->parent;

    DB_NULL->parent->right->left = rbtFactory(23, RED);
    DB_NULL->parent->right->left->parent = DB_NULL->parent->right;

    DB_NULL->parent->right->right = rbtFactory(30, RED);
    DB_NULL->parent->right->right->parent = DB_NULL->parent->right;

    rbt *temp = DB_NULL->parent;

    if (checkSixthRemoveFixupCase(DB_NULL)) {
        sixthRemoveFixup(&tree);
    }

    return 0;
}