# Bad Triplet

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/bad-triplet/](https://csacademy.com/contest/archive/task/bad-triplet/)  

---

You are given a simple, undirected, connected graph with $N$ nodes and $M$ edges. Find $3$ nodes $A$, $B$ and $C$ such that the minimum distance between $A - B$, $A-C$ and $B-C$ is the same.

### Standard input

The first line contains two integer $N$ and $M$.

Each of the next $M$ lines contains two integers representing two nodes that share an edge.

### Standard output

If there is no solution output $-1$.

Otherwise print three distinct integers, representing the nodes $A$, $B$ and $C$.

### Constraints and notes

$1 \leq N, M \leq 10^5$ 

| Input | Output |
| --- | --- |
| 8 8<br>1 6<br>6 3<br>3 4<br>4 5<br>4 7<br>7 8<br>8 1<br>5 2 | 1 7 3 |
| 3 2<br>1 3<br>2 3 | -1 |
