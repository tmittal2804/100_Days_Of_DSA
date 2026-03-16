// Given the root of a binary tree, return the preorder traversal of its nodes' values.

void preorder(struct TreeNode* root, int* result, int* returnSize){
    if(root == NULL)
        return;

    result[(*returnSize)++] = root->val;  // Root
    preorder(root->left, result, returnSize);   // Left
    preorder(root->right, result, returnSize);  // Right
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int)); // max nodes = 100
    *returnSize = 0;

    preorder(root, result, returnSize);

    return result;
}


