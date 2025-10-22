#include <stdio.h>

#define MAXN 200000

int N, D;
long long a[MAXN];

void preorder(int i, int *first) {
  if (i >= N)
    return;
  if (!(*first))
    printf(" ");
  printf("%lld", a[i]);
  *first = 0;
  preorder(2 * i + 1, first);
  preorder(2 * i + 2, first);
}

void inorder(int i, int *first) {
  if (i >= N)
    return;
  inorder(2 * i + 1, first);
  if (!(*first))
    printf(" ");
  printf("%lld", a[i]);
  *first = 0;
  inorder(2 * i + 2, first);
}

void postorder(int i, int *first) {
  if (i >= N)
    return;
  postorder(2 * i + 1, first);
  postorder(2 * i + 2, first);
  if (!(*first))
    printf(" ");
  printf("%lld", a[i]);
  *first = 0;
}

int main() {
  scanf("%d %d", &N, &D);
  for (int i = 0; i < N; i++)
    scanf("%lld", &a[i]);

  int first = 1;
  if (D == 1) {
    preorder(0, &first);
  } else if (D == 2) {
    inorder(0, &first);
  } else {
    postorder(0, &first);
  }

  // 不印換行
  fflush(stdout);
  return 0;
}
