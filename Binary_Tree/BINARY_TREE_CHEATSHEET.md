# BINARY TREE CHEAT SHEET

## Core Concept
**Each node has at most 2 children** (left and right)

## Memory Trick
🌳 **"Family Tree"** - Parent with max 2 children

## Node Structure
```c
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *root = NULL;
```

## Three Traversals (MEMORIZE!)

### 1. Pre-Order: Root → Left → Right
```c
void preorder(Node *root) {
    if (root) {
        printf("%d ", root->data);  // Visit root FIRST
        preorder(root->left);
        preorder(root->right);
    }
}
```
**Use**: Copy tree, prefix expression

### 2. In-Order: Left → Root → Right
```c
void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);  // Visit root MIDDLE
        inorder(root->right);
    }
}
```
**Use**: Get sorted order (in BST)

### 3. Post-Order: Left → Right → Root
```c
void postorder(Node *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);  // Visit root LAST
    }
}
```
**Use**: Delete tree, postfix expression

## Memory Trick for Traversals
- **PRE**-order: Visit **PRE**viously (root first)
- **IN**-order: Visit **IN** the middle
- **POST**-order: Visit **POST**poned (root last)

## Recursive Pattern (All operations)
```c
void operation(Node *root) {
    if (!root) return;  // Base case
    
    // Do something with root
    operation(root->left);   // Recurse left
    operation(root->right);  // Recurse right
}
```

## Find Node (Recursive)
```c
Node* findNode(Node *root, int val) {
    if (!root) return NULL;
    if (root->data == val) return root;
    
    Node *left = findNode(root->left, val);
    if (left) return left;
    
    return findNode(root->right, val);
}
```

## Common Mistakes
❌ Forgetting base case `if (!root) return;`
✓ Always check NULL first

❌ Wrong traversal order
✓ Remember: PRE-IN-POST = Root position

## Real-World Examples
- File system hierarchy
- Organization chart
- Expression trees
- Decision trees
