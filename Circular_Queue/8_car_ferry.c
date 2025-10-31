#include <stdio.h>
#define MAX 10

typedef struct {
    int cars[MAX];
    int front, rear, size;
} CarFerry;

void init(CarFerry *ferry) {
    ferry->front = 0;
    ferry->rear = -1;
    ferry->size = 0;
}

int isEmpty(CarFerry *ferry) {
    return ferry->size == 0;
}

int isFull(CarFerry *ferry) {
    return ferry->size == MAX;
}

void loadCar(CarFerry *ferry, int carID) {
    if (isFull(ferry)) {
        printf("Ferry is full!\n");
        return;
    }
    ferry->rear = (ferry->rear + 1) % MAX;
    ferry->cars[ferry->rear] = carID;
    ferry->size++;
    printf("Car %d loaded onto ferry\n", carID);
}

int unloadCar(CarFerry *ferry) {
    if (isEmpty(ferry)) {
        printf("No cars on ferry!\n");
        return -1;
    }
    int unloaded = ferry->cars[ferry->front];
    ferry->front = (ferry->front + 1) % MAX;
    ferry->size--;
    return unloaded;
}

int viewNextCar(CarFerry *ferry) {
    if (isEmpty(ferry)) {
        printf("No cars on ferry!\n");
        return -1;
    }
    return ferry->cars[ferry->front];
}

void displayFerry(CarFerry *ferry) {
    if (isEmpty(ferry)) {
        printf("Ferry is empty\n");
        return;
    }
    printf("Cars on ferry (front to rear): ");
    for (int i = 0; i < ferry->size; i++) {
        printf("%d ", ferry->cars[(ferry->front + i) % MAX]);
    }
    printf("\n");
}

int main() {
    CarFerry ferry;
    init(&ferry);
    int choice, car;
    
    while (1) {
        printf("\n1. Load car\n2. Unload car\n3. View next car\n4. Display ferry\n5. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter car ID: ");
                scanf("%d", &car);
                loadCar(&ferry, car);
                break;
            case 2:
                car = unloadCar(&ferry);
                if (car != -1) printf("Unloaded car: %d\n", car);
                break;
            case 3:
                car = viewNextCar(&ferry);
                if (car != -1) printf("Next car to unload: %d\n", car);
                break;
            case 4:
                displayFerry(&ferry);
                break;
            case 5:
                return 0;
        }
    }
}
