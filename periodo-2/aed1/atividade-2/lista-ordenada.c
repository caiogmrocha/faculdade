#include <stdio.h>
#include <stdlib.h>

struct node {
    int dado;
    struct node *proximo;
};

// void addPosition(struct node **head, int value, int position) {
//     if (*head == NULL) {
//         *head = (struct node *) malloc(sizeof(struct node));
//         (*head)->value = value;
//         (*head)->next = NULL;
//     } else {
//         int c = 0;
//         struct node *iterator = *head;

//         while (iterator->next != NULL && ++c < position) {
//             iterator = iterator->next;
//         }

//         struct node *newNode = (struct node *) malloc(sizeof(struct node));
        
//         newNode->value = value;
//         newNode->next = iterator->next;
//         iterator->next = newNode;
//     }
// }

// void removePosition(struct node **head, int position) {
//     if (*head == NULL) return;
    
//     if (position == 0) {
//         *head = (*head)->next;
//         return;
//     }
    
//     int c = 0;
//     struct node *iterator = *head;

//     while (iterator->next != NULL && ++c < position) {
//         iterator = iterator->next;
//     }

//     if (iterator == NULL) return;

//     printf("valor: %d\n", iterator->value);

//     struct node *temp = iterator->next;

//     iterator->next = iterator->next->next;

//     free(temp);
// }

int main() {
    struct node *list;

    inserir(&list, 4);
    inserir(&list, 5);
    inserir(&list, 3);
    inserir(&list, 3);
    inserir(&list, 1);
    // inserir(&list, 4);
    // inserir(&list, 3);
    // inserir(&list, 3);
    printf("%d\n", list->dado);
    printf("%d\n", list->proximo->dado);
    printf("%d\n", list->proximo->proximo->dado);

    return 0;
}