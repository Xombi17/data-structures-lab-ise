#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node *tail = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertProcess(int process_ID) {
    Node* newNode = createNode(process_ID);
    
    if (!tail) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    printf("Inserted process %d\n", process_ID);
}

int deleteProcess(int process_ID) {
    if (!tail) {
        printf("No processes!\n");
        return 0;
    }
    
    Node* current = tail->next;
    Node* prev = tail;
    
    do {
        if (current->data == process_ID) {
            if (current == tail && current->next == current) {
                tail = NULL;
            } else {
                prev->next = current->next;
                if (current == tail) {
                    tail = prev;
                }
            }
            free(current);
            printf("Deleted process %d\n", process_ID);
            return 1;
        }
        prev = current;
        current = current->next;
    } while (current != tail->next);
    
    printf("Process %d not found!\n", process_ID);
    return 0;
}

int modifyProcess(int old_ID, int new_ID) {
    if (!tail) {
        printf("No processes!\n");
        return 0;
    }
    
    Node* current = tail->next;
    do {
        if (current->data == old_ID) {
            current->data = new_ID;
            printf("Modified process %d to %d\n", old_ID, new_ID);
            return 1;
        }
        current = current->next;
    } while (current != tail->next);
    
    printf("Process %d not found!\n", old_ID);
    return 0;
}

void display() {
    if (!tail) {
        printf("No processes\n");
        return;
    }
    
    printf("Processes: ");
    Node* current = tail->next;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != tail->next);
    printf("\n");
}

int main() {
    int choice, id, old_id, new_id;
    
    while (1) {
        printf("\n1. Insert process\n2. Delete process\n3. Modify process\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter process ID: ");
                scanf("%d", &id);
                insertProcess(id);
                break;
            case 2:
                printf("Enter process ID to delete: ");
                scanf("%d", &id);
                deleteProcess(id);
                break;
            case 3:
                printf("Enter old process ID: ");
                scanf("%d", &old_id);
                printf("Enter new process ID: ");
                scanf("%d", &new_id);
                modifyProcess(old_id, new_id);
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
        }
    }
}
