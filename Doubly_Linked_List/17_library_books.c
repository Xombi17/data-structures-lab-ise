#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int book_ID;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} LibraryList;

void init(LibraryList* library) {
    library->head = NULL;
    library->tail = NULL;
    library->size = 0;
}

Node* createNode(int book_ID) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->book_ID = book_ID;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtPosition(LibraryList* library, int book_ID, int position) {
    if (position < 0 || position > library->size) {
        printf("Invalid position!\n");
        return;
    }
    
    Node* newNode = createNode(book_ID);
    
    if (position == 0) {
        if (library->head == NULL) {
            library->head = newNode;
            library->tail = newNode;
        } else {
            newNode->next = library->head;
            library->head->prev = newNode;
            library->head = newNode;
        }
    } else if (position == library->size) {
        library->tail->next = newNode;
        newNode->prev = library->tail;
        library->tail = newNode;
    } else {
        Node* current = library->head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }
    
    library->size++;
    printf("Inserted book %d at position %d\n", book_ID, position);
}

int deleteByID(LibraryList* library, int book_ID) {
    Node* temp = library->head;
    
    while (temp != NULL && temp->book_ID != book_ID) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Book %d not found!\n", book_ID);
        return 0;
    }
    
    if (temp == library->head && temp == library->tail) {
        library->head = NULL;
        library->tail = NULL;
    } else if (temp == library->head) {
        library->head = temp->next;
        library->head->prev = NULL;
    } else if (temp == library->tail) {
        library->tail = temp->prev;
        library->tail->next = NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    
    free(temp);
    library->size--;
    printf("Deleted book %d\n", book_ID);
    return 1;
}

void displayForward(LibraryList* library) {
    if (library->head == NULL) {
        printf("No books\n");
        return;
    }
    printf("Books (forward): ");
    Node* temp = library->head;
    while (temp != NULL) {
        printf("%d ", temp->book_ID);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    LibraryList library;
    init(&library);
    int choice, id, pos;
    
    while (1) {
        printf("\n1. Insert at position\n2. Delete by ID\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter book ID: ");
                scanf("%d", &id);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(&library, id, pos);
                break;
            case 2:
                printf("Enter book ID to delete: ");
                scanf("%d", &id);
                deleteByID(&library, id);
                break;
            case 3:
                displayForward(&library);
                break;
            case 4:
                return 0;
        }
    }
}
