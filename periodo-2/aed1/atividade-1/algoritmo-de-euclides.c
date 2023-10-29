#include <stdio.h>

int mdc(int n1, int n2);

int main() {
    int casos;

    scanf("%d", &casos);

    for (int i = 0; i < casos; i++) {
        int n1, n2;

        scanf("%d %d", &n1, &n2);
        printf("MDC(%d,%d) = %d\n", n1, n2, mdc(n1, n2));
    }

    return 0;
}


int mdc(int n1, int n2) {
    if (n1 % n2 != 0)
        return mdc(n2, n1 % n2);
    else
        return n2;
}