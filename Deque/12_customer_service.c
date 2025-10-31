#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int front, rear;
} Deque;

void init(Deque *d) { d->front = d->rear = -1; }

int isEmpty(Deque *d) { return d->front == -1; }

int isFull(Deque *d) { return (d->rear + 1) % MAX == d->front; }

void addVIP(Deque *d, int token) {
    if (isFull(d)) { printf("Line full\n"); return; }
    if (isEmpty(d)) d->front = d->rear = 0;
    else d->front = (d->front - 1 + MAX) % MAX;
    d->data[d->front] = token;
    printf("VIP %d added\n", token);
}

void addNormal(Deque *d, int token) {
    if (isFull(d)) { printf("Line full\n"); return; }
    if (isEmpty(d)) d->front = d->rear = 0;
    else d->rear = (d->rear + 1) % MAX;
    d->data[d->rear] = token;
    printf("Normal customer %d added\n", token);
}

int serveVIP(Deque *d) {
    if (isEmpty(d)) { printf("No customers\n"); return -1; }
    int token = d->data[d->front];
    if (d->front == d->rear) d->front = d->rear = -1;
    else d->front = (d->front + 1) % MAX;
    return token;
}

int serveNormal(Deque *d) {
    if (isEmpty(d)) { printf("No customers\n"); return -1; }
    int token = d->data[d->rear];
    if (d->front == d->rear) d->front = d->rear = -1;
    else d->rear = (d->rear - 1 + MAX) % MAX;
    return token;
}

void modifyVIPToken(Deque *d, int new_token) {
    if (isEmpty(d)) { printf("No customers\n"); return; }
    d->data[d->front] = new_token;
    printf("VIP token updated to %d\n", new_token);
}

void modifyNormalToken(Deque *d, int new_token) {
    if (isEmpty(d)) { printf("No customers\n"); return; }
    d->data[d->rear] = new_token;
    printf("Normal token updated to %d\n", new_token);
}

int viewNextVIP(Deque *d) {
    if (isEmpty(d)) { printf("No customers\n"); return -1; }
    return d->data[d->front];
}

int viewNextNormal(Deque *d) {
    if (isEmpty(d)) { printf("No customers\n"); return -1; }
    return d->data[d->rear];
}

void displayLine(Deque *d) {
    if (isEmpty(d)) { printf("No customers\n"); return; }
    printf("Line (front to rear): ");
    int i = d->front;
    while (1) {
        printf("%d ", d->data[i]);
        if (i == d->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque d;
    init(&d);
    int choice, token;
    while (1) {
        printf("\n1.AddVIP 2.AddNormal 3.ServeVIP 4.ServeNormal 5.ModifyVIP 6.ModifyNormal 7.ViewVIP 8.ViewNormal 9.Display 10.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: scanf("%d", &token); addVIP(&d, token); break;
            case 2: scanf("%d", &token); addNormal(&d, token); break;
            case 3: token = serveVIP(&d); if (token != -1) printf("Served VIP %d\n", token); break;
            case 4: token = serveNormal(&d); if (token != -1) printf("Served Normal %d\n", token); break;
            case 5: scanf("%d", &token); modifyVIPToken(&d, token); break;
            case 6: scanf("%d", &token); modifyNormalToken(&d, token); break;
            case 7: token = viewNextVIP(&d); if (token != -1) printf("Next VIP: %d\n", token); break;
            case 8: token = viewNextNormal(&d); if (token != -1) printf("Next Normal: %d\n", token); break;
            case 9: displayLine(&d); break;
            case 10: exit(0);
        }
    }
}
