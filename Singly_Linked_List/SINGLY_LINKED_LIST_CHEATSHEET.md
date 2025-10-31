# SINGLY LINKED LIST CHEAT SHEET

## Core Concept
**One-way chain** - Each node points to NEXT only

## Memory Trick
🚂 **"Train Cars"** - Each car connected to next, can only move forward

## Node Structure
```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;  // Start of list
```

## Essential Operations

### 1. Insert at Beginning (O(1))
```c
void insertAtStart(int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = head;  // Point to old head
    head = newNode;        // Update head
}
```

### 2. Insert at End (O(n))
```c
void insertAtEnd(int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    
    if (!head) { head = newNode; return; }
    
    Node *temp = head;
    while (temp->next) temp = temp->next;  // Reach end
    temp->next = newNode;
}
```

### 3. Delete at Position (O(n))
```c
void deleteAtPos(int pos) {
    if (!head) return;
    
    if (pos == 0) {  // Delete head
        Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    
    Node *temp = head;
    for (int i = 0; i < pos - 1 && temp; i++)
        temp = temp->next;
    
    if (temp && temp->next) {
        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    }
}
```

## Key Patterns

### Traversal Pattern
```c
Node *temp = head;
while (temp) {
    // Do something with temp->data
    temp = temp->next;
}
```

### Two-Pointer Pattern (for deletion)
```c
Node *prev = NULL, *curr = head;
while (curr) {
    // prev trails behind curr
    prev = curr;
    curr = curr->next;
}
```

## Remember: 3 Steps for Insertion
1. **Create** new node
2. **Link** new node to list
3. **Update** head/previous pointer

## Remember: 3 Steps for Deletion
1. **Find** node to delete
2. **Bypass** it (prev->next = curr->next)
3. **Free** memory

## Common Mistakes
❌ `head = newNode; newNode->next = head;` (loses list!)
✓ `newNode->next = head; head = newNode;` (correct order)

❌ Not checking `if (!head)` for empty list
✓ Always check before operations

## Real-World Examples
- Music playlist
- Browser history
- Undo operations
