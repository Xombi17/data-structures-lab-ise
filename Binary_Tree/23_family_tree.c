#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int member_ID;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct {
    TreeNode* root;
} FamilyTree;

void init(FamilyTree* tree) {
    tree->root = NULL;
}

TreeNode* createNode(int member_ID) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->member_ID = member_ID;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* findMember(TreeNode* root, int member_ID) {
    if (root == NULL) return NULL;
    if (root->member_ID == member_ID) return root;
    
    TreeNode* left_result = findMember(root->left, member_ID);
    if (left_result != NULL) return left_result;
    
    return findMember(root->right, member_ID);
}

int addMember(FamilyTree* tree, int member_ID, int parent_ID) {
    if (tree->root == NULL) {
        tree->root = createNode(member_ID);
        printf("Added ancestor %d\n", member_ID);
        return 1;
    }
    
    TreeNode* parent = findMember(tree->root, parent_ID);
    if (parent == NULL) {
        printf("Parent %d not found!\n", parent_ID);
        return 0;
    }
    
    if (parent->left == NULL) {
        parent->left = createNode(member_ID);
        printf("Added member %d as child of %d\n", member_ID, parent_ID);
        return 1;
    } else if (parent->right == NULL) {
        parent->right = createNode(member_ID);
        printf("Added member %d as child of %d\n", member_ID, parent_ID);
        return 1;
    } else {
        printf("Parent %d already has two children!\n", parent_ID);
        return 0;
    }
}

void preorderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->member_ID);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void displayFamily(FamilyTree* tree) {
    if (tree->root == NULL) {
        printf("No family members\n");
        return;
    }
    printf("Family tree: ");
    preorderTraversal(tree->root);
    printf("\n");
}

int main() {
    FamilyTree tree;
    init(&tree);
    int choice, member_id, parent_id;
    
    while (1) {
        printf("\n1. Add member\n2. Display family\n3. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter member ID: ");
                scanf("%d", &member_id);
                if (tree.root == NULL) {
                    addMember(&tree, member_id, 0);
                } else {
                    printf("Enter parent ID: ");
                    scanf("%d", &parent_id);
                    addMember(&tree, member_id, parent_id);
                }
                break;
            case 2:
                displayFamily(&tree);
                break;
            case 3:
                return 0;
        }
    }
}
