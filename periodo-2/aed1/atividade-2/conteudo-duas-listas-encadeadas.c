#include <stdio.h>

int main() {
    int n, m;

    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    scanf("%d", &m);

    int b[m];

    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    int estaContido;

    for (int i = 0; i < m; i++) {
        estaContido = 0;
        
        for (int j = 0; j < n; j++) {
            if (b[i] == a[j]) {
                estaContido = 1;
                break;
            }
        }

        if (!estaContido) {
            break;
        }
    }

    printf("%d\n", estaContido);
    
    return 0;
}