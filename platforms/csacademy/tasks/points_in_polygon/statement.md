# Points in Polygon

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/points_in_polygon/](https://csacademy.com/contest/archive/task/points_in_polygon/)  

---

You are given a polygon (not necessarily convex) with $N$ vertices and another $M$ points. You should compute the number of points that lie inside the polygon or on its sides.

### Standard input

The first line contains two integer values $N$ and $M$.

Each of the next $N$ lines contains two integers, representing the coordinates of the vertices in clockwise order.

Each of the next $M$ lines contains two integers, representing the coordinates of the points.

### Standard output

The output should consist of a single integer representing the number of points the lie inside the polygon or on its sides.

### Constraints and notes

$1$ ≤ $N$ ≤ $2000$$1$ ≤ $M$ ≤ $10^5$The coordinates of both the vertices and the points are integers between $0$ and $10^5$The polygon does not self intersectFor 20% of the test cases, $N \leq 15$ and $M \leq 20$For 50% of the test cases, $N \leq 500$ and $M \leq 2000$

| Input | Output |
| --- | --- |
| 4 3<br>1 1<br>1 4<br>4 4<br>4 1<br>2 3<br>3 4<br>3 0 | 2 |
| 4 3<br>1 4<br>3 2<br>5 4<br>3 0<br>2 0<br>3 1<br>4 2 | 2 |
| 5 5<br>2 1<br>2 3<br>5 4<br>3 2<br>5 0<br>4 0<br>4 1<br>4 2<br>4 3<br>4 4 | 2 |
| 6 3<br>4 6<br>1 6<br>3 0<br>0 0<br>0 7<br>6 7<br>2 0<br>3 1<br>0 2 | 2 |
