# DOUBLY LINKED LIST CHEAT SHEET

## Core Concept
**Two-way chain** - Each node points to BOTH next AND previous

## Memory Trick
🔗 **"Two-Way Street"** - Can travel forward AND backward

## Node Structure
```c
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;  // Extra pointer!
} Node;

Node *head = NULL;
Node *tail = NULL;  // Track both ends
```

## Essential Operations

### 1. Insert at Beginning (O(1))
```c
void insertAtStart(int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->prev = NULL;
    
    if (!head) {  // Empty list
        newNode->next = NULL;
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
```

### 2. Insert at End (O(1) with tail!)
```c
void insertAtEnd(int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    
    if (!tail) {  // Empty list
        newNode->prev = NULL;
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}
```

### 3. Delete from Beginning (O(1))
```c
void deleteFromStart() {
    if (!head) return;
    
    Node *temp = head;
    if (head == tail) {  // Single node
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    free(temp);
}
```

## Key Advantage
**O(1) operations at BOTH ends** (with tail pointer)

## Remember: 4 Pointer Updates for Middle Insertion
```c
// Insert newNode between prev and curr
newNode->next = curr;
newNode->prev = prev;
prev->next = newNode;
curr->prev = newNode;
```

## Common Mistakes
❌ Forgetting to update **prev** pointers
✓ Always update BOTH next AND prev

❌ Not handling **head == tail** case
✓ Check for single node separately

## Real-World Examples
- Browser forward/back
- Music player (prev/next)
- Text editor (undo/redo)
