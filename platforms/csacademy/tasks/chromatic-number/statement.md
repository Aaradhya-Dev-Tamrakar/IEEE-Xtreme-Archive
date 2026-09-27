# Chromatic Number

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/chromatic-number/](https://csacademy.com/contest/archive/task/chromatic-number/)  

---

You are given a simple undirected connected graph with $N$ nodes and $M$ edges with positive costs. From all the paths between $1$ and $N$ we'll call those that have the minimum total cost optimal. You should select $K$ nodes such that the number of optimal paths that pass through all the $K$ selected nodes is maximum.

### Standard input

The first line contains $3$ integers $N$, $M$ and $K$.

Each of the next $M$ lines contains $3$ integers $A$, $B$ and $C$, representing an edge between nodes $A$ and $B$ having cost $C$.

### Standard output

Print a line containing two integers:

The first integer is the maximum number of optimal paths that can pass through the $K$ selected nodesThe second integer represents the number of ways of selecting the $K$ nodes such that the number of optimal paths passing through them is maximum. This value should be printed modulo $10^{9}+7$.

### Constraints and notes

$1 \leq N \leq 300$ $N - 1 \leq M \leq \frac{N(N - 1)}{2}$ $1 \leq A, B \leq N$ $1 \leq C \leq 10^9$ $1 \leq K \leq N$ It is guaranteed that the first value you need to output is strictly positive and that it fits in a 64 bit signed integer.

| Input | Output | Explanation |
| --- | --- | --- |
| 4 5 3<br>1 3 2<br>1 2 1<br>2 3 1<br>2 4 2<br>3 4 1 | 2 2 | 211211234 The distance between $1$ and $4$ is $3$. There are $3$ possible paths of minimum cost from the node $1$ to node $4$: $\{(1, 2, 4), (1, 3, 4), (1, 2, 3, 4)\}$. You can choose the $3$ special nodes as  $\{1, 2, 4\}$, then the $2$ following optimal paths will pass through all of them: $\{(\bold{1}, \bold{2}, \bold{4}), (\bold{1}, \bold{2}, \bold{3}, 4)\}$. You can also choose the $3$ special nodes as $\{1, 3, 4\}$. In this case, the following $2$ paths will pass through all of them: $\{(\bold{1}, 2, \bold{3}, \bold{4}), (\bold{1}, \bold{3}, \bold{4})\}$. |
| 8 10 2<br>1 2 3<br>1 3 5<br>2 4 4<br>4 3 2<br>4 5 1<br>5 6 3<br>6 8 1<br>5 7 2<br>7 6 1<br>7 8 2 | 6 6 | The distance from $1$ to $8$ is $12$.There are $6$ paths of such cost: $(1, 2, 4, 5, 7, 8)$ $(1, 3, 4, 5, 7, 8)$ $(1, 2, 4, 5, 7, 6, 8)$ $(1, 3, 4, 5, 7, 6, 8)$ $(1, 2, 4, 5, 6, 8)$ $(1, 3, 4, 5, 6, 8)$ You can choose the following subsets of $2$ nodes: $\{\{1, 4\}, \{1, 5\}, \{1, 8\}, \{4, 5\}, \{4, 8\}, \{5, 8\}\}$. |
