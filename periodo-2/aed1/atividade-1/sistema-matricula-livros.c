#include <stdio.h>
#include <string.h>

int main() {
    int n;

    scanf("%d", &n);

    char livros[n+1][1024];
    
    getchar();

    for (int i = 0; i < n+1; i++) {
        fgets(livros[i], sizeof(livros[i]), stdin);
    }

    int flag = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(livros[i], livros[n]) == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        printf("Sim\n");
    } else {
        printf("Não\n");
    }


    return 0;
}