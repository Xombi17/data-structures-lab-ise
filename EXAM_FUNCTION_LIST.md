# 📚 DATA STRUCTURES - COMPLETE FUNCTION LIST FOR EXAM

## **ALL FUNCTIONS YOU NEED TO PREPARE**

### **STACK** 🥞
```c
void init(Stack *s)
int isEmpty(Stack *s)
int isFull(Stack *s)
void push(Stack *s, int val)
int pop(Stack *s)
int peek(Stack *s)
void modifyTop(Stack *s, int new_val)
void display(Stack *s)
```

### **QUEUE** 🎫
```c
void init(Queue *q)
int isEmpty(Queue *q)
int isFull(Queue *q)
void enqueue(Queue *q, int val)
int dequeue(Queue *q)
int front(Queue *q)
void modifyFront(Queue *q, int new_val)
void display(Queue *q)
// Special: serveAndRequeue() for ride queue
```

### **CIRCULAR QUEUE** 🎡
```c
void init(CircularQueue *cq)
int isEmpty(CircularQueue *cq)
int isFull(CircularQueue *cq)
void enqueue(CircularQueue *cq, int val)
int dequeue(CircularQueue *cq)
int front(CircularQueue *cq)
void display(CircularQueue *cq)
```

### **DEQUE** 🚂
```c
void init(Deque *d)
int isEmpty(Deque *d)
int isFull(Deque *d)
void addFront(Deque *d, int val)
void addRear(Deque *d, int val)
int removeFront(Deque *d)
int removeRear(Deque *d)
void modifyFront(Deque *d, int new_val)
void modifyRear(Deque *d, int new_val)
int getFront(Deque *d)
int getRear(Deque *d)
void display(Deque *d)
```

### **SINGLY LINKED LIST** 🚂
```c
Node* createNode(int data)
void insertAtBeginning(int val)
void insertAtEnd(int val)
void insertAtPosition(int val, int pos)
void deleteAtPosition(int pos)
int deleteByValue(int val)
void removeLast()
int modifyValue(int old_val, int new_val)
void display()
```

### **DOUBLY LINKED LIST** 🔗
```c
Node* createNode(int data)
void addAtStart(int val)
void addAtEnd(int val)
void insertAtPosition(int val, int pos)
void removeFromStart()
void removeFromEnd()
int deleteByValue(int val)
int modifyValue(int old_val, int new_val)
void displayForward()
void displayBackward()
```

### **CIRCULAR LINKED LIST** ⭕
```c
Node* createNode(int data)
void addPlayer(int val)
void insertAtEnd(int val)
int removePlayer(int val)
int changeID(int old_val, int new_val)
void display()
// Special: enqueue/dequeue for circular queue implementation
```

### **BINARY TREE** 🌳
```c
Node* createNode(int data)
Node* findNode(Node *root, int val)
int addNode(Node *root, int val, int parent_val)
int removeNode(Node *root, int val)
int modifyNode(Node *root, int old_val, int new_val)
void preorderTraversal(Node *root)
void inorderTraversal(Node *root)
void postorderTraversal(Node *root)
void display(Node *root)
```

### **BINARY SEARCH TREE** 📚
```c
Node* createNode(int data)
Node* insert(Node *root, int val)
Node* delete(Node *root, int val)
Node* search(Node *root, int val)
Node* findMin(Node *root)
Node* findMax(Node *root)
void updateValue(Node *root, int old_val, int new_val)
void inorderTraversal(Node *root)  // For sorted display
```

---

## 🎯 **CORE PATTERNS TO MASTER**

### **Array-Based Structures:**
- **Initialization**: `front=0, rear=-1, top=-1`
- **Empty check**: `size==0` or `top==-1`
- **Full check**: `size==MAX` or `top==MAX-1`
- **Circular arithmetic**: `(index + 1) % MAX`
- **Backward movement**: `(index - 1 + MAX) % MAX`

### **Linked List Patterns:**
- **Traversal**: `while(temp) { temp = temp->next; }`
- **Insertion**: Create → Link → Update pointers
- **Deletion**: Find → Bypass → Free
- **Circular**: `do-while` loop with `tail->next` check
- **Doubly**: Update both `next` AND `prev` pointers

### **Tree Patterns:**
- **Recursive base case**: `if(!root) return;`
- **BST property**: `left < root < right`
- **Traversals**: 
  - Pre-order: Root → Left → Right
  - In-order: Left → Root → Right (sorted for BST)
  - Post-order: Left → Right → Root
- **Search**: Compare and go left/right

---

## 📊 **TIME COMPLEXITY QUICK REFERENCE**

| **Data Structure** | **Insert** | **Delete** | **Search** | **Access** |
|-------------------|------------|------------|------------|------------|
| **Stack** | O(1) | O(1) | O(n) | O(n) |
| **Queue** | O(1) | O(1) | O(n) | O(n) |
| **Singly LL** | O(1)/O(n) | O(1)/O(n) | O(n) | O(n) |
| **Doubly LL** | O(1) | O(1) | O(n) | O(n) |
| **Binary Tree** | O(n) | O(n) | O(n) | O(n) |
| **BST** | O(log n) | O(log n) | O(log n) | O(log n) |

---

## 🔑 **KEY FORMULAS TO REMEMBER**

### **Circular Queue/Deque:**
```c
// Move forward
next_index = (current + 1) % MAX

// Move backward  
prev_index = (current - 1 + MAX) % MAX

// Check full (when using front/rear)
isFull = (rear + 1) % MAX == front
```

### **BST Delete Cases:**
1. **No children**: Just delete
2. **One child**: Replace with child
3. **Two children**: Replace with inorder successor

### **Linked List Edge Cases:**
- Empty list: `head == NULL`
- Single node: `head->next == NULL`
- Circular single: `tail->next == tail`

---

## 📝 **EXAM STRATEGY**

### **Must Practice:**
1. ✅ **Basic CRUD operations** for each structure
2. ✅ **Traversal patterns** (especially linked lists & trees)
3. ✅ **Edge case handling** (empty, single element, full)
4. ✅ **Memory management** (malloc/free for linked structures)
5. ✅ **Menu-driven programs** with switch cases

### **Common Exam Questions:**
- Implement stack using array/linked list
- Convert infix to postfix using stack
- Implement queue using circular array
- Reverse a linked list
- Find height/depth of binary tree
- Insert/delete in BST
- Check if binary tree is BST

### **Quick Revision Tips:**
- **Stack**: LIFO, push/pop from top
- **Queue**: FIFO, enqueue rear/dequeue front  
- **Deque**: Operations at both ends
- **Linked List**: Dynamic, pointer manipulation
- **Trees**: Recursive operations, traversals
- **BST**: Ordered tree, efficient search

---

**🎯 This covers ALL functions from your 26 problem statements!**

**Good luck with your exam preparation! 🚀**
