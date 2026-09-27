# Cyclic Shifts

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/cyclic-shifts/](https://csacademy.com/contest/archive/task/cyclic-shifts/)  

---

Table $N \times M$ is a permutation, if each cell contains a pair $(x, y)$ ($1 \le x \le N$, $1 \le y \le M$), and different cells contain different pairs.

Horizontal cyclic shift of a table moves each cell one square to the right, and moves the rightmost column to the leftmost column.

Vertical cyclic shift of a table moves each cell one square down, and moves the bottom-most row to the topmost row.

Call a table nice if it's a permutation, and after any combination of horizontal and vertical cyclic shifts there exists a pair $(i, j)$ such that a cell with coordinates $(i, j)$ contains a pair $(i, j)$.

You are given numbers $N$ and $M$.  Can you construct any nice table $N \times M$?

### Standard input

The first line contains two integers $N$ and $M$.

### Standard output

If there are no nice tables $N \times M$, print $0$.

Otherwise print $1$ in the first line. Then print $N$ lines containing $2M$ numbers in the table.

### Constraints and notes

$1 \le N, M \le 300$

| Input | Output |
| --- | --- |
| 2 4 | 1<br>1 1 2 2 1 2 2 3 <br>1 3 2 4 1 4 2 1 |
| 1 4 | 0 |
| 3 3 | 1<br>3 3 3 2 3 1 <br>2 3 2 2 2 1 <br>1 3 1 2 1 1 |
