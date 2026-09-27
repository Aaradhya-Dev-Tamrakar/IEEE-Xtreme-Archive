# Rectangle Path

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/rectangle-path/](https://csacademy.com/contest/archive/task/rectangle-path/)  

---

In a matrix with $N$ rows and $M$ columns you have a rectangle of height $H$ and width $W$. Initially the upper left corner of the rectangle is in the cell $(S_r, S_c)$.

At each step you can move the rectangle one row up/down or one column left/right, without leaving the matrix. In addition, some of the cells are forbidden, meaning the rectangle is not allowed to overlap them.

Find the minimum number of steps needed to bring the upper left corner of the rectangle in the cell $(F_r, F_c).$

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $N$ lines contains $M$ integers corresponding to the cells. A normal cell is represented by a $0$, while a forbidden one by a $1$.

The next line contains $6$ integers $H, W, S_r, S_c, F_r, F_c$.

### Standard output

If there is no solution output $-1$.

Otherwise, print a single integer representing the minimum number of steps needed.

### Constraints and notes

$1 \leq N, M \leq 1000$ Initially the rectangle lies within the matrix boundaries and does not overlap any forbidden cell

| Input | Output | Explanation |
| --- | --- | --- |
| 4 5<br>0 0 0 0 0<br>0 0 1 0 0<br>0 0 0 0 0<br>0 0 0 0 0<br>2 2 1 1 1 4 | 7 | down down right right right up up |
| 6 7<br>0 0 0 0 0 0 0<br>0 0 0 1 0 0 0<br>0 0 0 0 0 0 0<br>0 0 0 0 0 0 1<br>0 0 1 0 0 0 0<br>0 0 0 0 0 0 0<br>2 3 1 1 5 5 | 8 | down down right right right down down right |
