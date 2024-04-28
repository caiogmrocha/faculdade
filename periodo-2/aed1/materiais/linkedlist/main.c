#include <stdio.h>
#include "linkedlist.h"

int main(void) {
  
  struct node *head;
  init(&head);
  addFirst(&head, 10);
  addFirst(&head, 20);
  addFirst(&head, 30);
  printList(&head);
  addLast(&head, 40);
  addLast(&head, 50);
  addLast(&head, 60);
  printList(&head);
  removeAtPosition(&head, 1);
  printList(&head);
  removeAtPosition(&head, 1);
  printList(&head);

  int *a = toArray(&head);
  printf("\nArray: ");
  for(int i=0; i<size(&head); i++)
    printf("%d ", a[i]);

  struct node *element = get(&head, 2);
  printf("\nElement at position %d: %d", 2, element->key);

  struct node *last = getLast(&head);
  printf("\nLast element: %d", last->key);

  element = removeFirst(&head);
  printf("\nElement removed: %d", element->key);
  printList(&head);

  element = removeFirst(&head);
  printf("\nElement removed: %d", element->key);
  printList(&head);

  addAtPosition(&head, 1, 10);
  printList(&head);

  addAtPosition(&head, 2, 20);
  printList(&head);

  element = getFirst(&head);
  printf("\nFirst element: %d", element->key);

  addAtPosition(&head,3, 10);
  printList(&head);
  printList(&head);

  element->key = 20;

  printf("\nElement at position: %d", indexOf(&head, element->key));
/*
  removeFirstOccurrence(&head, element->next);
  printList(&head);*/
  
  return 0;
}