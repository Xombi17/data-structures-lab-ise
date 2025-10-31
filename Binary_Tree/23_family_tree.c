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

Node* findMember(Node* root, int member_ID) {
    if (!root) return NULL;
    if (root->data == member_ID) return root;
    
    Node* left_result = findMember(root->left, member_ID);
    if (left_result) return left_result;
    
    return findMember(root->right, member_ID);
}

int addMember(int member_ID, int parent_ID) {
    if (!root) {
        root = createNode(member_ID);
        printf("Added ancestor %d\n", member_ID);
        return 1;
    }
    
    Node* parent = findMember(root, parent_ID);
    if (!parent) {
        printf("Parent %d not found!\n", parent_ID);
        return 0;
    }
    
    if (!parent->left) {
        parent->left = createNode(member_ID);
        printf("Added member %d as child of %d\n", member_ID, parent_ID);
        return 1;
    } else if (!parent->right) {
        parent->right = createNode(member_ID);
        printf("Added member %d as child of %d\n", member_ID, parent_ID);
        return 1;
    } else {
        printf("Parent %d already has two children!\n", parent_ID);
        return 0;
    }
}

int removeMember(int member_ID, Node* parent, Node* current) {
    if (!current) return 0;
    
    if (current->data == member_ID) {
        if (!parent) {
            root = NULL;
        } else if (parent->left == current) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        printf("Removed member %d and descendants\n", member_ID);
        return 1;
    }
    
    if (removeMember(member_ID, current, current->left)) return 1;
    return removeMember(member_ID, current, current->right);
}

int updateMemberID(int old_ID, int new_ID) {
    Node* member = findMember(root, old_ID);
    if (!member) {
        printf("Member %d not found!\n", old_ID);
        return 0;
    }
    member->data = new_ID;
    printf("Updated member %d to %d\n", old_ID, new_ID);
    return 1;
}

void preorderTraversal(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void displayFamily() {
    if (!root) {
        printf("No family members\n");
        return;
    }
    printf("Family tree: ");
    preorderTraversal(root);
    printf("\n");
}

int main() {
    int choice, member_id, parent_id, old_id, new_id;
    
    while (1) {
        printf("\n1. Add member\n2. Remove member\n3. Update ID\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter member ID: ");
                scanf("%d", &member_id);
                if (!root) {
                    addMember(member_id, 0);
                } else {
                    printf("Enter parent ID: ");
                    scanf("%d", &parent_id);
                    addMember(member_id, parent_id);
                }
                break;
            case 2:
                printf("Enter member ID to remove: ");
                scanf("%d", &member_id);
                removeMember(member_id, NULL, root);
                break;
            case 3:
                printf("Enter old ID: ");
                scanf("%d", &old_id);
                printf("Enter new ID: ");
                scanf("%d", &new_id);
                updateMemberID(old_id, new_id);
                break;
            case 4:
                displayFamily();
                break;
            case 5:
                return 0;
        }
    }
}
