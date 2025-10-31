#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int player_ID;
    struct Node* next;
} Node;

typedef struct {
    Node* tail;
} GameCircle;

void init(GameCircle* game) {
    game->tail = NULL;
}

Node* createNode(int player_ID) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->player_ID = player_ID;
    newNode->next = NULL;
    return newNode;
}

void addPlayer(GameCircle* game, int player_ID) {
    Node* newNode = createNode(player_ID);
    
    if (game->tail == NULL) {
        newNode->next = newNode;
        game->tail = newNode;
    } else {
        newNode->next = game->tail->next;
        game->tail->next = newNode;
        game->tail = newNode;
    }
    printf("Added player %d\n", player_ID);
}

int removePlayer(GameCircle* game, int player_ID) {
    if (game->tail == NULL) {
        printf("No players in game!\n");
        return 0;
    }
    
    Node* current = game->tail->next;
    Node* prev = game->tail;
    
    do {
        if (current->player_ID == player_ID) {
            if (current == game->tail && current->next == current) {
                game->tail = NULL;
            } else {
                prev->next = current->next;
                if (current == game->tail) {
                    game->tail = prev;
                }
            }
            free(current);
            printf("Removed player %d\n", player_ID);
            return 1;
        }
        prev = current;
        current = current->next;
    } while (current != game->tail->next);
    
    printf("Player %d not found!\n", player_ID);
    return 0;
}

int changeID(GameCircle* game, int old_ID, int new_ID) {
    if (game->tail == NULL) {
        printf("No players in game!\n");
        return 0;
    }
    
    Node* current = game->tail->next;
    do {
        if (current->player_ID == old_ID) {
            current->player_ID = new_ID;
            printf("Changed player %d to %d\n", old_ID, new_ID);
            return 1;
        }
        current = current->next;
    } while (current != game->tail->next);
    
    printf("Player %d not found!\n", old_ID);
    return 0;
}

void display(GameCircle* game) {
    if (game->tail == NULL) {
        printf("No players in game\n");
        return;
    }
    
    printf("Players in circle: ");
    Node* current = game->tail->next;
    do {
        printf("%d ", current->player_ID);
        current = current->next;
    } while (current != game->tail->next);
    printf("\n");
}

int main() {
    GameCircle game;
    init(&game);
    int choice, id, old_id, new_id;
    
    while (1) {
        printf("\n1. Add player\n2. Remove player\n3. Change ID\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter player ID: ");
                scanf("%d", &id);
                addPlayer(&game, id);
                break;
            case 2:
                printf("Enter player ID to remove: ");
                scanf("%d", &id);
                removePlayer(&game, id);
                break;
            case 3:
                printf("Enter old ID: ");
                scanf("%d", &old_id);
                printf("Enter new ID: ");
                scanf("%d", &new_id);
                changeID(&game, old_id, new_id);
                break;
            case 4:
                display(&game);
                break;
            case 5:
                return 0;
        }
    }
}
