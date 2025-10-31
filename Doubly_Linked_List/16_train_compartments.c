#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node *head = NULL;
Node *tail = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addAtEnd(int compartment_ID) {
    Node* newNode = createNode(compartment_ID);
    
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    printf("Added compartment %d at end\n", compartment_ID);
}

int removeFromBeginning() {
    if (!head) {
        printf("No compartments to remove!\n");
        return -1;
    }
    
    int removed = head->data;
    Node* temp = head;
    
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    
    free(temp);
    return removed;
}

int modifyID(int old_ID, int new_ID) {
    Node* temp = head;
    while (temp) {
        if (temp->data == old_ID) {
            temp->data = new_ID;
            printf("Modified %d to %d\n", old_ID, new_ID);
            return 1;
        }
        temp = temp->next;
    }
    printf("Compartment %d not found!\n", old_ID);
    return 0;
}

void displayForward() {
    if (!head) {
        printf("No compartments\n");
        return;
    }
    printf("Train (head to tail): ");
    Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, id, old_id, new_id;
    
    while (1) {
        printf("\n1. Add at end\n2. Remove from beginning\n3. Modify ID\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter compartment ID: ");
                scanf("%d", &id);
                addAtEnd(id);
                break;
            case 2:
                id = removeFromBeginning();
                if (id != -1) printf("Removed compartment: %d\n", id);
                break;
            case 3:
                printf("Enter old ID: ");
                scanf("%d", &old_id);
                printf("Enter new ID: ");
                scanf("%d", &new_id);
                modifyID(old_id, new_id);
                break;
            case 4:
                displayForward();
                break;
            case 5:
                return 0;
        }
    }
}
