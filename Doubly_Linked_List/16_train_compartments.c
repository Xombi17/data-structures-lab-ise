#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int compartment_ID;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} TrainList;

void init(TrainList* train) {
    train->head = NULL;
    train->tail = NULL;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->compartment_ID = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addAtEnd(TrainList* train, int compartment_ID) {
    Node* newNode = createNode(compartment_ID);
    
    if (train->head == NULL) {
        train->head = newNode;
        train->tail = newNode;
    } else {
        train->tail->next = newNode;
        newNode->prev = train->tail;
        train->tail = newNode;
    }
    printf("Added compartment %d at end\n", compartment_ID);
}

int removeFromBeginning(TrainList* train) {
    if (train->head == NULL) {
        printf("No compartments to remove!\n");
        return -1;
    }
    
    int removed = train->head->compartment_ID;
    Node* temp = train->head;
    
    if (train->head == train->tail) {
        train->head = NULL;
        train->tail = NULL;
    } else {
        train->head = train->head->next;
        train->head->prev = NULL;
    }
    
    free(temp);
    return removed;
}

int modifyID(TrainList* train, int old_ID, int new_ID) {
    Node* temp = train->head;
    while (temp != NULL) {
        if (temp->compartment_ID == old_ID) {
            temp->compartment_ID = new_ID;
            printf("Modified %d to %d\n", old_ID, new_ID);
            return 1;
        }
        temp = temp->next;
    }
    printf("Compartment %d not found!\n", old_ID);
    return 0;
}

void displayForward(TrainList* train) {
    if (train->head == NULL) {
        printf("No compartments\n");
        return;
    }
    printf("Train (head to tail): ");
    Node* temp = train->head;
    while (temp != NULL) {
        printf("%d ", temp->compartment_ID);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    TrainList train;
    init(&train);
    int choice, id, old_id, new_id;
    
    while (1) {
        printf("\n1. Add at end\n2. Remove from beginning\n3. Modify ID\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter compartment ID: ");
                scanf("%d", &id);
                addAtEnd(&train, id);
                break;
            case 2:
                id = removeFromBeginning(&train);
                if (id != -1) printf("Removed compartment: %d\n", id);
                break;
            case 3:
                printf("Enter old ID: ");
                scanf("%d", &old_id);
                printf("Enter new ID: ");
                scanf("%d", &new_id);
                modifyID(&train, old_id, new_id);
                break;
            case 4:
                displayForward(&train);
                break;
            case 5:
                return 0;
        }
    }
}
