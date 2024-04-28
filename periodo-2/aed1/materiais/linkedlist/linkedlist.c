#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

void init(struct node **head){
  *head = NULL;
}

// Inserts the specified element at the beginning of this list.
void addFirst(struct node **head, int e){
  printf("\nAdding element %d", e);
  struct node *n = (struct node *) malloc(sizeof(struct node));
  n->key = e;
  n->next = *head;
  *head = n;  
}

void printList(struct node **head){
  if(isEmpty(head))
    printf("\nLista vazia!");
  else{
    printf("\nListando os elementos da lista: ");
    struct node *temp = *head;

    while(temp != NULL){
      printf("%d ", temp->key);
      temp = temp->next;
    }
  }
}

// Appends the specified element to the end of this list.
void addLast(struct node **head, int e){

   struct node *t = (struct node *) malloc(sizeof(struct node));
   t->key = e;
   t->next = NULL;
  
   if(isEmpty(head)){
     *head = t;
   }else{
     struct node *temp = *head;

     while(temp->next != NULL){
       temp = temp->next;
     }

     temp->next = t;
   }
}

// Removes all of the elements from this list.
void clear(struct node **head){
  *head = NULL;
}

// Returns true if this list contains the specified element.
int contains(struct node **head, int e){
  if(isEmpty(head))
    return 0;
  else{
    struct node *temp = *head;

     while(temp != NULL){
       if(temp->key == e)
         return 1;
       temp = temp->next;
     }

    return 0;
  }
}

// Retrieves, but does not remove, the head (first element) of this list.
struct node *element(struct node **head){
  if(isEmpty(head))
    return NULL;
  else
    return *head;
}

// Returns the element at the specified position in this list.
struct node *get(struct node **head, int index){
  if(isEmpty(head))
    return NULL;
  else{
    struct node *temp = *head;
    int i=0;

     while(temp != NULL && i<index){
       temp = temp->next;
       i++;
     }

    if(i==index)
      return temp;
    else
      return NULL;
  }    
}

int isEmpty(struct node **head){
  if(*head == NULL)
    return 1;
  else
    return 0;
}

// Returns the last element in this list.
struct node *getLast(struct node **head){
  if(isEmpty(head))
    return NULL;
  else{
    struct node *temp = *head;

     while(temp->next != NULL){
       temp = temp->next;
     }

    return temp;
  }
}

// Retrieves and removes the head (first element) of this list.
struct node *removeFirst(struct node **head){
  printf("\nRemoving first element");
  if(isEmpty(head))
    return NULL;
  else{
      struct node *temp = *head;
      *head = (*head)->next;
      return temp;
  }
}

// Removes the element at the specified position in this list.
struct node *removeAtPosition(struct node **head, int index){
    if(isEmpty(head))
      return NULL;
    else{
      struct node *temp = *head;
      int i = 0;

       while(temp != NULL && i<index-1){
         i++;
         temp = temp->next;
       }

      if(i == index-1){
        temp->next = temp->next->next;
        struct node *e = temp -> next;
        return e;
      }else{
        return NULL;
      }
    }
}

// Returns the number of elements in this list.
int size(struct node **head){
  if(isEmpty(head)){
    return 0;
  }
  else{
    struct node *temp = *head;
    int s = 0;
  
    while(temp != NULL){
      s++;
      temp = temp->next;
    }

    return s;
  }
}

// Returns an array containing all of the elements in this list in proper sequence (from first to last element).
int *toArray(struct node **head){
  if(isEmpty(head))
    return NULL;
  else{
    int s = size(head);
    int *v = (int *)malloc(sizeof(int)*s);
    if(v == NULL)
      return NULL;
    
    struct node *temp = *head;
    int i=0;
    
    while(temp != NULL){
      v[i++] = temp->key;
      temp = temp->next;
    }

    return v;
  }
}

// Returns the first element in this list.
struct node *getFirst(struct node **head){
  return (*head);
}

// Inserts the specified element at the specified position in this list.
//TO DO na aula 30-11
void addAtPosition(struct node **head, int index, int e){
  if(isEmpty(head) && index == 0)
    addFirst(head,  e);
  else{
      int s=size(head);
      if(index > s || index < 0){
        printf("\nPosição inválida!!");
        return ;
      }

      struct node *tmp = *head;
      int i=0; 

      while(tmp != NULL && i<index-1){
        tmp = tmp->next;
        i++;
      }

      if(i == index -1){
        struct node *n = (struct node * ) malloc(sizeof(struct node));
        n->key = e;
        n->next = tmp->next;
        tmp->next = n;
      }
    
  }
    
}

// Removes the first occurrence of the specified element in this list (when traversing the list from head to tail).
//TO DO na aula 30-11
int removeFirstOccurrence(struct node **head, struct node *o){
  if(isEmpty(head))
    return 0;
  else{
        if(size(head) == 1){
          if(getFirst(head)->key == o->key){
            removeFirst(head);
            return 1;
          }
          return 0;
        }
    
        struct node *tmp = *head; 

        while(tmp->next !=NULL && tmp->next->key != o->key){
          tmp = tmp->next;
        }

        if(tmp->next !=NULL ){
          tmp->next = tmp->next->next;
          return 1;
        }

      return 0;
  }

  
}

// Removes and returns the last element from this list.
//TO DO na aula 30-11
struct node *removeLast(struct node **head){
  if(isEmpty(head))
    return NULL;
  else{

    if(size(head) == 1)
      return removeFirst(head);
    else{
        struct node *tmp = *head; 
    
        while(tmp->next->next != NULL){
          tmp = tmp->next;
        }

        struct node *removed = tmp->next;
        tmp->next = NULL;
        return removed;
  }
}
}

// Removes the last occurrence of the specified element in this list (when traversing the list from head to tail).
//TO DO na aula 30-11
int removeLastOccurrence(struct node **head, struct node *o);

// Replaces the element at the specified position in this list with the
// specified element.
//TO DO na aula 30-11
struct node *set(struct node **head, int index, struct node *element);

// Returns the index of the first occurrence of the specified element in this list, or -1 if this list does not contain the element.
//TO DO na aula 30-11
int indexOf(struct node **head, int o){
    
    if(isEmpty(head))
      return -1;
    
    if(contains(head, o)){
      
      struct node *tmp = *head; 
      int i=0;

      while(tmp != NULL){
        
        if(tmp->key == o){
          return i;
        }
        tmp = tmp->next;
        i++;
      }
      return i;
    }else{
      return -1;
    }
    
}

// Returns the index of the last occurrence of the specified element in this list, or -1 if this list does not contain the element.
//TO DO na aula 30-11
int lastIndexOf(struct node **head, struct node *o);