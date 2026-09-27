# Empty Triangles

**Time Limit:** `1500 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/empty-triangles/](https://csacademy.com/contest/archive/task/empty-triangles/)  

---

You are given $K$ points with positive integer coordinates. You are also given $M$ triangles, each of them having one vertex in the origin and the other two vertices with non-negative integer coordinates.

You are asked to determine for each triangle whether it has at least one of the $K$ given points inside. (None of the $K$ points are on any edge of any triangle.)

### Standard input

The first line contains two integers $K$ and $M$.

Each of the following $K$ lines contain two positive integers $x\ y$ separated by one space representing the coordinates of each point.

The next $M$ lines contain four non-negative integers separated by one space, $(x1,y1)$ and $(x2, y2)$, that represent the other two vertices of each triangle, except the origin.

### Standard output

The output should contain exactly $M$ lines. The $k$-th line should contain the character Y if the $k$-th triangle (in the order of the input file) contains at least one point inside it, or N otherwise.

### Constraints and notes

$1 \leq K, M \leq 10^5$$1 \leq$ each coordinate of the $K$ points $\leq 10^9$$0 \leq$ each coordinate of the triangle vertices $\leq 10^9$Triangles are not degenerate (they all have nonzero area).In 50% of the test cases, all triangles have vertices with coordinates $x1=0$ and $y2=0$.

| Input | Output |
| --- | --- |
| 3 3<br>1 5<br>2 4<br>3 1<br>3 0 0 4<br>5 0 0 8<br>3 0 0 8 | N<br>Y<br>Y |
| 5 4<br>2 5<br>1 3<br>4 4<br>3 2<br>5 3<br>4 1 3 3<br>1 2 3 4<br>0 5 3 6<br>6 3 6 5 | Y<br>N<br>Y<br>Y |
