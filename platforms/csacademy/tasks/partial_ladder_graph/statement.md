# Partial Ladder Graph

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/partial_ladder_graph/](https://csacademy.com/contest/archive/task/partial_ladder_graph/)  

---

A ladder graph $L(N)$ is a planar graph with $2*N$ nodes and $N + 2*(N - 1)$ edges. It is isomorphic to the grid graph with $2$ lines and $N$ columns:

1N+12N+23N+3N-12N-1N2N

You want to delete a subset of edges (possibly none) such that the graph stays connected. Count the number of valid subsets of edges you can delete.

### Standard input

The first line contains a single integer value $N$.

### Standard output

The output should contain a single integer, representing the number of subsets of edges modulo $10^9+7$.

### Constraints and notes

$1 \leq N \leq 10^{18}$

| Input | Output | Explanation |
| --- | --- | --- |
| 2 | 5 | The valid subsets of edges are:$\{1,2\}$$\{1,3\}$$\{2,4\}$$\{3,4\}$Delete no edge |
| 1024 | 399356307 |  |
