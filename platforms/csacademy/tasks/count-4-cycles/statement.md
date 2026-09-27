# Count 4-cycles

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/count-4-cycles/](https://csacademy.com/contest/archive/task/count-4-cycles/)  

---

You are given two trees of $N$ nodes each, $T_1$ and $T_2$. Suppose $N$ additional bidirectional edges are added: the $i^{\text{th}}$ edge will join nodes $i$ from $T_1$ and $i$ from $T_2$, for every $1 \leq i \leq N$.

How many simple cycles of length $4$ are there in the resulting graph?

### Standard input

The first line contains $N$.

The next $N - 1$ lines contain two integers, denoting an edge from $T_1$.

The next $N - 1$ lines contain two integers, denoting an edge from $T_2$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ Throughout the whole problem, $1$-based indexing of the nodes is considered.

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>1 2<br>1 3<br>3 4<br>3 1<br>1 4<br>2 4 | 1 | The red nodes are from the second tree.The cycle is 1 1 3 312343142 |
