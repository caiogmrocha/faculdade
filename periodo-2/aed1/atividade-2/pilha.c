#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int value;
    struct node *next;
};

void stackup(struct node **stack, int value);
void unstack(struct node **stack);
void print(struct node *head);

int main() {
    struct node *stack;
    char operation[100];
    int value;

    while (1) {
        fgets(operation, sizeof(operation), stdin);

        if (strstr(operation, "Empilhar") != NULL) {
            sscanf(operation, "Empilhar %d", &value);
            stackup(&stack, value);
        } else if (strstr(operation, "Desempilhar") != NULL) {
            unstack(&stack);
        } else if (strstr(operation, "Imprimir") != NULL) {
            print(stack);
        } else {
            break;
        }
    }

    return 0;
}

void stackup(struct node **stack, int value) {
    if (*stack == NULL) {
        *stack = (struct node *) malloc(sizeof(struct node));
        (*stack)->value = value;
        (*stack)->next = NULL;
    } else {
        struct node *newNode = (struct node *) malloc(sizeof(struct node));

        newNode->value = value;
        newNode->next = *stack;
        *stack = newNode;
    }
}

void unstack(struct node **stack) {
    if (*stack == NULL) return;

    if ((*stack)->next == NULL) {
        return free(*stack);
    }

    struct node *temp = *stack;

    *stack = (*stack)->next;

    free(temp);
}

void print(struct node *head) {
    struct node *iterator = head;

    while (iterator != NULL) {
        if (iterator->next == NULL) {
            printf("%d\n", iterator->value);
        } else {
            printf("%d ", iterator->value);
        }

        iterator = iterator->next;
    }
}