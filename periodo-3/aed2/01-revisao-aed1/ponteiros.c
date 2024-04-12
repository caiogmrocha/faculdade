#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv) {
    int *array = (int *) malloc(sizeof(int) * 1);

    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;

    printf("array[0] = %d\n", array[0]);
    printf("array[1] = %d\n", array[1]);
    printf("array[2] = %d\n", array[2]);
    printf("array[3] = %d\n", array[3]);
    printf("array[4] = %d\n", array[4]);

    return 0;
}