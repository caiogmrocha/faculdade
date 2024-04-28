#include "stack.h"
#include <stdlib.h>

stack* create(){
  stack *s = (stack *) malloc(sizeof(stack));
  s->topo = -1;
  return s;
}

//Tests if this stack is empty.
int	isEmpty(stack *s){
  if(s == NULL || s->topo == -1)
    return 1;
  else
    return 0;
}

int	isFull(stack *s){
  if(s!=NULL && s->topo == MAX_SIZE-1)
    return 1;
  else 
    return 0;
}

//Looks at the object at the top of this stack without removing it from the stack.
int	peek(stack *s){
  if(isEmpty(s))
    return -1;
  else
    return s->itens[s->topo];
}
//Removes the object at the top of this stack and returns that object as the value of this function.
int	pop(stack *s){
  if(isEmpty(s))
    return -1;
  else
    return s->itens[s->topo--];
}
//Pushes an item onto the top of this stack.
int push(int item,stack *s){
  if(isFull(s)){ 
    return -1;
  }
  else{
    s->itens[++s->topo] = item;
    return 1;
  }
}
