#include <stdio.h>
#include <stdlib.h>

#define ll long long


typedef struct TreeNode {
    int index;
    ll val;
    struct TreeNode* left, * right;
} TreeNode;


int cmp(const void* a, const void* b) {
    int ia = ((TreeNode*)a)->index;
    int ib = ((TreeNode*)b)->index;
    if (ia < ib) return -1;
    if (ia > ib) return 1;
    return 0;
}

int unique(TreeNode* arr, int n) {
    if (n == 0) return 0;
    qsort(arr, n, sizeof(TreeNode), cmp);
    int idx = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i].index != arr[idx - 1].index) {
            arr[idx] = arr[i];
			idx++;
        }
        else {
			arr[idx - 1].val += arr[i].val;
        }
    }
    return idx;
}


TreeNode* buildCBST(TreeNode arr[], int l, int r) {
    if (l > r) return NULL;
    int mid = (l + r) / 2;
    if ((l + r) % 2 == 1) mid++; 
    arr[mid].left = buildCBST(arr, l, mid - 1);
    arr[mid].right = buildCBST(arr, mid + 1, r);
    return &arr[mid];
}

ll preorder(TreeNode* root) {
	if (!root) return 0;
	ll sum1 = 0, sum2 = 0;
	sum1 = preorder(root->left);
	sum2 = preorder(root->right);
	root->val += sum1 + sum2;
	return root->val;
}


TreeNode* findByIndex(TreeNode* root, int target_index) {
    if (root == NULL) return NULL;
    if (root->index == target_index) return root;
    if (target_index < root->index)
        return findByIndex(root->left, target_index);
    else
        return findByIndex(root->right, target_index);
}

int main() {
    int N, D;
    scanf("%d %d", &N, &D);
    TreeNode* arr = (TreeNode*)malloc(N * sizeof(TreeNode));
    for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i].index);
        scanf("%lld", &arr[i].val);
    }


    int newN = unique(arr, N);
	TreeNode* root;
    root=buildCBST(arr, 0, newN-1);
	preorder(root);
    
    for (int i = 0; i < D; i++) {
        int event;
		TreeNode* node;
		scanf("%d", &event);
		node = findByIndex(root, event);
		if (node) printf("%lld\n", node->val);
		else printf("Not found\n");
    }

    
    return 0;
}