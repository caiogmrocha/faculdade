#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int value;
    struct node *next;
};

void enqueue(struct node **queue, int value);
void dequeue(struct node **queue);
void print(struct node *head);

int main() {
    struct node *queue;
    char operation[100];
    int value;

    while (1) {
        fgets(operation, sizeof(operation), stdin);

        if (strstr(operation, "Enfileirar") != NULL) {
            sscanf(operation, "Enfileirar %d", &value);
            enqueue(&queue, value);
        } else if (strstr(operation, "Desenfileirar") != NULL) {
            dequeue(&queue);
        } else if (strstr(operation, "Imprimir") != NULL) {
            print(queue);
        } else {
            break;
        }
    }

    return 0;
}

void enqueue(struct node **queue, int value) {
    if (*queue == NULL) {
        *queue = (struct node *) malloc(sizeof(struct node));
        (*queue)->value = value;
        (*queue)->next = NULL;
    } else {
        struct node *iterator = *queue;

        while (iterator->next != NULL) {
            iterator = iterator->next;
        }

        struct node *newNode = (struct node *) malloc(sizeof(struct node));

        newNode->value = value;
        newNode->next = NULL;
        iterator->next = newNode;
    }
}

void dequeue(struct node **queue) {
    if (*queue == NULL) return;

    if ((*queue)->next == NULL) {
        return free(*queue);
    }

    struct node *temp = *queue;

    *queue = (*queue)->next;

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