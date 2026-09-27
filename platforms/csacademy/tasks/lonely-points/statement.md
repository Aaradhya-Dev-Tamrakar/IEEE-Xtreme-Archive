# Lonely Points

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/lonely-points/](https://csacademy.com/contest/archive/task/lonely-points/)  

---

There are $N$ points on an axis. You know the coordinate of each point, denoted by $C_i$.

The distance between point $i$ and point $j$ is $|C_i - C_j|$.

The loneliness of a set of points is defined as the maximum distance between two adjacent points on the axis.

You can take one point and move it at any other integer coordinate on the axis. Your task is to minimise the loneliness of the set.

### Standard input

The first line contains the integer $N$.

The second line contains $N$ integers representing the coordinates of the points.

### Standard output

You should print one number representing the minimum value of the maximum loneliness.

### Constraints and notes

$3 \leq N \leq 10^5$ $0 \leq C_i \leq 10^9$ $C_{i} < C_{i+1}$ for $1 \leq i < N$

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>0 6 7 8 | 1 | By moving the point from position $0$ to position $9$ we achieve a maximum segment length of $1$. |
| 6<br>0 10 23 30 41 60 | 11 | Move the point from coordinate $60$ to coordinate $16$. The segment length will be:1067711The maximum length is $11$. |
