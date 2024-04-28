#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int *array;
    int amount;
    struct node *next;
};

void stackup(struct node **stack, int *array, int amount);
void unstack(struct node **stack);
void print(struct node *stack);

int main() {
    struct node *stack = NULL;
    char operation[4];
    char numbers[1024];
    int value;
    int flag = 0;

    while (1) {
        scanf("%s", operation);
        getchar();


        if (strstr(operation, "PUSH") != NULL) {
            fgets(numbers, sizeof(numbers), stdin);

            char *token = strtok(numbers, " ");
            int *numbersArray = NULL;
            int c = 0;
            
            while (token != NULL) {
                sscanf(token, "%d", &value);
                numbersArray = (int *) realloc(numbersArray, (c + 1) * sizeof(int));
                numbersArray[c] = value;
                token = strtok(NULL, " ");
                c++;
            }

            stackup(&stack, numbersArray, c);
        } else {
            unstack(&stack);

            if (flag) break;
            if (stack == NULL) flag = 1;
        }
    }

    return 0;
}


void stackup(struct node **stack, int *array, int amount) {
    if (*stack == NULL) {
        *stack = (struct node *) malloc(sizeof(struct node));
        (*stack)->array = (int *) malloc(amount * sizeof(int));
        memcpy((*stack)->array, array, amount * sizeof(int));
        (*stack)->amount = amount;
        (*stack)->next = NULL;
    } else {
        struct node *newNode = (struct node *) malloc(sizeof(struct node));

        newNode->array = (int *) malloc(amount * sizeof(int));
        memcpy(newNode->array, array, amount * sizeof(int));
        newNode->amount = amount;
        newNode->next = *stack;
        *stack = newNode;
    }
}

void unstack(struct node **stack) {
    if (*stack == NULL) {
        printf("EMPTY STACK\n");
        return;
    }

    for (int i = 0; i < (*stack)->amount; i++) {
        if (i == (*stack)->amount - 1) {
            printf("%d\n", (*stack)->array[i]);
        } else {
            printf("%d ", (*stack)->array[i]);
        }
    }

    // free((*stack)->array);

    if ((*stack)->next == NULL) {
        // free(*stack);
        *stack = NULL;
        return;
    }

    struct node *temp = *stack;

    *stack = (*stack)->next;

    // free(temp);
}

void print(struct node *stack) {
    struct node *iterator = stack;
    
    while (iterator != NULL) {
        for (int i = 0; i < iterator->amount; i++) {
            if (iterator->next == NULL) {
                printf("%d\n", iterator->array[i]);
            } else {
                printf("%d ", iterator->array[i]);
            }
        }

        iterator = iterator->next;
    }
}
