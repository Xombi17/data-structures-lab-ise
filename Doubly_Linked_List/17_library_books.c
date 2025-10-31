#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node *head = NULL;
Node *tail = NULL;
int size = 0;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtPosition(int book_ID, int position) {
    if (position < 0 || position > size) {
        printf("Invalid position!\n");
        return;
    }
    
    Node* newNode = createNode(book_ID);
    
    if (position == 0) {
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    } else if (position == size) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    } else {
        Node* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }
    
    size++;
    printf("Inserted book %d at position %d\n", book_ID, position);
}

int deleteByID(int book_ID) {
    Node* temp = head;
    
    while (temp && temp->data != book_ID) {
        temp = temp->next;
    }
    
    if (!temp) {
        printf("Book %d not found!\n", book_ID);
        return 0;
    }
    
    if (temp == head && temp == tail) {
        head = tail = NULL;
    } else if (temp == head) {
        head = temp->next;
        head->prev = NULL;
    } else if (temp == tail) {
        tail = temp->prev;
        tail->next = NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    
    free(temp);
    size--;
    printf("Deleted book %d\n", book_ID);
    return 1;
}

int updateID(int old_ID, int new_ID) {
    Node* temp = head;
    while (temp) {
        if (temp->data == old_ID) {
            temp->data = new_ID;
            printf("Updated book %d to %d\n", old_ID, new_ID);
            return 1;
        }
        temp = temp->next;
    }
    printf("Book %d not found!\n", old_ID);
    return 0;
}

void displayForward() {
    if (!head) {
        printf("No books\n");
        return;
    }
    printf("Books (forward): ");
    Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, id, pos, old_id, new_id;
    
    while (1) {
        printf("\n1. Insert at position\n2. Delete by ID\n3. Update ID\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter book ID: ");
                scanf("%d", &id);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(id, pos);
                break;
            case 2:
                printf("Enter book ID to delete: ");
                scanf("%d", &id);
                deleteByID(id);
                break;
            case 3:
                printf("Enter old book ID: ");
                scanf("%d", &old_id);
                printf("Enter new book ID: ");
                scanf("%d", &new_id);
                updateID(old_id, new_id);
                break;
            case 4:
                displayForward();
                break;
            case 5:
                return 0;
        }
    }
}
