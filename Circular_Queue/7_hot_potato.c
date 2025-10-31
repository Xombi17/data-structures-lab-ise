#include <stdio.h>
#define MAX 10

typedef struct {
    int players[MAX];
    int front, rear, size;
} HotPotatoCircle;

void init(HotPotatoCircle *circle) {
    circle->front = 0;
    circle->rear = -1;
    circle->size = 0;
}

int isEmpty(HotPotatoCircle *circle) {
    return circle->size == 0;
}

int isFull(HotPotatoCircle *circle) {
    return circle->size == MAX;
}

void addPlayer(HotPotatoCircle *circle, int playerID) {
    if (isFull(circle)) {
        printf("Circle is full!\n");
        return;
    }
    circle->rear = (circle->rear + 1) % MAX;
    circle->players[circle->rear] = playerID;
    circle->size++;
    printf("Player %d joined the circle\n", playerID);
}

int removePlayer(HotPotatoCircle *circle) {
    if (isEmpty(circle)) {
        printf("No players in circle!\n");
        return -1;
    }
    int removed = circle->players[circle->front];
    circle->front = (circle->front + 1) % MAX;
    circle->size--;
    return removed;
}

int nextPlayer(HotPotatoCircle *circle) {
    if (isEmpty(circle)) {
        printf("No players!\n");
        return -1;
    }
    return circle->players[circle->front];
}

void displayPlayers(HotPotatoCircle *circle) {
    if (isEmpty(circle)) {
        printf("No players in circle\n");
        return;
    }
    printf("Players (front to rear): ");
    for (int i = 0; i < circle->size; i++) {
        printf("%d ", circle->players[(circle->front + i) % MAX]);
    }
    printf("\n");
}

int main() {
    HotPotatoCircle circle;
    init(&circle);
    int choice, player;
    
    while (1) {
        printf("\n1. Add player\n2. Remove player\n3. Next player\n4. Display players\n5. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter player ID: ");
                scanf("%d", &player);
                addPlayer(&circle, player);
                break;
            case 2:
                player = removePlayer(&circle);
                if (player != -1) printf("Removed player: %d\n", player);
                break;
            case 3:
                player = nextPlayer(&circle);
                if (player != -1) printf("Next player: %d\n", player);
                break;
            case 4:
                displayPlayers(&circle);
                break;
            case 5:
                return 0;
        }
    }
}
