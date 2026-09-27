# Surrounded Rectangle

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/surrounded-rectangle/](https://csacademy.com/contest/archive/task/surrounded-rectangle/)  

---

You are given a matrix with $N$ rows and $M$ columns. Each element of the matrix is either $0$ or $1$. You have to find the largest area of a rectangle that contains only $1$s and is completely surrounded by $0$s.

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $N$ lines contains $M$ integers representing the elements of the matrix. All these values are equal to $0$ or $1$.

### Standard output

Output $-1$ if there is no solution. Otherwise, print a single integer representing the largest area found.

### Constraints and notes

$1 \leq N, M \leq 1000$The rectangle has to lie strictly inside the matrix, so you shouldn't consider those that start/end on the first/last row/column.

| Input | Output | Explanation |
| --- | --- | --- |
| 3 4<br>0 0 0 0<br>0 1 1 0<br>0 0 0 0 | 2 |  |
| 5 5<br>1 1 0 0 0<br>1 1 0 1 0<br>0 0 0 1 0<br>0 1 0 1 0<br>0 0 0 0 0 | 3 | Even though there is a $2\times2$ square in the upper left corner, rectangles on the edge of the matrix are not considered valid. |
| 3 3<br>1 0 0<br>0 1 0<br>1 0 0 | -1 | A rectangle must be completely surrounded, even diagonally. |
