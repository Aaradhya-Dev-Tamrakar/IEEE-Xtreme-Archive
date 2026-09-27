# Zone Capture

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/zone-capture/](https://csacademy.com/contest/archive/task/zone-capture/)  

---

You are given a binary matrix of $N$ rows and $M$ columns. We consider a cell equal to $0$ to be white, and a cell equal to $1$ to be black.

We say that two cells are neighbours if they share one of their four sides. A zone is a maximal subset of white cells such that any cell is accessible from any other cell by moving only along neighbours.

It is guaranteed that initially the matrix contains only one zone, and in addition one of the zone's cells lies on the border of the matrix (first/last row/column).

You can change the color of exactly one white cell to black. When you do this, the initial zone might split in  two or more zones. Each of the resulting zones that doesn't have a cell on the matrix border becomes black. Your goal is to maximize the total number of resulting black cells.

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $N$ lines contains $M$ binary values representing the cells of the matrix.

### Standard output

Print a single integer representing the total number of black cells the matrix can contain after changing the color of one white cell.

### Constraints and notes

$1 \leq N, M \leq 1000$

| Input | Output |
| --- | --- |
| 3 3<br>0 1 1<br>0 0 1<br>0 1 1 | 7 |
| 5 4<br>1 1 0 0<br>1 0 1 0<br>1 0 1 0<br>1 0 1 0<br>1 0 0 0 | 13 |
| 3 4<br>0 1 0 1<br>0 0 0 0<br>1 1 0 1 | 6 |
| 4 4<br>0 0 0 1<br>0 0 1 1<br>1 0 0 1<br>1 1 1 1 | 12 |
