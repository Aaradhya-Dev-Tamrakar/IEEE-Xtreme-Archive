# Triangular Updates

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/triangular-updates/](https://csacademy.com/contest/archive/task/triangular-updates/)  

---

Consider a matrix $A$ of size $N \times N$. Initially all the cells are equal to $0$.

Perform $Q$ updates of the form:

Given four integers $R\ C\ L\ S$, add $S$ to all the cells $(x, y)$ such that $R \le x < R+L$, and $0 \le y - C \leq x - R$. Basically, you should update a triangular zone of the matrix, with the upper corner in $(R, C)$ and side $L$.

Print the final matrix.

### Standard input

The first line contains two integers $N$ and $Q$.

Each of the next $Q$ lines contains fours integers $R\ C\ L\ S$.

### Standard output

Print $N$ lines, each containing $N$ integers, representing the final values of the matrix.

### Constraints and notes

$1 \leq N \leq 1000$ $1 \leq Q \leq 3 * 10^5$ $1 \leq R, C \leq N$ $1 \leq L \leq 1000$ $1 \leq S \leq 10^9$

| Input | Output |
| --- | --- |
| 10 4<br>1 1 100 1<br>5 5 4 4<br>1 9 4 3<br>3 3 5 2 | 1 0 0 0 0 0 0 0 3 0<br>1 1 0 0 0 0 0 0 3 3<br>1 1 3 0 0 0 0 0 3 3<br>1 1 3 3 0 0 0 0 3 3<br>1 1 3 3 7 0 0 0 0 0<br>1 1 3 3 7 7 0 0 0 0<br>1 1 3 3 7 7 7 0 0 0<br>1 1 1 1 5 5 5 5 0 0<br>1 1 1 1 1 1 1 1 1 0<br>1 1 1 1 1 1 1 1 1 1 |
