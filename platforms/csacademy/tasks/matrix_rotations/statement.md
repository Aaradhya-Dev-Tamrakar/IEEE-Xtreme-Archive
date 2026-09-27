# Matrix Rotations

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/matrix_rotations/](https://csacademy.com/contest/archive/task/matrix_rotations/)  

---

You are given a square matrix $A$ of size $N$. The cells of the matrix are either $0$ or $1$. Consider the three matrices that are obtained by rotating $A$ by $90^{\circ}$, by $180^{\circ}$, and by $270^{\circ}$, respectively.

We want to build another square matrix $B$ of size $N$. Any cell from $B$ should be equal to $1$ if at least one corresponding cell (same line and column) from $A$ or one of its three rotations is also equal to $1$. Otherwise, it should be $0$. Compute and output matrix $B$.

### Standard input

The first line contains a single integer value $N$.

Each of the following $N$ lines contains $N$ values from the set ${0, 1}$, representing matrix $A$.

### Standard output

The output should consist of $N$ lines of $N$ values, representing matrix $B$.

### Constraints and notes

$1 \leq N \leq 100$

| Input | Output |
| --- | --- |
| 4<br>0 0 0 0<br>0 0 0 0<br>0 0 1 0<br>1 0 0 0 | 1 0 0 1<br>0 1 1 0<br>0 1 1 0<br>1 0 0 1 |
| 5<br>1 0 1 1 0<br>1 1 0 0 0<br>0 0 0 0 0<br>0 0 0 1 0<br>1 0 0 0 1 | 1 0 1 1 1<br>1 1 0 1 0<br>1 0 0 0 1<br>0 1 0 1 1<br>1 1 1 0 1 |
