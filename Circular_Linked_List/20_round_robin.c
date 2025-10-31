#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int process_ID;
    struct Node* next;
} Node;

typedef struct {
    Node* tail;
} ProcessScheduler;

void init(ProcessScheduler* scheduler) {
    scheduler->tail = NULL;
}

Node* createNode(int process_ID) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->process_ID = process_ID;
    newNode->next = NULL;
    return newNode;
}

void insertProcess(ProcessScheduler* scheduler, int process_ID) {
    Node* newNode = createNode(process_ID);
    
    if (scheduler->tail == NULL) {
        newNode->next = newNode;
        scheduler->tail = newNode;
    } else {
        newNode->next = scheduler->tail->next;
        scheduler->tail->next = newNode;
        scheduler->tail = newNode;
    }
    printf("Inserted process %d\n", process_ID);
}

int deleteProcess(ProcessScheduler* scheduler, int process_ID) {
    if (scheduler->tail == NULL) {
        printf("No processes!\n");
        return 0;
    }
    
    Node* current = scheduler->tail->next;
    Node* prev = scheduler->tail;
    
    do {
        if (current->process_ID == process_ID) {
            if (current == scheduler->tail && current->next == current) {
                scheduler->tail = NULL;
            } else {
                prev->next = current->next;
                if (current == scheduler->tail) {
                    scheduler->tail = prev;
                }
            }
            free(current);
            printf("Deleted process %d\n", process_ID);
            return 1;
        }
        prev = current;
        current = current->next;
    } while (current != scheduler->tail->next);
    
    printf("Process %d not found!\n", process_ID);
    return 0;
}

void display(ProcessScheduler* scheduler) {
    if (scheduler->tail == NULL) {
        printf("No processes\n");
        return;
    }
    
    printf("Processes: ");
    Node* current = scheduler->tail->next;
    do {
        printf("%d ", current->process_ID);
        current = current->next;
    } while (current != scheduler->tail->next);
    printf("\n");
}

int main() {
    ProcessScheduler scheduler;
    init(&scheduler);
    int choice, id;
    
    while (1) {
        printf("\n1. Insert process\n2. Delete process\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter process ID: ");
                scanf("%d", &id);
                insertProcess(&scheduler, id);
                break;
            case 2:
                printf("Enter process ID to delete: ");
                scanf("%d", &id);
                deleteProcess(&scheduler, id);
                break;
            case 3:
                display(&scheduler);
                break;
            case 4:
                return 0;
        }
    }
}
