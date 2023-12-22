    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    struct node {
        int value;
        struct node *next;
    };

    void addLast(struct node **head, int value);
    void sortAscending(struct node **head);

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

        sortAscending(&head);

        struct node *temp = head;

        while (temp != NULL) {
            printf("%d ", temp->value);
            temp = temp->next;
        }

        return 0;
    }

    void addLast(struct node **head, int value) {
        if (*head == NULL) {
            *head = (struct node *) malloc(sizeof(struct node));

            (*head)->value = value;
            (*head)->next = NULL;
        } else {
            struct node *temp = *head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = (struct node *) malloc(sizeof(struct node));
            temp->next->value = value;
            temp->next->next = NULL;
        }
    }

    void sortAscending(struct node **head) {
        struct node *iterator = *head;

        while (1) {
            if (iterator->next == NULL) break;

            if (iterator->value > iterator->next->value) {
                int temp = iterator->value;
                iterator->value = iterator->next->value;
                iterator->next->value = temp;

                sortAscending(head);
                break;
            } else {
                iterator = iterator->next;
            }
        }
    }

    // 4,3,2,1 | i > j == true -> troca
    // 3,4,2,1 | i > j == false -> i > j == true -> troca
    // 3,2,4,1 | i > j == true -> troca
    // 2,3,4,1 | i > j == false -> i > j == false -> i > j == true -> troca
    // 2,3,1,4 | i > j == false -> i > j == true -> troca
    // 2,1,3,4 | i > j == true -> troca
    // 1,2,3,4 | i > j == false -> i > j == false -> i > j == false -> i > j == false -> finaliza