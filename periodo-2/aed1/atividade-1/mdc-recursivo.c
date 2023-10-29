#include <stdio.h>

int mdc(int n1, int n2);

int main() {
    int n1, n2;

    scanf("%d", &n1);
    scanf("%d", &n2);

    printf("%d\n", mdc(n1, n2));

    return 0;
}


int mdc(int n1, int n2) {
    if (n1 % n2 != 0)
        return mdc(n2, n1 % n2);
    else
        return n2;
}