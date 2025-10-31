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

void insertAtEnd(int roll_number) {
    Node *newNode = createNode(roll_number);
    
    if (!head) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    printf("Added roll number %d\n", roll_number);
}

void deleteAtPosition(int position) {
    if (!head) {
        printf("List is empty!\n");
        return;
    }
    
    if (position == 0) {
        Node *temp = head;
        head = head->next;
        free(temp);
        printf("Deleted at position 0\n");
        return;
    }
    
    Node *temp = head;
    for (int i = 0; i < position - 1 && temp; i++) {
        temp = temp->next;
    }
    
    if (!temp || !temp->next) {
        printf("Invalid position!\n");
        return;
    }
    
    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Deleted at position %d\n", position);
}

int modifyRoll(int old_roll, int new_roll) {
    Node *temp = head;
    while (temp) {
        if (temp->data == old_roll) {
            temp->data = new_roll;
            printf("Modified %d to %d\n", old_roll, new_roll);
            return 1;
        }
        temp = temp->next;
    }
    printf("Roll number %d not found!\n", old_roll);
    return 0;
}

void display() {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    printf("Roll numbers: ");
    Node *temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, roll, pos, old_roll, new_roll;
    
    while (1) {
        printf("\n1. Insert at end\n2. Delete at position\n3. Modify roll\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertAtEnd(roll);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 3:
                printf("Enter old roll number: ");
                scanf("%d", &old_roll);
                printf("Enter new roll number: ");
                scanf("%d", &new_roll);
                modifyRoll(old_roll, new_roll);
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
        }
    }
}
