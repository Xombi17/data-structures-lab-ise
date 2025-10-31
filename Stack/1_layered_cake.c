#include <stdio.h>
#define MAX 5

typedef struct {
    int layers[MAX];
    int top;
} CakeStack;

void init(CakeStack *cake) {
    cake->top = -1;
}

int isEmpty(CakeStack *cake) {
    return cake->top == -1;
}

void addLayer(CakeStack *cake, int thickness) {
    if (cake->top < MAX - 1) {
        cake->layers[++cake->top] = thickness;
        printf("Added layer with thickness %d\n", thickness);
    } else {
        printf("Cake is full!\n");
    }
}

int removeLayer(CakeStack *cake) {
    if (isEmpty(cake)) {
        printf("No layers to remove!\n");
        return -1;
    }
    return cake->layers[cake->top--];
}

void changeTopThickness(CakeStack *cake, int new_thickness) {
    if (isEmpty(cake)) {
        printf("No layers to modify!\n");
    } else {
        cake->layers[cake->top] = new_thickness;
        printf("Top layer thickness changed to %d\n", new_thickness);
    }
}

int getTopThickness(CakeStack *cake) {
    if (isEmpty(cake)) {
        printf("No layers!\n");
        return -1;
    }
    return cake->layers[cake->top];
}

void display(CakeStack *cake) {
    if (isEmpty(cake)) {
        printf("No layers in cake\n");
        return;
    }
    printf("Cake layers (top to bottom): ");
    for (int i = cake->top; i >= 0; i--) {
        printf("%d ", cake->layers[i]);
    }
    printf("\n");
}

int main() {
    CakeStack cake;
    init(&cake);
    int choice, thickness;
    
    while (1) {
        printf("\n1. Add layer\n2. Remove layer\n3. Change top thickness\n4. Get top thickness\n5. Display\n6. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter thickness: ");
                scanf("%d", &thickness);
                addLayer(&cake, thickness);
                break;
            case 2:
                thickness = removeLayer(&cake);
                if (thickness != -1) printf("Removed layer: %d\n", thickness);
                break;
            case 3:
                printf("Enter new thickness: ");
                scanf("%d", &thickness);
                changeTopThickness(&cake, thickness);
                break;
            case 4:
                thickness = getTopThickness(&cake);
                if (thickness != -1) printf("Top thickness: %d\n", thickness);
                break;
            case 5:
                display(&cake);
                break;
            case 6:
                return 0;
        }
    }
}
