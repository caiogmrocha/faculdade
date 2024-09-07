// "rbt" means "red-black tree"

#ifndef RBT_H
#define RBT_H

typedef enum colors { RED, BLACK, DOUBLE_BLACK } colors;

typedef struct rbt {
    struct rbt *parent, *left, *right;
    int value;
    colors color;
} rbt;

extern rbt *DB_NULL;

/**
 * Inicializa a variável global do nó duplo-preto
*/
void rbtBootstrap();

/**
 * Libera a memória de um nó
 * 
 * @param tree Ponteiro para o nó a ser liberado
*/
void rbtFreeNode(rbt **tree);

/**
 * Insere um valor em uma árvore
 * 
 * @param tree Ponteiro para a árvore
 * @param value Valor a ser inserido
*/
void rbtInsert(rbt **tree, int value);

/**
 * Remove um valor de uma árvore
 * 
 * @param tree Ponteiro para a árvore
 * @param value Valor a ser removido
*/
void rbtRemove(rbt **tree, int value);

/**
 * Realizar uma travessia em pré-ordem
 * 
 * @param tree Ponteiro para a árvore
 * @param cb Função de callback
*/
void rbtPreOrderTraversal(rbt **tree, void cb(rbt **tree));

/**
 * Realizar uma travessia em ordem
 * 
 * @param tree Ponteiro para a árvore
 * @param cb Função de callback
*/
void rbtInOrderTraversal(rbt **tree, void cb(rbt **tree));

/**
 * Realizar uma travessia em pós-ordem
 * 
 * @param tree Ponteiro para a árvore
 * @param cb Função de callback
*/
void rbtPostOrderTraversal(rbt **tree, void cb(rbt **tree));

#endif