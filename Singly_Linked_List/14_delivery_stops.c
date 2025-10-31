#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addAtBeginning(int stop_ID) {
    Node *newNode = createNode(stop_ID);
    newNode->next = head;
    head = newNode;
    printf("Stop %d added at beginning\n", stop_ID);
}

void removeLast() {
    if (!head) { printf("No stops\n"); return; }
    if (!head->next) { free(head); head = NULL; printf("Last stop removed\n"); return; }
    Node *temp = head;
    while (temp->next->next) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    printf("Last stop removed\n");
}

int changeStopID(int old_ID, int new_ID) {
    Node *temp = head;
    while (temp) {
        if (temp->data == old_ID) {
            temp->data = new_ID;
            printf("Stop %d changed to %d\n", old_ID, new_ID);
            return 1;
        }
        temp = temp->next;
    }
    printf("Stop %d not found\n", old_ID);
    return 0;
}

void display() {
    if (!head) { printf("No stops\n"); return; }
    printf("Stops: ");
    Node *temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, stop, old, newID;
    while (1) {
        printf("\n1.AddBeginning 2.RemoveLast 3.ChangeStop 4.Display 5.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: scanf("%d", &stop); addAtBeginning(stop); break;
            case 2: removeLast(); break;
            case 3: scanf("%d %d", &old, &newID); changeStopID(old, newID); break;
            case 4: display(); break;
            case 5: exit(0);
        }
    }
}
