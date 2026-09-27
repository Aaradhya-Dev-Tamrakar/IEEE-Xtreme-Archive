# Bounding Box

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/bounding-box/](https://csacademy.com/contest/archive/task/bounding-box/)  

---

You are given a set of $N$ points having integer coordinates. Find the area of the smallest rectangle that:

Has sides parallel to the coordinate axisContains all the points inside or on its sides

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines contains two integers representing the coordinates of a point.

### Standard output

Print a single integer representing the area of the rectangle.

### Constraints and notes

$2 \leq N \leq 1000$ The coordinates are integers between $1$ and $1000$. There are no two points that have the same $x$ or $y$ coordinate.

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>1 1<br>1 3<br>3 1 | 4 | The bounding box has coordinates $(1, 1)$ and $(3, 3)$ with area $4$ |
| 3<br>2 3<br>3 4<br>4 1 | 6 | The bounding box has coordinates $(2, 1)$ and $(4, 4)$ with area $6$ |
