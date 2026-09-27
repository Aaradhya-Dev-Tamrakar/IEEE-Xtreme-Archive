# Black Shapes

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/black-shapes/](https://csacademy.com/contest/archive/task/black-shapes/)  

---

You are given a matrix with $N$ rows and $M$ columns. Each cell is either white or black.

We say that two cells are neighbours if they share one of their four sides.

A black shape is a maximal subset of black cells such that any cell is accessible from any other cell by moving only along neighbours.

You should change the colour of exactly one cell in order to maximise the size of the largest black shape.

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $N$ lines contains $M$ integers: $0$ for a white cell and $1$ for a black cell.

### Standard output

Print a single integer representing the largest possible size of a black shape.

### Constraints and notes

$1 \leq N, M \leq 1000$ There is at least one white cell and one black cell in the matrix

| Input | Output | Explanation |
| --- | --- | --- |
| 3 3<br>0 1 1<br>0 0 1<br>0 1 0 | 5 | Colouring the cell at coordinates $[2, 2]$ unites the 2 black shapes with sizes $1$ and $3$, rezulting a shape of size $5$, including the newly coloured cell. |
| 5 4<br>1 1 0 0<br>1 0 1 0<br>1 0 1 0<br>0 1 1 0<br>1 0 0 1 | 10 | Changing the color of the cell $[4, 1]$(line $4$, column $1$) creates a black shape of size $4 + 4 + 1 + 1 = 10$ |
| 3 4<br>0 1 0 1<br>0 0 0 1<br>1 1 0 1 | 6 | Changing the color of the cell $[3, 3]$ creates a black shape of size $2 + 3 + 1 = 6$ |
