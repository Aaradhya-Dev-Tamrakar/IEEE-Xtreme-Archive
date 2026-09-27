# Tree Coloring

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/tree-coloring/](https://csacademy.com/contest/archive/task/tree-coloring/)  

---

You are given a tree with $N$ nodes and a number $K$. You should paint every node in one of the $K$ available colors.

Count the number of ways of painting the tree such that any two nodes that are at distance $1$ or $2$ are painted in different colors.

### Standard input

The first line contains two integer $N$ and $K$.

Each of the next $N-1$ lines contains two integers representing two nodes that share an edge.

### Standard output

Print the answer modulo $10^9+7$ on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq K \leq 10^9$

| Input | Output |
| --- | --- |
| 3 3<br>2 1<br>3 2 | 6 |
| 5 4<br>1 2<br>4 2<br>5 1<br>3 1 | 48 |
| 5 3<br>5 3<br>4 3<br>1 3<br>2 4 | 0 |
