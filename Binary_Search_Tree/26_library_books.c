#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *root = NULL;

Node* createNode(int book_ID) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = book_ID;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node *node, int book_ID) {
    if (!node) return createNode(book_ID);
    if (book_ID < node->data) node->left = insert(node->left, book_ID);
    else if (book_ID > node->data) node->right = insert(node->right, book_ID);
    return node;
}

Node* minNode(Node *node) {
    while (node->left) node = node->left;
    return node;
}

Node* deleteNode(Node *node, int book_ID) {
    if (!node) return NULL;
    if (book_ID < node->data) node->left = deleteNode(node->left, book_ID);
    else if (book_ID > node->data) node->right = deleteNode(node->right, book_ID);
    else {
        if (!node->left) { Node *temp = node->right; free(node); return temp; }
        if (!node->right) { Node *temp = node->left; free(node); return temp; }
        Node *temp = minNode(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

int search(Node *node, int book_ID) {
    if (!node) return 0;
    if (book_ID == node->data) return 1;
    if (book_ID < node->data) return search(node->left, book_ID);
    return search(node->right, book_ID);
}

void inorder(Node *node) {
    if (node) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

int main() {
    int choice, book, old, newID;
    while (1) {
        printf("\n1.AddBook 2.RemoveBook 3.UpdateBook 4.FindBook 5.DisplayAll 6.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: scanf("%d", &book); root = insert(root, book); printf("Book %d added\n", book); break;
            case 2: scanf("%d", &book); root = deleteNode(root, book); printf("Book %d removed\n", book); break;
            case 3: scanf("%d %d", &old, &newID); root = deleteNode(root, old); root = insert(root, newID); printf("Updated\n"); break;
            case 4: scanf("%d", &book); printf(search(root, book) ? "Found\n" : "Not found\n"); break;
            case 5: printf("Books: "); inorder(root); printf("\n"); break;
            case 6: exit(0);
        }
    }
}
