#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int value;
    struct node *next;
};

void addFirst(struct node **head, int item);
void addLast(struct node **head, int item);
void reverseList(struct node **source, struct node **dest);
void sortListEvenOdd(struct node **source, struct node **dest);

int main() {
    struct node *list = NULL;
    char input[1024 * 15];

    fgets(input, sizeof(input), stdin) != NULL;

    char *token = strtok(input, " ");
    int value;

    while (token != NULL) {
        sscanf(token, "%d", &value);
        addLast(&list, value);
        token = strtok(NULL, " ");
    }

    struct node *reversedList = NULL;

    reverseList(&list, &reversedList);

    struct node *reverseIterator = reversedList;

    printf("Invert:");
    while (reverseIterator != NULL) {
        printf(" %d", reverseIterator->value);

        reverseIterator = reverseIterator->next;
    }
    printf("\n");

    struct node *sortedListEvenOdd = NULL;

    sortListEvenOdd(&list, &sortedListEvenOdd);

    struct node *sortedListEvenOddIterator = sortedListEvenOdd;

    printf("ParImp:");
    while (sortedListEvenOddIterator != NULL) {
        printf(" %d", sortedListEvenOddIterator->value);

        sortedListEvenOddIterator = sortedListEvenOddIterator->next;
    }
    printf("\n");

    sortedListEvenOddIterator = sortedListEvenOdd;
    reverseIterator = reversedList;

    printf("Soma:");

    while (sortedListEvenOddIterator != NULL) {
        printf(" %d", sortedListEvenOddIterator->value + reverseIterator->value);

        sortedListEvenOddIterator = sortedListEvenOddIterator->next;
        reverseIterator = reverseIterator->next;
    }
    printf("\n");

    return 0;
}

void addFirst(struct node **head, int item) {
    if (*head == NULL) {
        *head = (struct node *) malloc(sizeof(struct node));
        (*head)->value = item;
    } else {
        struct node *temp = *head;
        struct node *newNode = (struct node *) malloc(sizeof(struct node));

        newNode->value = item;
        newNode->next = temp;

        *head = newNode;
    }
}

void addLast(struct node **head, int item) {
    if (*head == NULL) {
        *head = (struct node *) malloc(sizeof(struct node));
        (*head)->value = item;
    } else {
        struct node *temp = *head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        struct node *newNode = (struct node *) malloc(sizeof(struct node));
        newNode->value = item;
        temp->next = newNode;
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

void sortListEvenOdd(struct node **source, struct node **dest) {
    if (*source == NULL) return;

    struct node *iterator = *source;
    int c = 0;

    while (iterator != NULL) {
        if (c % 2 == 0) addLast(dest, iterator->value);

        iterator = iterator->next;
        c++;
    }

    iterator = *source;
    c = 0;

    while (iterator != NULL) {
        if (c % 2 != 0) addLast(dest, iterator->value);

        iterator = iterator->next;
        c++;
    }
}