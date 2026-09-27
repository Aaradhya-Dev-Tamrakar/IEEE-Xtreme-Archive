# Path Inversions

**Time Limit:** `2500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/path-inversions/](https://csacademy.com/contest/archive/task/path-inversions/)  

---

Consider a tree with $N$ nodes. Alex chooses a node $v$ as a starting point and then travels over $K$ edges. The resulting path consists of $K+1$ nodes. Alex then builds an array $A$ of size $K+1$ using the labels of the nodes and counts the number inversions of this array. An inversion is pair of indices $(i, j)$, such that $i < j$ and $A_i > A_j$.

You don't know the starting point or the edges travelled, so you should find the sum of the number of inversions for all the possibilities.

### Standard input

The first line contains two integers $N$ and $K$.

Each of the next $N-1$ lines contains two integers, representing two nodes that share an edge.

### Standard output

Print the answer modulo $10^9+7$ on the first line.

### Constraints and notes

$1 \leq K < N \leq 10^5$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 4 1<br>1 2<br>1 3<br>1 4 | 3 | There are 6 paths with 1 edge in this graph: 1-2, 1-3, 1-4, 2-1, 3-1, 4-1. 3 of them have 1 inversion, and 3 of them have 0. |
| 4 3<br>1 2<br>2 3<br>2 4 | 0 | In this graphs there are no paths with 3 edges at all. |
