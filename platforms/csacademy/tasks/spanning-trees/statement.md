# Spanning Trees

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/spanning-trees/](https://csacademy.com/contest/archive/task/spanning-trees/)  

---

You are given two integers $N$ and $K$. Generate a weighted undirected graph with $N$ nodes such that:

Both the minimum and the maximum spanning trees are uniqueThe minimum and the maximum spanning trees have exactly $K$ edges in common

### Standard input

The first line contains two integers $N$ and $K$.

### Standard output

If there is no solution, output $-1$.

Otherwise, on the first line print a single integer $M$, the number of edges of the graph.

Each of the next $M$ line should contain three integers $a, b, c$, representing an edge between nodes $a$ and $b$ with cost $c$.

### Constraints and notes

$0 \leq K < N \leq 10^5$ Multiple edges or self-loops are not allowedThe costs of the edges should be between $1$ and $10^9$ $M$ should be at most $2 * N$

| Input | Output | Explanation |
| --- | --- | --- |
| 4 1 | 5<br>1 2 1<br>1 3 2<br>1 4 3<br>2 4 4<br>3 4 5 | The green edges are only in the minimum spanning tree.The red edges are only in the maximum spanning tree.The blue edges are part of both.123451234 |
| 4 0 | 6<br>1 2 1<br>2 3 2<br>3 4 3<br>2 4 4<br>4 1 5<br>1 3 6 | 1423561234 |
| 1 0 | 0 | 1 |
