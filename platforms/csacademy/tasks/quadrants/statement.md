# Quadrants

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/quadrants/](https://csacademy.com/contest/archive/task/quadrants/)  

---

The axes of a two-dimensional Cartesian system divide the plane into four infinite regions, called quadrants, each bounded by two half-axes:

You are given $N$ points, decide how many of the $4$ quadrants contain at least one of the given points.

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines contains two integers $x_i$ and $y_i$ representing the coordinates of a point.

### Standard output

Print the answer on the first line, an integer between $1$ and $4$ representing the number of quadrants that contain at least one point.

### Constraints and notes

$1 \leq N \leq 1000$ $-1000 \leq x_i, y_i \leq 1000$ $x_i, y_i \neq 0$

| Input | Output |
| --- | --- |
| 4<br>1 2<br>4 3<br>-2 -1<br>-3 -2 | 2 |
| 4<br>1 1<br>1 -1<br>-1 1<br>-1 -1 | 4 |
| 2<br>2 2<br>3 3 | 1 |
