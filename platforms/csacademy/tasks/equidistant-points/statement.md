# Equidistant Points

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/equidistant-points/](https://csacademy.com/contest/archive/task/equidistant-points/)  

---

You're given a number $N$. You need to place $N$ points on the $2D$ plane, such that there are exactly $N$ pairs of points with distance equal to $1$, and all other pairs of points are at a distance strictly less than $1$.

### Standard input

A single integer, $N$.

### Standard output

You should output $N$ lines, each with $2$ numbers representing the $X$ and $Y$ coordinates of the points.

### Constraints and notes

$3 \leq N \leq 1024$ All of your coordinated need to be between $-10$ and $10$.Two distances are considered to be equal with a precision error of $10^{-9}$.The distance between any $2$ points needs to be at least $10^{-4}$

| Input | Output |
| --- | --- |
| 3 | 0 1<br>1 1<br>0.5 0.1339745962155614 |
