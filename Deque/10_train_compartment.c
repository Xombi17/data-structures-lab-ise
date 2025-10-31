#include <stdio.h>
#define MAX 100

typedef struct {
    int compartments[MAX];
    int front, rear, size;
} TrainDeque;

void init(TrainDeque *train) {
    train->front = 0;
    train->rear = -1;
    train->size = 0;
}

int isEmpty(TrainDeque *train) {
    return train->size == 0;
}

void attachFront(TrainDeque *train, int compartment_ID) {
    if (train->size < MAX) {
        train->front = (train->front - 1 + MAX) % MAX;
        train->compartments[train->front] = compartment_ID;
        train->size++;
        printf("Attached compartment %d to front\n", compartment_ID);
    }
}

void attachRear(TrainDeque *train, int compartment_ID) {
    if (train->size < MAX) {
        train->rear = (train->rear + 1) % MAX;
        train->compartments[train->rear] = compartment_ID;
        train->size++;
        printf("Attached compartment %d to rear\n", compartment_ID);
    }
}

int detachFront(TrainDeque *train) {
    if (isEmpty(train)) {
        printf("No compartments to detach!\n");
        return -1;
    }
    int detached = train->compartments[train->front];
    train->front = (train->front + 1) % MAX;
    train->size--;
    return detached;
}

int detachRear(TrainDeque *train) {
    if (isEmpty(train)) {
        printf("No compartments to detach!\n");
        return -1;
    }
    int detached = train->compartments[train->rear];
    train->rear = (train->rear - 1 + MAX) % MAX;
    train->size--;
    return detached;
}

void modifyFront(TrainDeque *train, int new_ID) {
    if (isEmpty(train)) {
        printf("No compartments to modify!\n");
    } else {
        train->compartments[train->front] = new_ID;
        printf("Front compartment modified to %d\n", new_ID);
    }
}

void modifyRear(TrainDeque *train, int new_ID) {
    if (isEmpty(train)) {
        printf("No compartments to modify!\n");
    } else {
        train->compartments[train->rear] = new_ID;
        printf("Rear compartment modified to %d\n", new_ID);
    }
}

int getFront(TrainDeque *train) {
    if (isEmpty(train)) return -1;
    return train->compartments[train->front];
}

int getRear(TrainDeque *train) {
    if (isEmpty(train)) return -1;
    return train->compartments[train->rear];
}

void displayTrain(TrainDeque *train) {
    if (isEmpty(train)) {
        printf("No compartments\n");
        return;
    }
    printf("Train (front to rear): ");
    for (int i = 0; i < train->size; i++) {
        printf("%d ", train->compartments[(train->front + i) % MAX]);
    }
    printf("\n");
}

int main() {
    TrainDeque train;
    init(&train);
    int choice, id;
    
    while (1) {
        printf("\n1. Attach front\n2. Attach rear\n3. Detach front\n4. Detach rear\n");
        printf("5. Modify front\n6. Modify rear\n7. Get front\n8. Get rear\n9. Display\n10. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter compartment ID: ");
                scanf("%d", &id);
                attachFront(&train, id);
                break;
            case 2:
                printf("Enter compartment ID: ");
                scanf("%d", &id);
                attachRear(&train, id);
                break;
            case 3:
                id = detachFront(&train);
                if (id != -1) printf("Detached front: %d\n", id);
                break;
            case 4:
                id = detachRear(&train);
                if (id != -1) printf("Detached rear: %d\n", id);
                break;
            case 5:
                printf("Enter new ID: ");
                scanf("%d", &id);
                modifyFront(&train, id);
                break;
            case 6:
                printf("Enter new ID: ");
                scanf("%d", &id);
                modifyRear(&train, id);
                break;
            case 7:
                id = getFront(&train);
                if (id != -1) printf("Front: %d\n", id);
                break;
            case 8:
                id = getRear(&train);
                if (id != -1) printf("Rear: %d\n", id);
                break;
            case 9:
                displayTrain(&train);
                break;
            case 10:
                return 0;
        }
    }
}
