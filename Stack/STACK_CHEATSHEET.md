# STACK CHEAT SHEET

## Core Concept
**LIFO - Last In First Out** (like a stack of plates)

## Memory Trick
🥞 **"Pancake Stack"** - You can only add/remove from the TOP

## Essential Operations
```c
typedef struct {
    int data[MAX];
    int top;  // Points to last element (-1 when empty)
} Stack;

void init(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top == -1; }
int isFull(Stack *s) { return s->top == MAX - 1; }

void push(Stack *s, int val) {
    if (!isFull(s)) s->data[++s->top] = val;
}

int pop(Stack *s) {
    if (!isEmpty(s)) return s->data[s->top--];
    return -1;
}

int peek(Stack *s) {
    if (!isEmpty(s)) return s->data[s->top];
    return -1;
}
```

## Key Points
- **top = -1** → Empty stack
- **++top** before push, **top--** after pop
- Always check **isEmpty()** before pop/peek
- Always check **isFull()** before push

## Common Mistakes
❌ `s->data[s->top++] = val;` (wrong order)
✓ `s->data[++s->top] = val;` (correct)

## Real-World Examples
- Undo operations
- Browser back button
- Function calls
- Expression evaluation
