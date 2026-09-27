# Dependency Graph

**Time Limit:** `2000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/dependency-graph/](https://csacademy.com/contest/archive/task/dependency-graph/)  

---

You are given a directed graph with $N$ nodes and $M$ edges. In this graph the following property holds true:

For any three nodes $A$, $B$ and $C$ such that there is a path from $A$ to $C$ and a path from $B$ to $C$ then there is a path from $A$ to $B$ or one from $B$ to $A$ (possibly both).

You are allowed to choose any subset of edges and change their orientation (the tail becomes the head and the head becomes the tail). Compute the minimum possible size of a subset such that the graph becomes strongly connected or decide if this is not possible.

### Standard input

The first line contains two integer values $N$ and $M$.

Each of the next $M$ lines contains two integer values, representing two nodes that share an edge.

### Standard output

The output should consist of a single integer representing the minimum number of edges that need to be changed or $-1$ if there is no solution.

### Constraints and notes

$1 \leq N \leq 10^5$$1 \leq M \leq 3*10^5$The nodes are numbered from $1$ to $N$.

| Input | Output | Explanation |
| --- | --- | --- |
| 3 3<br>1 2<br>2 3<br>1 3 | 1 | Changing the orientation of the edge $(1 \rightarrow 3)$ gives the solution with the minimum number of edges. |
| 3 3<br>1 2<br>2 3<br>3 1 | 0 | The graph is already strongly connected. |
| 4 5<br>1 2<br>2 3<br>2 4<br>1 3<br>1 4 | 2 | The chosen edges are ${(1 \rightarrow 3), (1 \rightarrow 4)}$. |
| 5 5<br>2 1<br>1 3<br>1 4<br>4 5<br>2 5 | -1 | There's no solution since node $3$ has only $1$ incident edge. |
| 4 5<br>1 2<br>1 3<br>2 3<br>3 4<br>4 2 | 1 | There are $2$ ways to achieve the solution with the minimal cost. Choosing the edge $(1 \rightarrow 3)$ or $(1 \rightarrow 4)$. |
