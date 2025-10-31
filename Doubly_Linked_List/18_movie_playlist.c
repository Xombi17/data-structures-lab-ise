#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node *head = NULL, *tail = NULL;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addAtStart(int movie_ID) {
    Node *newNode = createNode(movie_ID);
    if (!head) {
        newNode->next = NULL;
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Movie %d added at start\n", movie_ID);
}

void addAtEnd(int movie_ID) {
    Node *newNode = createNode(movie_ID);
    if (!tail) {
        newNode->prev = NULL;
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    printf("Movie %d added at end\n", movie_ID);
}

void removeFromStart() {
    if (!head) { printf("Playlist empty\n"); return; }
    Node *temp = head;
    if (head == tail) head = tail = NULL;
    else {
        head = head->next;
        head->prev = NULL;
    }
    printf("Movie %d removed from start\n", temp->data);
    free(temp);
}

void removeFromEnd() {
    if (!tail) { printf("Playlist empty\n"); return; }
    Node *temp = tail;
    if (head == tail) head = tail = NULL;
    else {
        tail = tail->prev;
        tail->next = NULL;
    }
    printf("Movie %d removed from end\n", temp->data);
    free(temp);
}

int modifyID(int old_ID, int new_ID) {
    Node *temp = head;
    while (temp) {
        if (temp->data == old_ID) {
            temp->data = new_ID;
            printf("Movie %d updated to %d\n", old_ID, new_ID);
            return 1;
        }
        temp = temp->next;
    }
    printf("Movie %d not found\n", old_ID);
    return 0;
}

void displayForward() {
    if (!head) { printf("Playlist empty\n"); return; }
    printf("Movies: ");
    Node *temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, movie, old, newID;
    while (1) {
        printf("\n1.AddStart 2.AddEnd 3.RemoveStart 4.RemoveEnd 5.Modify 6.Display 7.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: scanf("%d", &movie); addAtStart(movie); break;
            case 2: scanf("%d", &movie); addAtEnd(movie); break;
            case 3: removeFromStart(); break;
            case 4: removeFromEnd(); break;
            case 5: scanf("%d %d", &old, &newID); modifyID(old, newID); break;
            case 6: displayForward(); break;
            case 7: exit(0);
        }
    }
}
