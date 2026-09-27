# Right Triangles

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/right-triangles/](https://csacademy.com/contest/archive/task/right-triangles/)  

---

You are given $N$ points having positive coordinates. It is guaranteed all the points have distinct x coordinates and there are no two points that are collinear with the origin.

For each point having coordinates$(x, y)$ consider the right triangle formed by:

the point itself: $(x, y)$ the origin of the coordinate system: $(0, 0)$ the point's projection on the x-axis: $(x, 0)$.

For each triangle count how many of the other $N-1$ points it contains.

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines contains two integers representing the coordinates of a point.

### Standard output

Print $N$ lines, each containing the answer for a point, in the order given in the input.

### Constraints and notes

$2 \leq N \leq 10^5$ The coordinates of the points are between $1$ and $10^5$

| Input | Output |
| --- | --- |
| 2<br>4 4<br>1 6 | 0<br>0 |
| 3<br>2 1<br>3 2<br>4 3 | 0<br>1<br>2 |
