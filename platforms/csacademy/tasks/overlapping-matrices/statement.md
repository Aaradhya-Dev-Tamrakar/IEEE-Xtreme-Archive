# Overlapping Matrices

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/overlapping-matrices/](https://csacademy.com/contest/archive/task/overlapping-matrices/)  

---

You have a matrix $A$ of dimensions $H \times W$ and two integers $X$ and $Y$. The matrix $B$ of size $(H + X) \times (W + Y)$ is created by overlapping matrix $A$ with matrix $A$ moved $X$ rows down and $Y$ columns to the right. Consider the cell $(i, j)$ in matrix $B$:

If cell $(i, j)$ is not in any matrix, $B_{i, j} = 0$ If cell $(i, j)$ is in both the initial matrix $A$ and in the moved matrix $A$, $B_{i, j} = A_{i, j} + A_{i - x, j - y}$ if cell $(i, j)$ is only in a matrix then $B_{i, j} = A_{i, j}$ or $B_{i, j} = A_{i - x, j - y}$ depending on the matrix that intersects the cell.

Given the matrix $B$, $X$ and $Y$ find out matrix $A$.

### Standard input

The first line contains four integers $H$, $W$, $X$ and $Y$.

The next $H + X$ lines contains $W + Y$ integers representing the values of matrix $B$.

### Standard output

Print $H$ lines, each line containing $W$ integers, representing the values of matrix $A$.

### Constraints and notes

$2 \leq H \leq 300$ $2 \leq W \leq 300$ $1 \leq X < H$ $1 \leq Y < W$ $0 \leq B_{i, j} \leq 1000$ It is guaranteed that there exists a valid matrix $A$ 

| Input | Output |
| --- | --- |
| 2 4 1 1<br>1 2 3 4 0<br>5 7 9 11 4<br>0 5 6 7 8 | 1 2 3 4 <br>5 6 7 8 |
| 3 3 2 1<br>1 2 3 0<br>4 5 6 0<br>7 9 11 3<br>0 4 5 6<br>0 7 8 9 | 1 2 3 <br>4 5 6 <br>7 8 9 |
