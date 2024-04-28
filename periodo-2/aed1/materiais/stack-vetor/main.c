#include <stdio.h>
#include "stack.h"

int main(void) {
  stack *s;
  s = create();

  push(1, s);
  push(2, s);
  push(5, s);
  push(3, s);

  printf("\nElement at top: %d", peek(s));
  printf("\nRemoved element at top: %d", pop(s));
  printf("\nElement at top: %d", peek(s));
  printf("\nRemoved element at top: %d", pop(s));
  printf("\nRemoved element at top: %d", pop(s));
  printf("\nRemoved element at top: %d", pop(s));
  
  return 0;
}