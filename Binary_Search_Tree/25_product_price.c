#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *root = NULL;

Node* createNode(int price) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = price;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node *node, int price) {
    if (!node) return createNode(price);
    if (price < node->data) node->left = insert(node->left, price);
    else if (price > node->data) node->right = insert(node->right, price);
    return node;
}

Node* minNode(Node *node) {
    while (node->left) node = node->left;
    return node;
}

Node* deleteNode(Node *node, int price) {
    if (!node) return NULL;
    if (price < node->data) node->left = deleteNode(node->left, price);
    else if (price > node->data) node->right = deleteNode(node->right, price);
    else {
        if (!node->left) { Node *temp = node->right; free(node); return temp; }
        if (!node->right) { Node *temp = node->left; free(node); return temp; }
        Node *temp = minNode(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

int search(Node *node, int price) {
    if (!node) return 0;
    if (price == node->data) return 1;
    if (price < node->data) return search(node->left, price);
    return search(node->right, price);
}

void inorder(Node *node) {
    if (node) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

int main() {
    int choice, price, old, newPrice;
    while (1) {
        printf("\n1.Insert 2.Remove 3.Modify 4.Find 5.Display 6.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: scanf("%d", &price); root = insert(root, price); printf("Price %d inserted\n", price); break;
            case 2: scanf("%d", &price); root = deleteNode(root, price); printf("Price %d removed\n", price); break;
            case 3: scanf("%d %d", &old, &newPrice); root = deleteNode(root, old); root = insert(root, newPrice); printf("Modified\n"); break;
            case 4: scanf("%d", &price); printf(search(root, price) ? "Found\n" : "Not found\n"); break;
            case 5: printf("Prices: "); inorder(root); printf("\n"); break;
            case 6: exit(0);
        }
    }
}
