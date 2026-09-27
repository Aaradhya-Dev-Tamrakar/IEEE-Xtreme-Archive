# Virus on a Tree

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/virus-on-a-tree/](https://csacademy.com/contest/archive/task/virus-on-a-tree/)  

---

You are given a tree with $N$ nodes. In node $1$ there is a virus that's about to spread to all the other nodes it can reach by traversing the edges.

Fortunately, you have some time to remove some edges before the virus starts to spread. For each edge you know whether you are allowed to remove it or not. Your goal is to find the minimum number of edges you need to cut such that the virus will be present in at most $K$ nodes after spreading (including node $1$).

### Standard input

The first line contains two integers $N$ and $K$.

Each of the next $N-1$ lines contains three integers $a$, $b$ and $c$. The first two, $a$ and $b$, represent two nodes that share an edge, while $c$ is $1$ if the edge can be removed, $0$ otherwise.

### Standard output

If there is no solution, output $-1$.

Otherwise, print the minimum number of edges you should remove.

### Constraints and notes

$1 \leq K \leq N \leq 10^5$

| Input | Output | Explanation |
| --- | --- | --- |
| 6 4<br>3 5 1<br>1 2 0<br>2 3 1<br>3 4 0<br>5 6 1 | 1 | We can cut the edge $(3, 5)$:10101123456 |
| 4 2<br>1 4 0<br>1 2 0<br>3 4 1 | -1 | We are allowed to cut edge $(3, 4)$, but the virus would still spread to $3$ nodes:0011234 |
| 7 3<br>1 2 1<br>2 3 1<br>1 4 1<br>4 6 1<br>6 5 1<br>6 7 1 | 1 | We should cut the edge $(1, 4)$:1111111234657 |
| 4 4<br>1 4 0<br>4 3 0<br>3 2 0 | 0 | Don't cut any edge:0001234 |
