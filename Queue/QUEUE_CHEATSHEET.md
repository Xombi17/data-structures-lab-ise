# QUEUE CHEAT SHEET

## Core Concept
**FIFO - First In First Out** (like a line at ticket counter)

## Memory Trick
🎫 **"Movie Ticket Line"** - First person in line gets served first

## Essential Operations
```c
typedef struct {
    int data[MAX];
    int front, rear, size;
} Queue;

void init(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(Queue *q) { return q->size == 0; }
int isFull(Queue *q) { return q->size == MAX; }

void enqueue(Queue *q, int val) {
    if (!isFull(q)) {
        q->rear = (q->rear + 1) % MAX;  // Circular
        q->data[q->rear] = val;
        q->size++;
    }
}

int dequeue(Queue *q) {
    if (!isEmpty(q)) {
        int val = q->data[q->front];
        q->front = (q->front + 1) % MAX;  // Circular
        q->size--;
        return val;
    }
    return -1;
}
```

## Key Points
- **front** → where we remove (dequeue)
- **rear** → where we add (enqueue)
- Use **% MAX** for circular behavior
- Track **size** to avoid confusion

## Remember
- **EN**queue = **EN**ter at rear
- **DE**queue = **DE**part from front

## Real-World Examples
- Print job queue
- Customer service line
- Playlist
- Task scheduling
