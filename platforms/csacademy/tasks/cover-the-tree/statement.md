# Cover the Tree

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/cover-the-tree/](https://csacademy.com/contest/archive/task/cover-the-tree/)  

---

You are given a tree with $N$ nodes. Find the minimum number of simple paths such that each edge is part of at least one chosen path.

### Standard input

The first line contains a single integer $N$.

Each of the next $N-1$ lines contains two integers representing two nodes that share an edge.

### Standard output

On the first line print the minimum number $M$ of paths chosen.

Each of the next $M$ lines should contain two integers representing the two end nodes of a path.

### Constraints and notes

$2 \leq N \leq 10^5$ Nodes are labeled from $1$ to $N$ The chosen paths can intersect

| Input | Output |
| --- | --- |
| 5<br>1 2<br>2 3<br>3 4<br>3 5 | 2<br>1 4<br>5 3 |
| 6<br>1 4<br>4 3<br>1 2<br>5 4<br>6 3 | 2<br>2 6<br>5 4 |
| 7<br>1 2<br>2 3<br>2 4<br>1 5<br>1 6<br>1 7 | 3<br>4 6<br>5 7<br>3 1 |
