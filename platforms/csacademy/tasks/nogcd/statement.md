# Nogcd

**Time Limit:** `800 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/nogcd/](https://csacademy.com/contest/archive/task/nogcd/)  

---

Boss, if $N \le 30\ 000$, you should try to optimise the $N^2$ solution. (Friedrich Nietzsche)

Let $G$ be a undirected connected graph with $N$ nodes and $M$ edges. Label each of the $M$ edges with a distinct integer from $1$ to $M$. For each node with degree greater than $1$, the greatest common divisor of its incident edges' labels should be $1$.

### Standard input

The first line contains two integers $N$ and $M$.

The next $M$ lines contain two integers $u$ and $v$, representing two nodes that share an edge.

### Standard output

Print $M$ lines, each containing three integers $u$, $v$ and $c$ corresponding to an edge with label $c$ between $u$ and $v$.

### Constraints and notes

$1 \le N \le 10^5$ $1 \le M \le 220\ 000$ There are no self-loops or multiple edges in the graph.

| Input | Output | Explanation |
| --- | --- | --- |
| 5 6<br>1 2<br>2 3<br>1 3<br>4 1<br>3 4<br>3 5 | 1 2 2<br>1 4 1<br>1 3 3<br>3 2 5<br>3 4 4<br>3 5 6 | $G$ has 5 nodes and 6 edges. The labels for node $1$ are $\{2, 1, 3\}$.The labels for node $2$ are $\{2, 5\}$.The labels for node $3$ are $\{3, 4, 5, 6\}$.The labels for node $4$ are $\{1, 4\}$.Node $5$ has degree $1$. |
