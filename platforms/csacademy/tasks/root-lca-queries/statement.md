# Root LCA Queries

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/root-lca-queries/](https://csacademy.com/contest/archive/task/root-lca-queries/)  

---

You are given a tree with $N$ nodes. Answer $Q$ queries of the type:

Given three nodes $A$, $B$ and $C$, find the number of nodes $D$ such that if you root the tree in $D$, the lowest common ancestor of $A$ and $B$ is $C$.

### Standard input

The first line contains two integers $N$ and $Q$.

Each of the next $N-1$ lines contains two integers, representing two nodes that share an edge.

Each of the next $Q$ lines contains three integers $A$, $B$ and $C$, representing a query.

### Standard output

For each query print the answer on a different line.

### Constraints and notes

$1 \leq N, Q \leq 10^5$ The three nodes $A$, $B$ and $C$ are distinct

| Input | Output | Explanation |
| --- | --- | --- |
| 7 5<br>1 2<br>2 3<br>3 4<br>4 5<br>2 6<br>1 7<br>6 5 1<br>6 5 2<br>6 5 3<br>7 6 2<br>7 5 2 | 0<br>3<br>1<br>4<br>2 | 1234567 |
