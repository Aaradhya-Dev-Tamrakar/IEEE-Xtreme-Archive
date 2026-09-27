# Manhattan Center

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/manhattan-center/](https://csacademy.com/contest/archive/task/manhattan-center/)  

---

You are given $N$ points in the plane and a number $K$. You must choose a point $P$ on the x-axis (having coordinates $(X, 0)$) such that the sum of the Manhattan distances to the nearest $K$ points (considering Manhattan distances when determining those $K$ points) to $P$ is minimised.

### Standard input

The first line contains two integers $N$ and $K$.

Each of the next $N$ lines contains two integers representing the coordinates of a point.

### Standard output

Print the sum of Manhattan distances to the nearest $K$ points for an optimal $P$.

### Constraints and notes

$1 \leq K \leq N \leq 10^5$ The coordinates of the points are integers between $1$ and $10^8$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 5 3<br>1 1<br>1 4<br>2 1<br>2 2<br>4 2 | 5 | The point $P$ is situated on the $OX$ axis.The nearest $3$ points are $[1, 3, 4]$ 0123456012345612345P |
| 5 5<br>3 2<br>1 1<br>1 2<br>2 1<br>4 1 | 12 | The nearest $5$ points are $[1, 2, 3, 4, 5]$  having the sum of the distances equal to$3 + 2 + 3 + 1 + 3 = 12$ 01234560123412345P |
| 6 3<br>1 1<br>1 1<br>1 1<br>2 3<br>4 1<br>3 2 | 3 | Note that there may be multiple points having the same set of coordinates.The nearest $3$ points are $[1, 2, 3]$ 0123456012341,2,3456P |
