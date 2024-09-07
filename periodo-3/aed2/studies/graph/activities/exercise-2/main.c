#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    char name;
    struct node *next;
} node;


node *nodeFactory(char name) {
    node *n = (node *) malloc(sizeof(node));

    n->name = name;
    n->next = NULL;
    
    return n;
}

void nodeAppend(node **s, node *d) {
    if (*s == NULL) {
        *s = d;
    } else {
        node *iterator = *s;

        while (iterator->next != NULL) {
            iterator = iterator->next;
        }

        iterator->next = d;
    }
}

int nodeIsInList(node *n, char name) {
    if (n != NULL) {
        while (n->next != NULL) {
            if (n->name == name) {
                return 1;
            }

            n = n->next;
        }
    }

    return 0;
}

int main(int argc, char *argv) {
    int v, e;

    scanf("%i %i", &v, &e);
    getchar();

    node *adjacences[v];

    for (int i = 0; i < v; i++) {
        char name;

        scanf("%c", &name);
        getchar();

        adjacences[i] = nodeFactory(name);
    }

    for (int i = 0; i < e; i++) {
        char edge[2];

        scanf("%c%c", &edge[0], &edge[1]);
        getchar();

        for (int j = 0; j < v; j++) {
            if (adjacences[j]->name == edge[0] && !nodeIsInList(adjacences[j], edge[1])) {
                nodeAppend(&adjacences[j], nodeFactory(edge[1]));
            }

            if (adjacences[j]->name == edge[1] && !nodeIsInList(adjacences[j], edge[0])) {
                nodeAppend(&adjacences[j], nodeFactory(edge[0]));
            }
        }
    }

    for (int i = 0; i < v; i++) {
        node *iterator = adjacences[i];

        printf("%c:", iterator->name);

        iterator = iterator->next;

        while (iterator != NULL) {
            printf(" %c", iterator->name);
            iterator = iterator->next;
        }

        printf("\n");
    }

    return 0;
}