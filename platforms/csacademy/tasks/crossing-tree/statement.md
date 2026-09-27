# Crossing Tree

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/crossing-tree/](https://csacademy.com/contest/archive/task/crossing-tree/)  

---

You are given a tree of $N$ nodes. Find a path that traverses every edge at least once and has minimum length. The path can start from any node, end in any node and cross edges multiple times.

### Standard input

The first line contains $N$.

Each one of the next $N - 1$ lines will contain an edge $(u, v)$.

### Standard output

Print the number of edges you've traversed in your path. Let's call this number $P$.

On the next line you should print $P + 1$ nodes representing the path.

### Constraints and notes

$2 \leq N \leq 10^5$ $1 \leq u, v \leq N$

| Input | Output | Explanation |
| --- | --- | --- |
| 6<br>1 2<br>1 3<br>3 4<br>3 5<br>3 6 | 7<br>2 1 3 5 3 6 3 4 | 123456 |
