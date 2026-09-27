# Tree Square

**Time Limit:** `500 ms`  
**Memory Limit:** `1 GB`  
**Source:** [https://csacademy.com/contest/archive/task/tree-square/](https://csacademy.com/contest/archive/task/tree-square/)  

---

The square of an undirected graph $G$ is a graph $G^2$ with the same nodes as $G$ having an edge between a pair of nodes $u$ and $v$ if and only if there is path of length at most $2$ between $u$ and $v$ in $G$.

You are given $G^2$ and you know that $G$ is a tree. You should determine the edges of $G$.

### Standard input

The first line contains the two integers $N$ and $M$, representing the number of nodes and the number of edges of $G^2$.

Each of the next $M$ lines contains two integer values, representing two nodes that share an edge in $G^2$.

### Standard output

Output $N-1$ lines corresponding to the $N-1$ edges of $G$. Each line should contain two integers $u$ and $v$ representing an edge in $G$. You can output the edges in any order.

### Constraints and notes

$2 \leq N \leq 333$$2 \leq M \leq N*(N-1)/2$The nodes are numbered from $1$ to $N$It is guaranteed there will be at least one solution.If the solution is not unique you can output any of them.

| Input | Output | Explanation |
| --- | --- | --- |
| 5 7<br>4 5<br>1 4<br>1 3<br>3 2<br>5 1<br>4 3<br>1 2 | 1 4<br>2 3<br>3 1<br>5 4 | Input graph12345Solution Graph12345 |
| 4 6<br>2 1<br>2 4<br>2 3<br>1 4<br>1 3<br>4 3 | 1 2<br>3 2<br>4 2 | Input graph1234Solution Graph1234 |
| 6 9<br>5 3<br>4 5<br>6 4<br>2 1<br>2 6<br>3 4<br>5 6<br>4 2<br>1 6 | 1 2<br>2 6<br>3 5<br>4 5<br>6 4 | Input graph123456Solution Graph123456 |
