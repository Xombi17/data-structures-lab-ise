#include <stdio.h>
#define MAX 100

typedef struct {
    int queue[MAX];
    int front, rear, size;
} RideQueue;

void init(RideQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(RideQueue *q) {
    return q->size == 0;
}

void joinLine(RideQueue *q, int person_token) {
    if (q->size < MAX) {
        q->rear = (q->rear + 1) % MAX;
        q->queue[q->rear] = person_token;
        q->size++;
        printf("Person %d joined the line\n", person_token);
    }
}

int serveAndRequeue(RideQueue *q) {
    if (isEmpty(q)) {
        printf("No one in line!\n");
        return -1;
    }
    int served = q->queue[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    
    // Immediately requeue
    q->rear = (q->rear + 1) % MAX;
    q->queue[q->rear] = served;
    q->size++;
    
    printf("Served person %d, they rejoined the line\n", served);
    return served;
}

int getFirst(RideQueue *q) {
    if (isEmpty(q)) {
        printf("No one in line!\n");
        return -1;
    }
    return q->queue[q->front];
}

void display(RideQueue *q) {
    if (isEmpty(q)) {
        printf("No one in line\n");
        return;
    }
    printf("Queue (oldest to latest): ");
    for (int i = 0; i < q->size; i++) {
        printf("%d ", q->queue[(q->front + i) % MAX]);
    }
    printf("\n");
}

int main() {
    RideQueue q;
    init(&q);
    int choice, token;
    
    while (1) {
        printf("\n1. Join line\n2. Serve and requeue\n3. Get first person\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter person token: ");
                scanf("%d", &token);
                joinLine(&q, token);
                break;
            case 2:
                serveAndRequeue(&q);
                break;
            case 3:
                token = getFirst(&q);
                if (token != -1) printf("First person: %d\n", token);
                break;
            case 4:
                display(&q);
                break;
            case 5:
                return 0;
        }
    }
}
