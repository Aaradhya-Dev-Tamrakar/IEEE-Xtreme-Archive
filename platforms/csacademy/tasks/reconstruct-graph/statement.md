# Reconstruct Graph

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/reconstruct-graph/](https://csacademy.com/contest/archive/task/reconstruct-graph/)  

---

Count the number of graphs with $N$ nodes that respect the following properties:

the graph is connectedthe minimum distance from node $1$ do node $i$ is equal to $D_i$ the graph contains all of $M$ given edges (and possibly some extra ones)the graph doesn't contain multiple edges or self loops

### Standard input

The first line contains two integers $N$ and $M$.

The second line contains $N$ integers representing the values of $D$.

Each of the next $M$ lines contains two integers representing two nodes that share an edge.

### Standard output

Print the number of possible graphs modulo $10^9+7$.

### Constraints and notes

$1 \leq N \leq 10^5$ $0 \leq M \leq 10^5$ The values of $D$ are integers between $0$ and $N-1$ $D_1 = 0$

| Input | Output | Explanation |
| --- | --- | --- |
| 3 2<br>0 1 1<br>1 2<br>2 3 | 1 | The only valid graph looks like this:123 |
| 4 1<br>0 1 2 3<br>2 3 | 1 | 1234 |
| 5 2<br>0 1 2 2 0<br>3 4<br>4 5 | 0 | The distance to node $5$ can't be $0$ in any graph. |
| 5 2<br>0 2 2 1 1<br>2 3<br>3 4 | 12 |  |
