# CIRCULAR LINKED LIST CHEAT SHEET

## Core Concept
**Last node points back to first** - No NULL, forms a circle

## Memory Trick
⭕ **"Round Table"** - Everyone sits in a circle, no beginning or end

## Node Structure
```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *tail = NULL;  // Track tail (tail->next is head!)
```

## Why Track TAIL not HEAD?
- **tail->next** = head (easy access to both ends)
- Insert at end = O(1)
- Insert at start = O(1)

## Essential Operations

### 1. Insert at End (O(1))
```c
void insertAtEnd(int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    
    if (!tail) {  // Empty list
        newNode->next = newNode;  // Points to itself!
        tail = newNode;
    } else {
        newNode->next = tail->next;  // Point to head
        tail->next = newNode;        // Old tail points to new
        tail = newNode;              // Update tail
    }
}
```

### 2. Delete Node (O(n))
```c
int deleteNode(int val) {
    if (!tail) return 0;
    
    Node *curr = tail->next;  // Start at head
    Node *prev = tail;
    
    do {
        if (curr->data == val) {
            // Single node
            if (curr->next == curr) {
                tail = NULL;
            } else {
                prev->next = curr->next;
                if (curr == tail) tail = prev;  // Deleting tail
            }
            free(curr);
            return 1;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);
    
    return 0;
}
```

### 3. Display (O(n))
```c
void display() {
    if (!tail) return;
    
    Node *temp = tail->next;  // Start at head
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);  // Stop when back at head
}
```

## Key Pattern: do-while Loop
```c
Node *temp = tail->next;
do {
    // Process temp
    temp = temp->next;
} while (temp != tail->next);
```
**Why?** Must visit at least one node before checking condition

## Remember: 3 Special Cases
1. **Empty list**: `tail == NULL`
2. **Single node**: `tail->next == tail`
3. **Deleting tail**: Update tail pointer

## Common Mistakes
❌ Using `while (temp)` → Infinite loop!
✓ Use `while (temp != tail->next)`

❌ Using `while (temp->next != NULL)` → Never NULL!
✓ Check against starting point

## Real-World Examples
- Round-robin scheduling
- Multiplayer games (turn-based)
- Music playlist (repeat mode)
