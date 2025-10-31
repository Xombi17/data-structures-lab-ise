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

void visitPage(Deque *d, int page_ID) {
    if (isFull(d)) { printf("History full\n"); return; }
    if (isEmpty(d)) d->front = d->rear = 0;
    else d->rear = (d->rear + 1) % MAX;
    d->data[d->rear] = page_ID;
    printf("Visited page %d\n", page_ID);
}

int goBack(Deque *d) {
    if (isEmpty(d)) { printf("No history\n"); return -1; }
    int page = d->data[d->rear];
    if (d->front == d->rear) d->front = d->rear = -1;
    else d->rear = (d->rear - 1 + MAX) % MAX;
    return page;
}

void modifyCurrentPage(Deque *d, int new_ID) {
    if (isEmpty(d)) { printf("No current page\n"); return; }
    d->data[d->rear] = new_ID;
    printf("Current page updated to %d\n", new_ID);
}

void modifyOldestPage(Deque *d, int new_ID) {
    if (isEmpty(d)) { printf("No history\n"); return; }
    d->data[d->front] = new_ID;
    printf("Oldest page updated to %d\n", new_ID);
}

int viewCurrentPage(Deque *d) {
    if (isEmpty(d)) { printf("No current page\n"); return -1; }
    return d->data[d->rear];
}

int viewOldestPage(Deque *d) {
    if (isEmpty(d)) { printf("No history\n"); return -1; }
    return d->data[d->front];
}

void displayHistory(Deque *d) {
    if (isEmpty(d)) { printf("No history\n"); return; }
    printf("History (oldest to recent): ");
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
    int choice, page;
    while (1) {
        printf("\n1.Visit 2.Back 3.ModifyCurrent 4.ModifyOldest 5.ViewCurrent 6.ViewOldest 7.Display 8.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: scanf("%d", &page); visitPage(&d, page); break;
            case 2: page = goBack(&d); if (page != -1) printf("Went back from %d\n", page); break;
            case 3: scanf("%d", &page); modifyCurrentPage(&d, page); break;
            case 4: scanf("%d", &page); modifyOldestPage(&d, page); break;
            case 5: page = viewCurrentPage(&d); if (page != -1) printf("Current: %d\n", page); break;
            case 6: page = viewOldestPage(&d); if (page != -1) printf("Oldest: %d\n", page); break;
            case 7: displayHistory(&d); break;
            case 8: exit(0);
        }
    }
}
