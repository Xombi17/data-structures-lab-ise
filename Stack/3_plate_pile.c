#include <stdio.h>
#define MAX 100

typedef struct {
    int plates[MAX];
    int top;
} PlateStack;

void init(PlateStack *pile) {
    pile->top = -1;
}

int isEmpty(PlateStack *pile) {
    return pile->top == -1;
}

void addPlate(PlateStack *pile, int plate_number) {
    if (pile->top < MAX - 1) {
        pile->plates[++pile->top] = plate_number;
        printf("Added plate %d\n", plate_number);
    }
}

int removePlate(PlateStack *pile) {
    if (isEmpty(pile)) {
        printf("No plates to remove!\n");
        return -1;
    }
    return pile->plates[pile->top--];
}

void swapTopPlate(PlateStack *pile, int new_plate_number) {
    if (isEmpty(pile)) {
        printf("No plates to swap!\n");
    } else {
        pile->plates[pile->top] = new_plate_number;
        printf("Top plate swapped to %d\n", new_plate_number);
    }
}

int getTopPlate(PlateStack *pile) {
    if (isEmpty(pile)) {
        printf("No plates!\n");
        return -1;
    }
    return pile->plates[pile->top];
}

void display(PlateStack *pile) {
    if (isEmpty(pile)) {
        printf("No plates in pile\n");
        return;
    }
    printf("Plates (top to bottom): ");
    for (int i = pile->top; i >= 0; i--) {
        printf("%d ", pile->plates[i]);
    }
    printf("\n");
}

int main() {
    PlateStack pile;
    init(&pile);
    int choice, plate;
    
    while (1) {
        printf("\n1. Add plate\n2. Remove plate\n3. Swap top plate\n4. Get top plate\n5. Display\n6. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter plate number: ");
                scanf("%d", &plate);
                addPlate(&pile, plate);
                break;
            case 2:
                plate = removePlate(&pile);
                if (plate != -1) printf("Removed plate: %d\n", plate);
                break;
            case 3:
                printf("Enter new plate number: ");
                scanf("%d", &plate);
                swapTopPlate(&pile, plate);
                break;
            case 4:
                plate = getTopPlate(&pile);
                if (plate != -1) printf("Top plate: %d\n", plate);
                break;
            case 5:
                display(&pile);
                break;
            case 6:
                return 0;
        }
    }
}
