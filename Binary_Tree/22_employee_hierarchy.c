#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node *root = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* findNode(Node* root, int employee_ID) {
    if (!root) return NULL;
    if (root->data == employee_ID) return root;
    
    Node* left_result = findNode(root->left, employee_ID);
    if (left_result) return left_result;
    
    return findNode(root->right, employee_ID);
}

int addEmployee(int employee_ID, int manager_ID) {
    if (!root) {
        root = createNode(employee_ID);
        printf("Added CEO %d\n", employee_ID);
        return 1;
    }
    
    Node* manager = findNode(root, manager_ID);
    if (!manager) {
        printf("Manager %d not found!\n", manager_ID);
        return 0;
    }
    
    if (!manager->left) {
        manager->left = createNode(employee_ID);
        printf("Added employee %d under manager %d (left)\n", employee_ID, manager_ID);
        return 1;
    } else if (!manager->right) {
        manager->right = createNode(employee_ID);
        printf("Added employee %d under manager %d (right)\n", employee_ID, manager_ID);
        return 1;
    } else {
        printf("Manager %d already has two subordinates!\n", manager_ID);
        return 0;
    }
}

int removeEmployee(int employee_ID, Node* parent, Node* current) {
    if (!current) return 0;
    
    if (current->data == employee_ID) {
        if (!parent) {
            root = NULL;
        } else if (parent->left == current) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        printf("Removed employee %d and subordinates\n", employee_ID);
        return 1;
    }
    
    if (removeEmployee(employee_ID, current, current->left)) return 1;
    return removeEmployee(employee_ID, current, current->right);
}

int modifyEmployeeID(int old_ID, int new_ID) {
    Node* emp = findNode(root, old_ID);
    if (!emp) {
        printf("Employee %d not found!\n", old_ID);
        return 0;
    }
    emp->data = new_ID;
    printf("Modified employee %d to %d\n", old_ID, new_ID);
    return 1;
}

void preorderTraversal(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void displayHierarchy() {
    if (!root) {
        printf("No employees\n");
        return;
    }
    printf("Employee hierarchy: ");
    preorderTraversal(root);
    printf("\n");
}

int main() {
    int choice, emp_id, mgr_id, old_id, new_id;
    
    while (1) {
        printf("\n1. Add employee\n2. Remove employee\n3. Modify ID\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter employee ID: ");
                scanf("%d", &emp_id);
                if (!root) {
                    addEmployee(emp_id, 0);
                } else {
                    printf("Enter manager ID: ");
                    scanf("%d", &mgr_id);
                    addEmployee(emp_id, mgr_id);
                }
                break;
            case 2:
                printf("Enter employee ID to remove: ");
                scanf("%d", &emp_id);
                removeEmployee(emp_id, NULL, root);
                break;
            case 3:
                printf("Enter old ID: ");
                scanf("%d", &old_id);
                printf("Enter new ID: ");
                scanf("%d", &new_id);
                modifyEmployeeID(old_id, new_id);
                break;
            case 4:
                displayHierarchy();
                break;
            case 5:
                return 0;
        }
    }
}
