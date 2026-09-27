# Max Score Tree

**Time Limit:** `1500 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/max-score-tree/](https://csacademy.com/contest/archive/task/max-score-tree/)  

---

You are given a tree with $N$ nodes. You are also given an array $score$ of $N$ values. On this tree you can perform the following type of operations:

Choose any edge and delete it. From the resulting two connected components keep one and discard the other.

You are allowed to perform as many operations as you want (possibly none, at most $N-1$). In the end the total score of the tree left is computed as $\sum score[degree_{node}]$. You need to maximize this total score.

### Standard input

The first line contains a single integer $N$ representing the number of nodes of the tree.

The second line contains $N$ values representing the elements of $score$ (0-indexed).

Each of the next $N-1$ lines contains two integer values, representing two nodes that share an edge.

### Standard output

The output should contain a single integer representing maximum total score you can get.

### Constraints and notes

$1 \leq N \leq 10^5$The nodes are numbered from $1$ to $N$The elements of $score$ are integers between $-10^9$ and $10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>10 1 2 3<br>1 2<br>1 3<br>2 4 | 10 | We get the best cost by performing any two operations, obtaining a graph with a single node. |
| 5<br>0 1 5 1 1<br>1 2<br>1 3<br>1 4<br>1 5 | 7 | Choose the edge $1-2$, and keep the connected component of node $1$.Next choose the edge $1-3$, and again keep the connected component of node $1$.In this way the degrees of the resulting tree are $\{2, 1, 1\}$. |
| 5<br>-5 -1 1 1 1<br>1 2<br>1 3<br>3 4<br>3 5 | 0 | Choose the edge $3-5$ and keep the connected component of node $3$.The degrees of the resulting tree are $\{2, 2, 1, 1\}$. |
| 4<br>-10 1 -2 -3<br>1 2<br>2 3<br>3 4 | 2 | Choose the edge $2-3$ and keep the connected component of node $2$.The degrees of the resulting tree are $\{1, 1\}$. |
