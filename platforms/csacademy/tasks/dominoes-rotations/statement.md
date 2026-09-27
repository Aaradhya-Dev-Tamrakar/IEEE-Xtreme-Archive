# Dominoes Rotations

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/dominoes-rotations/](https://csacademy.com/contest/archive/task/dominoes-rotations/)  

---

You have a set of $N$ dominoes. Each domino is a rectangular tile with a line dividing its face into two squares. On each square there are drawn some points. The number of points varies between $1$ and $6$.

The dominoes are placed horizontally in a line from left to right. What is the minimum number of tiles you should rotate $180^{\circ}$ such that for every pair of consecutive dominoes their touching squares share the same number of points?

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines contains two integers representing the number of points on the left side and on the right side of a domino piece.

### Standard output

If there is no solution output $-1$.

Otherwise, print a single integer representing the minimum number of dominoes you have to rotate.

### Constraints and notes

$2 \leq N \leq 10^5$

| Input | Output |
| --- | --- |
| 3<br>4 2<br>4 3<br>3 3 | 1 |
| 3<br>3 3<br>3 5<br>6 3 | -1 |
| 4<br>3 2<br>4 3<br>4 4<br>5 4 | 3 |
| 2<br>2 2<br>2 3 | 0 |
| 2<br>2 3<br>2 3 | 1 |
