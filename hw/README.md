# Complete Binary Tree Traversal

## 題目敘述
小明是台大資工的大一新生，在上完DSA後突然對TREE感到很有興趣，特別是可以用陣列輕易處理的complete binarary tree。所以他想要自己嘗試建幾顆樹來玩玩，順便練習練習各種traversal的用途。

## Input 格式
- 第一行包含兩個整數 N, D
- 第二行有 N 個整數，代表樹的節點 (以 complete binary tree 的陣列方式給定)
- D 的意義如下：
  - D = 1：pre-order traversal
  - D = 2：in-order traversal
  - D = 3：post-order traversal

## Output 格式
- 按照 D 的要求輸出對應 traversal，數字間以空格隔開

## Constraints
- 1 ≤ N ≤ 2×10⁵
- D ∈ {1, 2, 3}
- -10⁹ ≤ aᵢ ≤ 10⁹

## 範例測資
### Input
```
6 1
8 5 4 9 62 1
```
### Output
```
8 5 9 62 4 1
```

## 實作提示
- 樹的陣列編號規則：假設父節點編號為 i，則左子為 2i+1，右子為 2i+2。
- 遞迴或迴圈皆可進行 traversal，請注意效率與 stack overflow 問題。
