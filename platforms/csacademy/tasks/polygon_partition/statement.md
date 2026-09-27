# Polygon Partition

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/polygon_partition/](https://csacademy.com/contest/archive/task/polygon_partition/)  

---

Consider you have a convex polygon of size N, the vertices being labeled from $1$ to $N$ clockwise. You want to partition this polygon in $K$ regions by drawing $K-1$ segments between the vertices, in such a way that no two segments will intersect, with the exception of segments sharing a vertex.

Count the number of ways of achieving this kind of partitioning.

### Standard input

The first line contains two integer values $N$ and $K$.

### Standard output

The output should contains a single value representing the number of partitions modulo $10^9+7$.

### Constraints and notes

$3 \leq N \leq 125$$1 \leq K \leq N-2$For 20% of the test cases, $N \leq 20$For 40% of the test cases, $N \leq 50$For 60% of the test cases, $N \leq 100$

| Input | Output | Explanation |
| --- | --- | --- |
| 5 2 | 5 | The $5$ ways to partition the polygon are by choosing the segments:$(1 - 3)$, $(2 - 4)$, $(3 - 5)$, $(4 - 1)$, $(5 - 2)$ |
| 6 3 | 21 | - |
| 10 3 | 385 | - |
