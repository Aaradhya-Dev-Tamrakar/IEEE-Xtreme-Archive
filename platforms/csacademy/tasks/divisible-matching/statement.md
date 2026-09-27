# Divisible Matching

**Time Limit:** `4000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/divisible-matching/](https://csacademy.com/contest/archive/task/divisible-matching/)  

---

You are given a bipartite graph with labels on the edges and an integer $K$. Each of its parts contain $N$ vertices. Is there any perfect matching in this graph such that the sum of the labels on its edges is divisible by $K$?

### Standard input

The first line contains two integers $N$ and $K$.

Each of the next $N$ lines contain $N$ integers $a_{ij}$. If there are no edge between $i^{th}$ vertex in the first part and $j^{th}$ vertex in the second part, $a_{ij} = -1$, otherwise $a_{ij}$ is equal to the label on this edge.

### Standard output

Print Yes if such a matching exists, and No otherwise.

### Constraints and notes

$1 \le K, N \le 100$ $-1 \le a_{ij} < K$

| Input | Output |
| --- | --- |
| 3 3<br>0 0 -1<br>-1 1 0<br>1 -1 2 | Yes |
| 3 2<br>0 0 -1<br>-1 0 0<br>1 -1 1 | No |
| 3 2<br>0 1 0<br>-1 -1 0<br>-1 -1 1 | No |
