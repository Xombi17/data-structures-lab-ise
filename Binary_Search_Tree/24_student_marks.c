#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int mark;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct {
    TreeNode* root;
} MarksTree;

void init(MarksTree* tree) {
    tree->root = NULL;
}

TreeNode* createNode(int mark) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->mark = mark;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insertNode(TreeNode* root, int mark) {
    if (root == NULL) {
        return createNode(mark);
    }
    
    if (mark < root->mark) {
        root->left = insertNode(root->left, mark);
    } else if (mark > root->mark) {
        root->right = insertNode(root->right, mark);
    }
    
    return root;
}

void insertMark(MarksTree* tree, int mark) {
    tree->root = insertNode(tree->root, mark);
    printf("Inserted mark %d\n", mark);
}

TreeNode* findMin(TreeNode* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

TreeNode* deleteNode(TreeNode* root, int mark) {
    if (root == NULL) return root;
    
    if (mark < root->mark) {
        root->left = deleteNode(root->left, mark);
    } else if (mark > root->mark) {
        root->right = deleteNode(root->right, mark);
    } else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        
        TreeNode* temp = findMin(root->right);
        root->mark = temp->mark;
        root->right = deleteNode(root->right, temp->mark);
    }
    return root;
}

void deleteMark(MarksTree* tree, int mark) {
    tree->root = deleteNode(tree->root, mark);
    printf("Deleted mark %d\n", mark);
}

TreeNode* searchNode(TreeNode* root, int mark) {
    if (root == NULL || root->mark == mark) {
        return root;
    }
    
    if (mark < root->mark) {
        return searchNode(root->left, mark);
    }
    
    return searchNode(root->right, mark);
}

int findMark(MarksTree* tree, int mark) {
    TreeNode* result = searchNode(tree->root, mark);
    return (result != NULL);
}

void updateMark(MarksTree* tree, int old_mark, int new_mark) {
    if (findMark(tree, old_mark)) {
        deleteMark(tree, old_mark);
        insertMark(tree, new_mark);
        printf("Updated %d to %d\n", old_mark, new_mark);
    } else {
        printf("Mark %d not found!\n", old_mark);
    }
}

void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->mark);
        inorderTraversal(root->right);
    }
}

void displaySortedMarks(MarksTree* tree) {
    if (tree->root == NULL) {
        printf("No marks recorded\n");
        return;
    }
    printf("Sorted marks: ");
    inorderTraversal(tree->root);
    printf("\n");
}

int main() {
    MarksTree tree;
    init(&tree);
    int choice, mark, old_mark, new_mark;
    
    while (1) {
        printf("\n1. Insert mark\n2. Delete mark\n3. Update mark\n4. Find mark\n5. Display sorted\n6. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter mark: ");
                scanf("%d", &mark);
                insertMark(&tree, mark);
                break;
            case 2:
                printf("Enter mark to delete: ");
                scanf("%d", &mark);
                deleteMark(&tree, mark);
                break;
            case 3:
                printf("Enter old mark: ");
                scanf("%d", &old_mark);
                printf("Enter new mark: ");
                scanf("%d", &new_mark);
                updateMark(&tree, old_mark, new_mark);
                break;
            case 4:
                printf("Enter mark to find: ");
                scanf("%d", &mark);
                if (findMark(&tree, mark)) {
                    printf("Mark %d found\n", mark);
                } else {
                    printf("Mark %d not found\n", mark);
                }
                break;
            case 5:
                displaySortedMarks(&tree);
                break;
            case 6:
                return 0;
        }
    }
}
