#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtPosition(int product_code, int position) {
    Node *newNode = createNode(product_code);
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        printf("Product %d inserted at position %d\n", product_code, position);
        return;
    }
    Node *temp = head;
    for (int i = 0; i < position - 1 && temp; i++) temp = temp->next;
    if (!temp) { printf("Invalid position\n"); free(newNode); return; }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Product %d inserted at position %d\n", product_code, position);
}

int deleteByValue(int product_code) {
    if (!head) { printf("Inventory empty\n"); return 0; }
    if (head->data == product_code) {
        Node *temp = head;
        head = head->next;
        free(temp);
        printf("Product %d deleted\n", product_code);
        return 1;
    }
    Node *prev = head, *curr = head->next;
    while (curr) {
        if (curr->data == product_code) {
            prev->next = curr->next;
            free(curr);
            printf("Product %d deleted\n", product_code);
            return 1;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Product %d not found\n", product_code);
    return 0;
}

int updateCode(int old_code, int new_code) {
    Node *temp = head;
    while (temp) {
        if (temp->data == old_code) {
            temp->data = new_code;
            printf("Product %d updated to %d\n", old_code, new_code);
            return 1;
        }
        temp = temp->next;
    }
    printf("Product %d not found\n", old_code);
    return 0;
}

void display() {
    if (!head) { printf("Inventory empty\n"); return; }
    printf("Products: ");
    Node *temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, code, pos, old, newCode;
    while (1) {
        printf("\n1.Insert 2.Delete 3.Update 4.Display 5.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: scanf("%d %d", &code, &pos); insertAtPosition(code, pos); break;
            case 2: scanf("%d", &code); deleteByValue(code); break;
            case 3: scanf("%d %d", &old, &newCode); updateCode(old, newCode); break;
            case 4: display(); break;
            case 5: exit(0);
        }
    }
}
