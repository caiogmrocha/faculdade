struct node {
  int key;
  struct node *next;
};

void init(struct node **head);

int isEmpty(struct node **head);

// Inserts the specified element at the specified position in this list.
void addAtPosition(struct node **head, int index, int e);

// Inserts the specified element at the beginning of this list.
void addFirst(struct node **head, int e);

// Appends the specified element to the end of this list.
void addLast(struct node **head, int e);

// Removes all of the elements from this list.
void clear(struct node **head);

// Returns true if this list contains the specified element.
int contains(struct node **head, int e);

// Retrieves, but does not remove, the head (first element) of this list.
struct node *element(struct node **head);

// Returns the element at the specified position in this list.
struct node *get(struct node **head, int index);

// Returns the first element in this list.
struct node *getFirst(struct node **head);

// Returns the last element in this list.
struct node *getLast(struct node **head);

// Returns the index of the first occurrence of the specified element in this
// list, or -1 if this list does not contain the element.
int indexOf(struct node **head, int o);

// Returns the index of the last occurrence of the specified element in this
// list, or -1 if this list does not contain the element.
int lastIndexOf(struct node **head, struct node *o);

// Retrieves and removes the head (first element) of this list.
struct node *removeFirst(struct node **head);

// Removes the element at the specified position in this list.
struct node *removeAtPosition(struct node **head, int index);

// Removes the first occurrence of the specified element in this list (when
// traversing the list from head to tail).
int removeFirstOccurrence(struct node **head, struct node *o);

// Removes and returns the last element from this list.
struct node *removeLast(struct node **head);

// Removes the last occurrence of the specified element in this list (when
// traversing the list from head to tail).
int removeLastOccurrence(struct node **head, struct node *o);

// Replaces the element at the specified position in this list with the
// specified element.
struct node *set(struct node **head, int index, struct node *element);

// Returns the number of elements in this list.
int size(struct node **head);

// Returns an array containing all of the elements in this list in proper
// sequence (from first to last element).
int *toArray(struct node **head);

void printList(struct node **head);
