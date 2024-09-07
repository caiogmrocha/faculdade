#include <stdio.h>

int hasEdge(char a, char b, char edges[][2], int e) {
    for (int i = 0; i < e; i++) {
        if (
            (edges[i][0] == a && edges[i][1] == b) ||
            (edges[i][1] == a && edges[i][0] == b) ||
            a == b
        ) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char *argv) {
    int v, e;

    scanf("%i %i\n", &v, &e);

    char vertices[v];

    for (int i = 0; i < v; i++) {
        scanf("%c", &vertices[i]);
        getchar();
    }

    char edges[e][2];
    
    for (int i = 0; i < e; i++) {
        scanf("%c%c", &edges[i][0], &edges[i][1]);
        getchar();
    }

    for (int i = -1; i < v; i++) {
        printf(" %c", vertices[i]);
    }

    printf("\n");

    for (int i = 0; i < v; i++) {
        printf("%c", vertices[i]);

        for (int j = 0; j < v; j++) {
            printf(" %i", hasEdge(vertices[i], vertices[j], edges, e));
        }

        printf("\n");
    }

    return 0;
}