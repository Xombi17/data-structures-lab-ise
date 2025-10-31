#include <stdio.h>
#define MAX 10

typedef struct {
    int tasks[MAX];
    int front, rear, size;
} TaskScheduler;

void init(TaskScheduler *scheduler) {
    scheduler->front = 0;
    scheduler->rear = -1;
    scheduler->size = 0;
}

int isEmpty(TaskScheduler *scheduler) {
    return scheduler->size == 0;
}

int isFull(TaskScheduler *scheduler) {
    return scheduler->size == MAX;
}

void submitTask(TaskScheduler *scheduler, int taskID) {
    if (isFull(scheduler)) {
        printf("Task queue is full!\n");
        return;
    }
    scheduler->rear = (scheduler->rear + 1) % MAX;
    scheduler->tasks[scheduler->rear] = taskID;
    scheduler->size++;
    printf("Task %d submitted\n", taskID);
}

int executeTask(TaskScheduler *scheduler) {
    if (isEmpty(scheduler)) {
        printf("No tasks to execute!\n");
        return -1;
    }
    int executed = scheduler->tasks[scheduler->front];
    scheduler->front = (scheduler->front + 1) % MAX;
    scheduler->size--;
    return executed;
}

int viewNextTask(TaskScheduler *scheduler) {
    if (isEmpty(scheduler)) {
        printf("No tasks in queue!\n");
        return -1;
    }
    return scheduler->tasks[scheduler->front];
}

void displayTasks(TaskScheduler *scheduler) {
    if (isEmpty(scheduler)) {
        printf("No pending tasks\n");
        return;
    }
    printf("Pending tasks (front to rear): ");
    for (int i = 0; i < scheduler->size; i++) {
        printf("%d ", scheduler->tasks[(scheduler->front + i) % MAX]);
    }
    printf("\n");
}

int main() {
    TaskScheduler scheduler;
    init(&scheduler);
    int choice, task;
    
    while (1) {
        printf("\n1. Submit task\n2. Execute task\n3. View next task\n4. Display tasks\n5. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter task ID: ");
                scanf("%d", &task);
                submitTask(&scheduler, task);
                break;
            case 2:
                task = executeTask(&scheduler);
                if (task != -1) printf("Executed task: %d\n", task);
                break;
            case 3:
                task = viewNextTask(&scheduler);
                if (task != -1) printf("Next task: %d\n", task);
                break;
            case 4:
                displayTasks(&scheduler);
                break;
            case 5:
                return 0;
        }
    }
}
