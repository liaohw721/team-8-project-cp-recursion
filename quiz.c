#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
    int val;
    struct TreeNode* left, * right;
} TreeNode;


int cmp(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

int unique(int arr[], int n) {
    if (n == 0) return 0;
    qsort(arr, n, sizeof(int), cmp);   
    int idx = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[idx - 1]) {
            arr[idx++] = arr[i];
        }
    }
    return idx;
}


TreeNode* buildCBST(TreeNode* root, int vals[], int l ,int r) {
    if (l > r) {
        root = NULL;
        return root;
    }
    int mid = (l + r) / 2;
    if ((l + r) % 2 == 1) mid++;
    /*printf("l=%d r=%d mid=%d val[mid]=%d \n", l, r, mid, vals[mid]);*/
    root = (TreeNode*)malloc(sizeof(TreeNode));
	root->left = buildCBST(root->left, vals, l, mid - 1);
    root->val = vals[mid];
	root->right = buildCBST(root->right, vals, mid + 1, r);
	return root;
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
    /*for (int i = 0; i < N; i++) scanf("%d", &arr[i]);*/
    int newN = unique(arr, N);
    TreeNode* root = NULL;
    int idx = 0;
	/*for (int i = 0; i < newN; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");*/
    root=buildCBST(root, arr, 0, newN-1);
    if (ope == 1) {
        inorder(root);
    }
    else if (ope == 2) {
        postorder(root);
    }
    freeTree(root);
    free(arr);
    return 0;
}