#include <stdio.h>
#define MAX 100

typedef struct {
    int actions[MAX];
    int top;
} UndoStack;

void init(UndoStack *stack) {
    stack->top = -1;
}

int isEmpty(UndoStack *stack) {
    return stack->top == -1;
}

void performAction(UndoStack *stack, int action_code) {
    if (stack->top < MAX - 1) {
        stack->actions[++stack->top] = action_code;
        printf("Action %d performed\n", action_code);
    }
}

int undo(UndoStack *stack) {
    if (isEmpty(stack)) {
        printf("No actions to undo!\n");
        return -1;
    }
    return stack->actions[stack->top--];
}

void modifyLastAction(UndoStack *stack, int new_action_code) {
    if (isEmpty(stack)) {
        printf("No actions to modify!\n");
    } else {
        stack->actions[stack->top] = new_action_code;
        printf("Last action modified to %d\n", new_action_code);
    }
}

int getLastAction(UndoStack *stack) {
    if (isEmpty(stack)) {
        printf("No actions!\n");
        return -1;
    }
    return stack->actions[stack->top];
}

void displayHistory(UndoStack *stack) {
    if (isEmpty(stack)) {
        printf("No history\n");
        return;
    }
    printf("Action history (recent to old): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->actions[i]);
    }
    printf("\n");
}

int main() {
    UndoStack stack;
    init(&stack);
    int choice, action;
    
    while (1) {
        printf("\n1. Perform action\n2. Undo\n3. Modify last action\n4. Get last action\n5. Display history\n6. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter action code: ");
                scanf("%d", &action);
                performAction(&stack, action);
                break;
            case 2:
                action = undo(&stack);
                if (action != -1) printf("Undone action: %d\n", action);
                break;
            case 3:
                printf("Enter new action code: ");
                scanf("%d", &action);
                modifyLastAction(&stack, action);
                break;
            case 4:
                action = getLastAction(&stack);
                if (action != -1) printf("Last action: %d\n", action);
                break;
            case 5:
                displayHistory(&stack);
                break;
            case 6:
                return 0;
        }
    }
}
