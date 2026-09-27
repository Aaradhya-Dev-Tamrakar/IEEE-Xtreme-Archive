# Critical Cells

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/critical-cells/](https://csacademy.com/contest/archive/task/critical-cells/)  

---

You are in the upper upper left corner - cell $(1, 1)$ - of a matrix with $N$ rows and $M$ columns. At each step you can move one cell down or to the right, until you get to the bottom right corner of the matrix.

Exactly $K$ of the cell are special. You want your path to pass through as many special cells as possible, let's call this number $Best$. A cell is critical if removing it (making it not special, but you can still pass through) results in $Best$ becoming less than before. Find out how many of the $K$ special cells are critical.

### Standard input

The first line contains three integere $N$, $M$ and $K$.

Each of the next $K$ lines contains two integers $r$ and $c$ representing the row and the column of a special cell.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N, M \leq 10^9$ $1 \leq K \leq 10^5$ 

| Input | Output |
| --- | --- |
| 3 20 6<br>1 1<br>1 3<br>1 8<br>2 1<br>2 5<br>2 10 | 2 |
| 10 10 5<br>1 1<br>2 2<br>2 4<br>4 2<br>5 5 | 3 |
| 1000000000 1000000000 5<br>2 6<br>6 3<br>1 1<br>2 5<br>3 1 | 1 |
