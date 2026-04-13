#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create Node
struct Node* createNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Find index in inorder
int findIndex(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Build Tree
struct Node* buildTree(int inorder[], int postorder[],
                       int inStart, int inEnd, int* postIndex) {

    if (inStart > inEnd)
        return NULL;

    // Last element is root
    int val = postorder[*postIndex];
    (*postIndex)--;

    struct Node* root = createNode(val);

    // If only one node
    if (inStart == inEnd)
        return root;

    int index = findIndex(inorder, inStart, inEnd, val);

    // Build right first
    root->right = buildTree(inorder, postorder, index + 1, inEnd, postIndex);
    root->left  = buildTree(inorder, postorder, inStart, index - 1, postIndex);

    return root;
}

// Preorder Traversal (Output)
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Main Function
int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    // Input inorder
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    // Input postorder
    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    // Output preorder
    preorder(root);

    return 0;
}