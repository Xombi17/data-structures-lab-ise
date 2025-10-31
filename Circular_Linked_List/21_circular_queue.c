#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *tail = NULL;

void enqueue(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if (!tail) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    printf("Enqueued %d\n", value);
}

int dequeue() {
    if (!tail) { printf("Queue empty\n"); return -1; }
    Node *front = tail->next;
    int data = front->data;
    if (tail->next == tail) tail = NULL;
    else tail->next = front->next;
    free(front);
    return data;
}

int modifyFront(int new_value) {
    if (!tail) { printf("Queue empty\n"); return 0; }
    tail->next->data = new_value;
    printf("Front modified to %d\n", new_value);
    return 1;
}

void displayQueue() {
    if (!tail) { printf("Queue empty\n"); return; }
    printf("Queue: ");
    Node *temp = tail->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.ModifyFront 4.Display 5.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: scanf("%d", &value); enqueue(value); break;
            case 2: value = dequeue(); if (value != -1) printf("Dequeued %d\n", value); break;
            case 3: scanf("%d", &value); modifyFront(value); break;
            case 4: displayQueue(); break;
            case 5: exit(0);
        }
    }
}
