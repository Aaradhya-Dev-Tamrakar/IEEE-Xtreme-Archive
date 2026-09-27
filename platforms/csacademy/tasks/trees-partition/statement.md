# Trees Partition

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/trees-partition/](https://csacademy.com/contest/archive/task/trees-partition/)  

---

You are given two trees, each with $N$ nodes numbered from $1$ to $N$. When you remove an edge from a tree, it partitions the set of nodes into two subsets.

Assume that two subsets are the same if the sets of numbers of nodes they contain are the same.

Count the numbers of pairs of edges $(e_1, e_2)$, $e_1$ from the first tree, $e_2$ from the second, such that they partition the nodes into the same subsets.

### Standard input

The first line contains a single integer $N$.

The next line contains $N - 1$ integers $p_2, p_3, ..., p_N$, describing edges of the first tree. For each $i \in 2..N$, nodes $i$ and $p_i$ are connected.

The following line contains $N-1$ integers $q_2, q_3, ..., q_N$, describing edges of the second tree in the same way.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \le N \le 3 \times 10^5$ $1 \le p_i, q_i \le N$ for $i \in 2..N$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>1 1 1<br>1 1 2 | 2 | We can select an edge $1-3$ in the first graph and in the second graph. The subsets will be $\{3\}$ and $\{1, 2, 4\}$ for both graphs.Also we can select an edge $1-4$ in the first graph and $2-4$ in the second graph. The subsets will be $\{4\}$ and $\{1, 2, 3\}$ |
| 6<br>1 2 3 4 5<br>1 2 5 6 1 | 1 | Remove edge $3-4$ in the first graph and edge $1-6$ in the second graph. The subsets will be $\{1, 2, 3\}$ and $\{4, 5, 6\}$ |
