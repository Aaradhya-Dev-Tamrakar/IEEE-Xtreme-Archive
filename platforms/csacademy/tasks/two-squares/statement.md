# Two Squares

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/two-squares/](https://csacademy.com/contest/archive/task/two-squares/)  

---

You are given a binary matrix with $N$ rows and $M$ columns, and an integer $K$. You need to choose two subsquares of size $K$ in this matrix. Squares may overlap. Cells that are inside at least one of the squares will be assigned $0$.

Choose the subsquares in a way to maximize the total number of $0$'s in the matrix.

### Standard input

The first line contains three integers representing $N$, $M$ and $K$.

Each of the following $N$ lines contains $M$ binary values ($0$/$1$), representing the configuration of the matrix.

### Standard output

The first line will contain the maximum number of $0$s that can be achieved.

### Constraints and notes

$1 \leq N, M \leq 200$ $1 \leq K \leq min(30, N, M)$

| Input | Output |
| --- | --- |
| 3 3 2<br>1 1 0<br>1 1 0<br>0 1 0 | 9 |
| 3 4 2<br>1 1 0 1<br>1 0 1 1<br>1 1 0 1 | 9 |
| 5 4 3<br>0 0 1 0<br>1 0 0 0<br>1 1 0 1<br>1 1 0 1<br>1 1 0 1 | 18 |
