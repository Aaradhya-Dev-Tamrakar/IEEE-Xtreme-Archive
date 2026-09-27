# Root Change

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/root-change/](https://csacademy.com/contest/archive/task/root-change/)  

---

You are given a tree with $N$ nodes. You should analyze $N$ scenarios, in each scenario $i$ consider node $i$ to be the root of the tree.

In a rooted tree, you are allowed to cut exactly one edge. When you do this, all nodes that are connected to the root through this edge disappear. Count how many of the $N-1$ edges can be cut without changing the height of the tree.

### Standard input

The first line contains a single integer $N$.

Each of the next $N-1$ lines contain two integers representing two nodes that share an edge.

### Standard output

Print $N$ lines, on line $i$ the number of edges that can be cut when node $i$ is the root.

### Constraints and notes

$1 \leq N \leq 10^5$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>1 2<br>2 3 | 0<br>2<br>0 | 123 |
| 4<br>1 2<br>1 3<br>1 4 | 3<br>2<br>2<br>2 | 1234 |
| 5<br>1 2<br>1 3<br>2 4<br>2 5 | 3<br>2<br>2<br>1<br>1 | 12345 |
