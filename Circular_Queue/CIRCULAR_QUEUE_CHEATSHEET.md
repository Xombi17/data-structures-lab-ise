# CIRCULAR QUEUE CHEAT SHEET

## Core Concept
**Fixed-size FIFO with wraparound** (like a circular buffer)

## Memory Trick
🎡 **"Ferris Wheel"** - Fixed seats, goes in circles, first on = first off

## Essential Operations
```c
typedef struct {
    int data[MAX];
    int front, rear, size;
} CircularQueue;

void init(CircularQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(CircularQueue *q) { return q->size == 0; }
int isFull(CircularQueue *q) { return q->size == MAX; }

void enqueue(CircularQueue *q, int val) {
    if (!isFull(q)) {
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = val;
        q->size++;
    }
}

int dequeue(CircularQueue *q) {
    if (!isEmpty(q)) {
        int val = q->data[q->front];
        q->front = (q->front + 1) % MAX;
        q->size--;
        return val;
    }
    return -1;
}
```

## Key Difference from Regular Queue
- **MUST check isFull()** - has capacity limit
- **Wraparound** - uses modulo arithmetic
- **Size tracking** - essential for empty/full detection

## The Magic Formula
```
next_position = (current + 1) % MAX
```

## Remember: Two Checks
1. **isEmpty()** before dequeue
2. **isFull()** before enqueue

## Real-World Examples
- Round-robin CPU scheduling
- Buffering (audio/video)
- Limited capacity systems (ferry, game lobby)
