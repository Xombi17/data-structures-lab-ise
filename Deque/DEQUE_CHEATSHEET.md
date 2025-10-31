# DEQUE (DOUBLE-ENDED QUEUE) CHEAT SHEET

## Core Concept
**Add/Remove from BOTH ends** (hybrid of stack + queue)

## Memory Trick
🚂 **"Train"** - Can attach/detach cars from BOTH front and back

## Essential Operations
```c
typedef struct {
    int data[MAX];
    int front, rear, size;
} Deque;

void init(Deque *d) {
    d->front = 0;
    d->rear = -1;
    d->size = 0;
}

// Add to FRONT (move front backward)
void addFront(Deque *d, int val) {
    if (d->size < MAX) {
        d->front = (d->front - 1 + MAX) % MAX;
        d->data[d->front] = val;
        d->size++;
    }
}

// Add to REAR (move rear forward)
void addRear(Deque *d, int val) {
    if (d->size < MAX) {
        d->rear = (d->rear + 1) % MAX;
        d->data[d->rear] = val;
        d->size++;
    }
}

// Remove from FRONT
int removeFront(Deque *d) {
    if (d->size > 0) {
        int val = d->data[d->front];
        d->front = (d->front + 1) % MAX;
        d->size--;
        return val;
    }
    return -1;
}

// Remove from REAR
int removeRear(Deque *d) {
    if (d->size > 0) {
        int val = d->data[d->rear];
        d->rear = (d->rear - 1 + MAX) % MAX;
        d->size--;
        return val;
    }
    return -1;
}
```

## Key Formulas
- **Move forward**: `(index + 1) % MAX`
- **Move backward**: `(index - 1 + MAX) % MAX`

## Remember: 4 Operations
1. **addFront** - front moves LEFT (backward)
2. **addRear** - rear moves RIGHT (forward)
3. **removeFront** - front moves RIGHT (forward)
4. **removeRear** - rear moves LEFT (backward)

## The "+MAX" Trick
Always add MAX before modulo when going backward:
```c
(index - 1 + MAX) % MAX  // Prevents negative numbers
```

## Real-World Examples
- Browser history (back/forward)
- VIP queue (priority from front, normal from rear)
- Train compartments
