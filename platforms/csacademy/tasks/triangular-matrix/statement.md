# Triangular Matrix

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/triangular-matrix/](https://csacademy.com/contest/archive/task/triangular-matrix/)  

---

You are given a triangular matrix consisting of $N$ lines: every row $i (1 \leq i \leq N)$ has exactly $i$ cells positioned on the columns from $1$ to $i$. Each cell contains one lowercase English letter.

You start at position $(1, 1)$ and at each step you can jump from cell $(i, j)$ to cell $(i+1,j)$ or cell $(i+1,j+1)$. Find the smallest lexicographical path from row $1$ to row $N$.

### Standard input

The first line contains the integer $N$.

The next $N$ lines describe the triangular matrix. The $i+1$ line contains $i$ letters corresponding to the cells of the $i$-th row of the triangular matrix.

### Standard output

Print the smallest lexicographical path on the first line.

### Constraints and notes

$1 \leq N \leq 3000$ 

| Input | Output |
| --- | --- |
| 3<br>a<br>ab<br>ccc | aac |
| 5<br>b<br>ab<br>cac<br>ffff<br>deded | baafd |
