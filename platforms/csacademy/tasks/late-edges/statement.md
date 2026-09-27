# Late Edges

**Time Limit:** `1500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/late-edges/](https://csacademy.com/contest/archive/task/late-edges/)  

---

Consider an undirected graph with $N$ nodes and $M$ edges. At moment $0$ you are in node $1$ and your goal is to get to node $N$ as soon as possible.

It takes you $1$ second to traverse an edge, and you are not allowed to stop in a node (so each second you should traverse an edge). For each edge you know a moment when it becomes available. Before that moment you are not allowed to traverse the edge, but after that you can use it at any time.

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $M$ lines contains three integers $a, b, c$ representing an edge between $a$ and $b$ that becomes available at moment $c$.

### Standard output

If there is no solution output $-1$.

Otherwise, print the minimum time you need to get to node $N$ on the first line.

### Constraints and notes

$2 \leq N \leq 5\,000$ $1 \leq M \leq 5\,000$ The moments when edges become available are between $0$ and $10^9$ There is at least one edge incident in node $1$ that becomes available at moment $0$.

| Input | Output |
| --- | --- |
| 3 2<br>1 2 0<br>1 3 5 | 7 |
| 3 3<br>1 2 0<br>2 3 1<br>1 3 10 | 2 |
| 4 3<br>1 2 0<br>2 3 0<br>3 1 0 | -1 |
