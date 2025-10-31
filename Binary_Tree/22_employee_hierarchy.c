#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int employee_ID;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct {
    TreeNode* root;
} EmployeeTree;

void init(EmployeeTree* tree) {
    tree->root = NULL;
}

TreeNode* createNode(int employee_ID) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->employee_ID = employee_ID;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* findNode(TreeNode* root, int employee_ID) {
    if (root == NULL) return NULL;
    if (root->employee_ID == employee_ID) return root;
    
    TreeNode* left_result = findNode(root->left, employee_ID);
    if (left_result != NULL) return left_result;
    
    return findNode(root->right, employee_ID);
}

int addEmployee(EmployeeTree* tree, int employee_ID, int manager_ID) {
    if (tree->root == NULL) {
        tree->root = createNode(employee_ID);
        printf("Added CEO %d\n", employee_ID);
        return 1;
    }
    
    TreeNode* manager = findNode(tree->root, manager_ID);
    if (manager == NULL) {
        printf("Manager %d not found!\n", manager_ID);
        return 0;
    }
    
    if (manager->left == NULL) {
        manager->left = createNode(employee_ID);
        printf("Added employee %d under manager %d (left)\n", employee_ID, manager_ID);
        return 1;
    } else if (manager->right == NULL) {
        manager->right = createNode(employee_ID);
        printf("Added employee %d under manager %d (right)\n", employee_ID, manager_ID);
        return 1;
    } else {
        printf("Manager %d already has two subordinates!\n", manager_ID);
        return 0;
    }
}

void preorderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->employee_ID);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void displayHierarchy(EmployeeTree* tree) {
    if (tree->root == NULL) {
        printf("No employees\n");
        return;
    }
    printf("Employee hierarchy: ");
    preorderTraversal(tree->root);
    printf("\n");
}

int main() {
    EmployeeTree tree;
    init(&tree);
    int choice, emp_id, mgr_id;
    
    while (1) {
        printf("\n1. Add employee\n2. Display hierarchy\n3. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter employee ID: ");
                scanf("%d", &emp_id);
                if (tree.root == NULL) {
                    addEmployee(&tree, emp_id, 0);
                } else {
                    printf("Enter manager ID: ");
                    scanf("%d", &mgr_id);
                    addEmployee(&tree, emp_id, mgr_id);
                }
                break;
            case 2:
                displayHierarchy(&tree);
                break;
            case 3:
                return 0;
        }
    }
}
