#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node *root = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int mark) {
    if (!root) {
        return createNode(mark);
    }
    
    if (mark < root->data) {
        root->left = insertNode(root->left, mark);
    } else if (mark > root->data) {
        root->right = insertNode(root->right, mark);
    }
    
    return root;
}

void insertMark(int mark) {
    root = insertNode(root, mark);
    printf("Inserted mark %d\n", mark);
}

Node* findMin(Node* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int mark) {
    if (!root) return root;
    
    if (mark < root->data) {
        root->left = deleteNode(root->left, mark);
    } else if (mark > root->data) {
        root->right = deleteNode(root->right, mark);
    } else {
        if (!root->left) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void deleteMark(int mark) {
    root = deleteNode(root, mark);
    printf("Deleted mark %d\n", mark);
}

Node* searchNode(Node* root, int mark) {
    if (!root || root->data == mark) {
        return root;
    }
    
    if (mark < root->data) {
        return searchNode(root->left, mark);
    }
    
    return searchNode(root->right, mark);
}

int findMark(int mark) {
    Node* result = searchNode(root, mark);
    return (result != NULL);
}

void updateMark(int old_mark, int new_mark) {
    if (findMark(old_mark)) {
        deleteMark(old_mark);
        insertMark(new_mark);
        printf("Updated %d to %d\n", old_mark, new_mark);
    } else {
        printf("Mark %d not found!\n", old_mark);
    }
}

void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void displaySortedMarks() {
    if (!root) {
        printf("No marks recorded\n");
        return;
    }
    printf("Sorted marks: ");
    inorderTraversal(root);
    printf("\n");
}

int main() {
    int choice, mark, old_mark, new_mark;
    
    while (1) {
        printf("\n1. Insert mark\n2. Delete mark\n3. Update mark\n4. Find mark\n5. Display sorted\n6. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter mark: ");
                scanf("%d", &mark);
                insertMark(mark);
                break;
            case 2:
                printf("Enter mark to delete: ");
                scanf("%d", &mark);
                deleteMark(mark);
                break;
            case 3:
                printf("Enter old mark: ");
                scanf("%d", &old_mark);
                printf("Enter new mark: ");
                scanf("%d", &new_mark);
                updateMark(old_mark, new_mark);
                break;
            case 4:
                printf("Enter mark to find: ");
                scanf("%d", &mark);
                if (findMark(mark)) {
                    printf("Mark %d found\n", mark);
                } else {
                    printf("Mark %d not found\n", mark);
                }
                break;
            case 5:
                displaySortedMarks();
                break;
            case 6:
                return 0;
        }
    }
}
