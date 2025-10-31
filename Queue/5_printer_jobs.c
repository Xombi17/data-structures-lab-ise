#include <stdio.h>
#define MAX 100

typedef struct {
    int jobs[MAX];
    int front, rear, size;
} PrinterQueue;

void init(PrinterQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(PrinterQueue *q) {
    return q->size == 0;
}

void addJob(PrinterQueue *q, int pages_to_print) {
    if (q->size < MAX) {
        q->rear = (q->rear + 1) % MAX;
        q->jobs[q->rear] = pages_to_print;
        q->size++;
        printf("Added job with %d pages\n", pages_to_print);
    }
}

int finishJob(PrinterQueue *q) {
    if (isEmpty(q)) {
        printf("No jobs to print!\n");
        return -1;
    }
    int finished = q->jobs[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return finished;
}

void updateFirstJob(PrinterQueue *q, int new_pages) {
    if (isEmpty(q)) {
        printf("No jobs to update!\n");
    } else {
        q->jobs[q->front] = new_pages;
        printf("First job updated to %d pages\n", new_pages);
    }
}

void display(PrinterQueue *q) {
    if (isEmpty(q)) {
        printf("No pending jobs\n");
        return;
    }
    printf("Pending jobs (oldest to recent): ");
    for (int i = 0; i < q->size; i++) {
        printf("%d ", q->jobs[(q->front + i) % MAX]);
    }
    printf("\n");
}

int main() {
    PrinterQueue q;
    init(&q);
    int choice, pages;
    
    while (1) {
        printf("\n1. Add job\n2. Finish job\n3. Update first job\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter pages to print: ");
                scanf("%d", &pages);
                addJob(&q, pages);
                break;
            case 2:
                pages = finishJob(&q);
                if (pages != -1) printf("Finished job: %d pages\n", pages);
                break;
            case 3:
                printf("Enter new page count: ");
                scanf("%d", &pages);
                updateFirstJob(&q, pages);
                break;
            case 4:
                display(&q);
                break;
            case 5:
                return 0;
        }
    }
}
