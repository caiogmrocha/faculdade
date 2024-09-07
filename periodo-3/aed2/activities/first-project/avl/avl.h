#ifndef AVL_H
#define AVL_H

typedef struct avl {
    int value, bf;
    struct avl *left, *right;
} avl;

avl *avlFactory(int value);

/**
 * Inserts a value into the AVL tree.
 * 
 * @param tree The tree to insert the value into.
 * @param value The value to insert.
 * @param grew A flag to indicate if the tree grew.
*/
void avlInsert(avl **tree, int value, short *grew);

/**
 * Removes a value from the AVL tree.
 * 
 * @param tree The tree to remove the value from.
 * @param value The value to remove.
 * @param shrank A flag to indicate if the tree shrank.
*/
void avlRemove(avl **tree, int value, short *shrank);

/**
 * Fixup the AVL tree.
 * 
 * @param node The node to fixup.
*/
void avlFixup(avl **node);

/**
 * Rotates the AVL tree to the left.
 * 
 * @param node The node to rotate.
*/
void avlRotateLeft(avl **node);

/**
 * Rotates the AVL tree to the right.
 * 
 * @param node The node to rotate.
*/
void avlRotateRight(avl **node);

/**
 * Rotates the AVL tree to the left and then to the right
 * (double right rotation).
 * 
 * @param node The node to rotate.
*/
void avlRotateLeftRight(avl **node);

/**
 * Rotates the AVL tree to the right and then to the left
 * (double left rotation).
 * 
 * @param node The node to rotate.
*/
void avlRotateRightLeft(avl **node);

/**
 * Gets the balance factor of the AVL tree.
 * 
 * @param tree The tree to get the balance factor from.
 * @return The balance factor of the tree.
*/
int avlBalanceFactor(avl *tree);

/**
 * Gets the height of the AVL tree.
 * 
 * @param tree The tree to get the height from.
 * @return The height of the tree.
*/
int avlHeight(avl *tree);

/**
 * Pre-order traversal of the AVL tree.
 * 
 * @param tree The tree to traverse.
 * @param cb The callback function to call for each node.
*/
void avlPreOrderTraversal(avl *tree, void cb(avl *node));

/**
 * Post-order traversal of the AVL tree.
 * 
 * @param tree The tree to traverse.
 * @param cb The callback function to call for each node.
*/
void avlPostOrderTraversal(avl *tree, void cb(avl *node));

#endif