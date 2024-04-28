#define MAX_SIZE 50

typedef struct{
  int itens[MAX_SIZE];
  int topo;
}stack;

stack* create();

//Tests if this stack is empty.
int	isEmpty(stack *s);
//Tests if this stack is full.
int	isFull(stack *s);
//Looks at the object at the top of this stack without removing it from the stack.
int	peek(stack *s);
//Removes the object at the top of this stack and returns that object as the value of this function.
int	pop(stack *s);
//Pushes an item onto the top of this stack.
int	push(int item,stack *s);