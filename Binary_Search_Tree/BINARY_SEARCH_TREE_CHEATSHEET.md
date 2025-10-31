# BINARY SEARCH TREE (BST) CHEAT SHEET

## Core Concept
**Ordered Binary Tree**: Left < Root < Right

## Memory Trick
📚 **"Library Shelf"** - Books arranged in order, easy to find

## BST Property
```
For every node:
- All left subtree values < node value
- All right subtree values > node value
```

## Essential Operations

### 1. Insert (O(log n))
```c
Node* insert(Node *root, int val) {
    if (!root) return createNode(val);
    
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    
    return root;
}
```

### 2. Search (O(log n))
```c
Node* search(Node *root, int val) {
    if (!root || root->data == val) return root;
    
    if (val < root->data)
        return search(root->left, val);
    else
        return search(root->right, val);
}
```

### 3. Delete (O(log n)) - 3 Cases
```c
Node* delete(Node *root, int val) {
    if (!root) return root;
    
    if (val < root->data)
        root->left = delete(root->left, val);
    else if (val > root->data)
        root->right = delete(root->right, val);
    else {
        // Case 1: No children (leaf)
        if (!root->left && !root->right) {
            free(root);
            return NULL;
        }
        // Case 2: One child
        if (!root->left) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        if (!root->right) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Two children
        Node *temp = findMin(root->right);  // Inorder successor
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}
```

### 4. Find Minimum
```c
Node* findMin(Node *root) {
    while (root && root->left)
        root = root->left;
    return root;
}
```

## In-Order Traversal = Sorted Output
```c
void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);  // Prints in ascending order
        inorder(root->right);
    }
}
```

## Search Pattern (Go Left or Right)
```c
if (target < current->data)
    go_left();
else if (target > current->data)
    go_right();
else
    found();
```

## Delete Cases to Remember
1. **Leaf node** (0 children) → Just delete
2. **One child** → Replace with child
3. **Two children** → Replace with inorder successor

## Time Complexity
| Operation | Average | Worst |
|-----------|---------|-------|
| Search | O(log n) | O(n) |
| Insert | O(log n) | O(n) |
| Delete | O(log n) | O(n) |

## Common Mistakes
❌ Not maintaining BST property during insert
✓ Always compare and go left/right

❌ Wrong inorder successor (should be leftmost in right subtree)
✓ `findMin(root->right)`

## Real-World Examples
- Database indexing
- File systems
- Expression parsing
- Auto-complete systems
