#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct TreeNode{
    int index;
    ll val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

int cmp(const void *a, const void *b){
    TreeNode *x = (TreeNode *)a;
    TreeNode *y = (TreeNode *)b;
    if(x->index < y->index) return -1;
    else if(x->index > y->index) return 1;
    else return 0;
}

int toUnique(TreeNode *arr, int arr_size){
    if(arr_size == 0) return 0;
    qsort(arr, arr_size, sizeof(TreeNode), cmp);
    int new_size = 1;
    for(int i = 1; i < arr_size; i++){
        if(arr[i].index != arr[i - 1].index){
            arr[new_size++] = arr[i];
        }
        else{
            arr[new_size - 1].val += arr[i].val;
        }
    }
    return new_size;
}

TreeNode *buildCBST(TreeNode *arr, int l, int r){
    if(l > r) return NULL;
    int m = (l + r) / 2;
    if((l + r) % 2 == 1) m++;
    arr[m].left = buildCBST(arr, l, m - 1);
    arr[m].right = buildCBST(arr, m + 1, r);
    return &arr[m];
}

ll addValByPostorder(TreeNode *root){
    if(!root) return 0;
    ll left = addValByPostorder(root->left);
    ll right = addValByPostorder(root->right);
    root->val += left + right;
    return root->val;
}

TreeNode *queryTreeByIndex(TreeNode *root, int index){
    if(!root) return NULL;
    
    if(root->index == index) return root;
    else if(index < root->index) return queryTreeByIndex(root->left, index);
    else return queryTreeByIndex(root->right, index);
}

int main(){
    int n, d; scanf("%d %d", &n, &d);
    TreeNode *arr = (TreeNode*)malloc(n * sizeof(TreeNode));
    for(int i = 0; i < n; i++){
        scanf("%d %lld", &arr[i].index, &arr[i].val);
        arr[i].left = NULL;
        arr[i].right = NULL;
    }
    
    int newN = toUnique(arr, n);
    TreeNode *root = buildCBST(arr, 0, newN - 1);
    addValByPostorder(root);
    for(int i = 0; i < d; i++){
        int type, index; scanf("%d %d", &type, &index);
        TreeNode *rtv = queryTreeByIndex(root, index);
        
        if(type == 1){
            if(rtv) printf("%lld\n", rtv->val);
            else printf("Not Found\n");
        }
        else if(type == 2){
            if(rtv){
                int leftVal = (rtv->left)? rtv->left->val : 0; // 設為 ll(long long) 的時候testcase 15~25會WA, 因此int型別可能有發生overflow的情況
                int rightVal = (rtv->right)? rtv->right->val : 0; // 設為 ll(long long) 的時候testcase 15~25會WA, 因此int型別可能有發生overflow的情況
                printf("%lld\n", rtv->val - leftVal - rightVal);
            }
            else printf("Not Found\n");
        }
    }
    free(arr);
    return 0;
}