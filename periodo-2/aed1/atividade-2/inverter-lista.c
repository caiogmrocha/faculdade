#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int value;
    struct node *next;
};

void addLast(struct node **head, int value);
void addFirst(struct node **head, int value);
void reverseList(struct node **source, struct node **dest);

int main() {
    struct node *head;
    char input[1024 * 1024];

    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " ");
    int value;

    while (token != NULL) {
        sscanf(token, "%d", &value);
        addLast(&head, value);
        token = strtok(NULL, " ");
    }

    struct node *reversed;

    reverseList(&head, &reversed);

    struct node *iterator = reversed;

    while (iterator != NULL) {
        printf("%d ", iterator->value);
        iterator = iterator->next;
    }

    return 0;
}

void addLast(struct node **head, int value) {
    if (*head == NULL) {
        *head = (struct node *) malloc(sizeof(struct node));
        (*head)->value = value;
        (*head)->next = NULL;
    } else {
        struct node *iterator = *head;

        while (iterator->next != NULL) {
            iterator = iterator->next;
        }

        struct node *newNode = (struct node *) malloc(sizeof(struct node));

        newNode->value = value;
        newNode->next = NULL;

        iterator->next = newNode;
    }
}

void addFirst(struct node **head, int value) {
    if (*head == NULL) {
        *head = (struct node *) malloc(sizeof(struct node));
        (*head)->value = value;
    } else {
        struct node *temp = *head;
        struct node *newNode = (struct node *) malloc(sizeof(struct node));

        newNode->value = value;
        newNode->next = temp;

        *head = newNode;
    }
}

void reverseList(struct node **source, struct node **dest) {
    if (*source == NULL) return;

    struct node *sourceIterator = *source;

    while (sourceIterator != NULL) {
        addFirst(dest, sourceIterator->value);

        sourceIterator = sourceIterator->next;
    }
}