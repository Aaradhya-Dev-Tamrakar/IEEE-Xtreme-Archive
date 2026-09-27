# Permutation Matrix

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/permutation-matrix/](https://csacademy.com/contest/archive/task/permutation-matrix/)  

---

You are given a permutation $\sigma$ of length $M$. Suppose we build a matrix with $N$ rows and $M$ columns:

The $j$-th element on row $1$ is equal to $\sigma(j)$ The $j$-th element on row $2$ is equal to $\sigma(\sigma(j))$ In general, the $j$-th element on row $i$ is equal to $\sigma(\sigma(...\sigma(j)))$, where we apply the permutation $\sigma$ exactly $i$ times.

Find the sum of the elements on each of the $M$ columns.

### Standard input

The first line contains two integers $M$ and $N$.

The second line contains the $M$ values of the permutation $\sigma$.

### Standard output

Print on a single line $M$ values, representing the sum of the elements for each of the $M$ columns of the matrix.

### Constraints and notes

$1 \leq N, M \leq 10^5$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 4 3<br>3 2 4 1 | 8 6 8 8 | 3 2 4 1 4 2 1 3 1 2 3 4 |
| 5 3<br>2 1 4 5 3 | 5 4 12 12 12 | 2 1 4 5 3 1 2 5 3 4 2 1 3 4 5 |
| 6 2<br>2 5 4 1 6 3 | 7 11 5 3 9 7 | 2 5 4 1 6 3 5 6 1 2 3 4 |
| 7 3<br>3 6 7 2 1 4 5 | 15 12 13 12 11 12 9 | 3 6 7 2 1 4 5 7 4 5 6 3 2 1 5 2 1 4 7 6 3 |
