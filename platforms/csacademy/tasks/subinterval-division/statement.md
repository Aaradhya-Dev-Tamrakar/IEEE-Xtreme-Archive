# Subinterval Division

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/subinterval-division/](https://csacademy.com/contest/archive/task/subinterval-division/)  

---

You are given a set $S$ of $N$ points and a segment on the x-axis, between $(0, 0)$ and $(X, 0)$.

You should divide the segment into one or more subsegments, such that for all the points in a subsegment the closest point from $S$ is the same.

For each point $P$ in $S$, print the sum of lengths of the subsegments for which $P$ is the closest point.

### Standard input

The first line contains two integers $N$ and $X$.

Each of the next $N$ lines contains two integers representing the $x$ and $y$ coordinates of a point in $S$.

### Standard output

Print $N$ lines, each containing the answer for a point in $S$.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq X \leq 10^9$ The coordinates of the points are integers between $0$ and $10^9$ An answer is considered correct if the absolute difference between it and the official answer is less than $10^{-6}$. The points in $S$ are distinct.

| Input | Output |
| --- | --- |
| 3 10<br>3 1<br>0 2<br>5 3 | 5.000000000<br>1.000000000<br>4.000000000 |
