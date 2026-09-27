# Flipping Matrix

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/flipping-matrix/](https://csacademy.com/contest/archive/task/flipping-matrix/)  

---

You are given a binary matrix $A$ of size $N \times N$. You are allowed to perform the following two operations:

Take two rows and swap them. If we want to swap rows $x$ and $y$, we'll encode this operation as R x y.Take two columns and swap them. If we want to swap columns $x$ and $y$, we'll encode this operation as C x y.

Is it possible to obtain only values of $1$ on the main diagonal of $A$ by performing a sequence of at most $N$ operations? If so, print the required operations.

### Standard input

The first line contains $N$.

The next $N$ lines contain $N$ binary values separated by spaces, representing $A$.

### Standard output

If there is no solution, print $-1$.

Otherwise, print every operation on a separated line.

### Constraints and notes

$2 \leq N \leq 10^3$ $0 \leq A_{i, j} \leq 1$ for every $1 \leq i, j \leq N$

| Input | Output |
| --- | --- |
| 3<br>0 0 1<br>0 1 0<br>1 0 0 | C 1 3 |
| 4<br>1 1 0 0<br>0 1 0 1<br>1 1 0 0<br>0 0 0 1 | -1 |
| 5<br>0 1 0 0 1<br>0 0 1 0 0<br>0 1 0 0 0<br>0 0 1 1 0<br>1 0 0 0 0 | R 1 5<br>C 2 3 |
