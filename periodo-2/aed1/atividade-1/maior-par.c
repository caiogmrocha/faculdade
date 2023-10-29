#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // input
    char numberList[1000];
    int *treatedNumberList = NULL;

    fgets(numberList, sizeof(numberList), stdin);

    char *token = strtok(numberList, "[, ]");
    int counter = 0;

    while (token != NULL) {
        counter++;
        treatedNumberList = (int *) realloc(treatedNumberList, counter * sizeof(int));

        treatedNumberList[counter - 1] = atoi(token);

        token = strtok(NULL, "[, ]");
    }

    // calc
    int majorEven = treatedNumberList[0];

    for (int i = 0; i < counter; i++) {
        if (treatedNumberList[i] > majorEven) {
            majorEven = treatedNumberList[i];
        }
    }

    printf("%d\n", majorEven);

    free(treatedNumberList);
    free(token);
}