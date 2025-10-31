#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int roll_number;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} StudentList;

void init(StudentList* list) {
    list->head = NULL;
}

void insertAtEnd(StudentList* list, int roll_number) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->roll_number = roll_number;
    newNode->next = NULL;
    
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Added roll number %d\n", roll_number);
}

void deleteAtPosition(StudentList* list, int position) {
    if (list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    if (position == 0) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        printf("Deleted at position 0\n");
        return;
    }
    
    Node* temp = list->head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position!\n");
        return;
    }
    
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Deleted at position %d\n", position);
}

int modifyRoll(StudentList* list, int old_roll, int new_roll) {
    Node* temp = list->head;
    while (temp != NULL) {
        if (temp->roll_number == old_roll) {
            temp->roll_number = new_roll;
            printf("Modified %d to %d\n", old_roll, new_roll);
            return 1;
        }
        temp = temp->next;
    }
    printf("Roll number %d not found!\n", old_roll);
    return 0;
}

void display(StudentList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Roll numbers: ");
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->roll_number);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    StudentList list;
    init(&list);
    int choice, roll, pos, old_roll, new_roll;
    
    while (1) {
        printf("\n1. Insert at end\n2. Delete at position\n3. Modify roll\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertAtEnd(&list, roll);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(&list, pos);
                break;
            case 3:
                printf("Enter old roll number: ");
                scanf("%d", &old_roll);
                printf("Enter new roll number: ");
                scanf("%d", &new_roll);
                modifyRoll(&list, old_roll, new_roll);
                break;
            case 4:
                display(&list);
                break;
            case 5:
                return 0;
        }
    }
}
