# Connected Tree Subgraphs

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/connected-tree-subgraphs/](https://csacademy.com/contest/archive/task/connected-tree-subgraphs/)  

---

You are given a tree with $N$ nodes. Count how many of the $N!$ permutations of the node labels lead to the tree respecting the following property:

For any $K (1\leq K\leq N)$ the subgraph induced by the nodes with labels $1, 2, ... , K$ is connected.

### Standard input

The first line contains a single integer $N$.

Each of the following $N-1$ lines contains two integer values, representing two nodes that share an edge.

### Standard output

Output a single integer representing the answer modulo $10^9+7$.

### Constraints and notes

$1 \leq N \leq 10^5$The nodes are numbered from $1$ to $N$.

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>1 2<br>2 3 | 4 | 123 |
| 4<br>1 2<br>1 3<br>3 4 | 8 | 1234 |
| 7<br>1 2<br>1 3<br>2 4<br>2 5<br>3 6<br>3 7 | 240 | 1234567 |
