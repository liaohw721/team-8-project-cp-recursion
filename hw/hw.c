#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* buildTree(int arr[], int n, int idx) {
    if (idx >= n) return NULL;
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = arr[idx];
    root->left = buildTree(arr, n, 2 * idx + 1);
    root->right = buildTree(arr, n, 2 * idx + 2);
    return root;
}

void preorder(TreeNode* root) {
    if (!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}


void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}


void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int N, ope;
	scanf("%d %d", &N, &ope);

    int* arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }

    TreeNode* root = buildTree(arr, N, 0);
	switch (ope) {
	case 1:
		preorder(root);
		break;
	case 2:
		inorder(root);
		break;
	case 3:
		postorder(root);
		break;
	}
    freeTree(root);
    free(arr);
    return 0;
}