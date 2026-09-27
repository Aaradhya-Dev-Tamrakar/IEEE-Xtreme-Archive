# Tree Reconstruction

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/tree-construct/](https://csacademy.com/contest/archive/task/tree-construct/)  

---

Consider an unweighted tree $T$, whose nodes are labelled by positive integers 1 to $N$. Define $p_i$ as the node id of the unique farthest node to node $i$,  or $-1$ if the farthest node to node $i$ is not unique. Define the ordered sequence ${p_1, p_2, ..., p_N}$ as the characteristic of tree $T$. You are given $N$ integers $p_i$, find an unweighted tree $T$ whose characteristic is exactly the ordered sequence ${p_1, p_2, ..., p_N}$.

### Standard input

The first line contains one integer $N$. The second line contains $N$ integers ${p_1, p_2, ..., p_N}$, in this order.

### Standard output

If a solution exists, output Possible in the first line. Each of the next $N-1$ lines in the output should contain two integers, which describes the edges of the tree.

If no solution exists, output Impossible in the first line.

### Constraints and notes

$1  \leq N \leq 100\,000$ $p_i = -1$, or $1 \leq p_i \leq \ N$ 

| Input | Output |
| --- | --- |
| 2<br>2 1 | Possible<br>1 2 |
| 2<br>1 2 | Impossible |
| 3<br>3 -1 1 | Possible<br>1 2<br>2 3 |
| 4<br>-1 -1 -1 -1 | Possible<br>1 4<br>2 4<br>3 4 |
