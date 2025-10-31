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

void addPlayer(int player_ID) {
    Node* newNode = createNode(player_ID);
    
    if (!tail) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    printf("Added player %d\n", player_ID);
}

int removePlayer(int player_ID) {
    if (!tail) {
        printf("No players in game!\n");
        return 0;
    }
    
    Node* current = tail->next;
    Node* prev = tail;
    
    do {
        if (current->data == player_ID) {
            if (current == tail && current->next == current) {
                tail = NULL;
            } else {
                prev->next = current->next;
                if (current == tail) {
                    tail = prev;
                }
            }
            free(current);
            printf("Removed player %d\n", player_ID);
            return 1;
        }
        prev = current;
        current = current->next;
    } while (current != tail->next);
    
    printf("Player %d not found!\n", player_ID);
    return 0;
}

int changeID(int old_ID, int new_ID) {
    if (!tail) {
        printf("No players in game!\n");
        return 0;
    }
    
    Node* current = tail->next;
    do {
        if (current->data == old_ID) {
            current->data = new_ID;
            printf("Changed player %d to %d\n", old_ID, new_ID);
            return 1;
        }
        current = current->next;
    } while (current != tail->next);
    
    printf("Player %d not found!\n", old_ID);
    return 0;
}

void display() {
    if (!tail) {
        printf("No players in game\n");
        return;
    }
    
    printf("Players in circle: ");
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
        printf("\n1. Add player\n2. Remove player\n3. Change ID\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter player ID: ");
                scanf("%d", &id);
                addPlayer(id);
                break;
            case 2:
                printf("Enter player ID to remove: ");
                scanf("%d", &id);
                removePlayer(id);
                break;
            case 3:
                printf("Enter old ID: ");
                scanf("%d", &old_id);
                printf("Enter new ID: ");
                scanf("%d", &new_id);
                changeID(old_id, new_id);
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
        }
    }
}
