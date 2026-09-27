# Find the Matrix

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/find-the-matrix/](https://csacademy.com/contest/archive/task/find-the-matrix/)  

---

Starting from a matrix $A$ of size $N * M$ consisting of integers between $0$ and $K$, another matrix $B$ of size $(N - 1) * (M - 1)$ was built with elements satisfying the following equation:

$B_{i, j} = A_{i, j} + A_{i, j+1} + A_{i + 1, j} + A_{i + 1, j + 1}$ 

Given $B$, find a possible $A$ or print $-1$ if it's not possible.

### Standard input

The first line contains three integers $N$, $M$ and $K$.

The next $N - 1$ lines contain $M - 1$ integers denoting the $B$ matrix.

### Standard output

If there is no solution print $-1$.

Otherwise, print $N$ lines each containing $M$ integers between $0$ and $K$, the $A$ matrix.

### Constraints and notes

$2 \leq N, M \leq 200$ $1 \leq K \leq 10^9$ $0 \leq B_{i, j} \leq 10^9$ 

| Input | Output |
| --- | --- |
| 3 3 2<br>6 7<br>8 6 | 1 1 2<br>2 2 2<br>2 2 0 |
| 2 3 1<br>3 0 | -1 |
