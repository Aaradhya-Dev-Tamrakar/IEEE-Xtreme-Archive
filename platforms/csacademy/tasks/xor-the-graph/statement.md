# Xor the Graph

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/xor-the-graph/](https://csacademy.com/contest/archive/task/xor-the-graph/)  

---

You are given a simple undirected graph with $N$ vertices and $M$ edges. Every edge has a binary value associated with it, either $0$ or $1$. An operation consists of choosing a path (not necessarily simple) and alternating the binary values of every edge. Make all the edges $0$ using minimum number of operations.

### Standard input

The first line contains two integers $N$ and $M$.

The next $M$ lines contain three integers $a$, $b$ and $c$, meaning there is an edge $(a, b)$ whose initial binary value is $c$.

### Standard output

Print the number of operations $K$ on the first line.

The next $K$ lines should contain the paths you've chosen:

It should start with $P$, the number of nodes in the path.The next $P$ integers $v_1, v_2, ..., v_P$ should be the indices of the nodes. For every $1 \leq i \leq P - 1$, $(v_i, v_{i+1})$ should be an edge in the given graph.

A solution is considered valid if  it uses the minimum number of operations and $\sum{P} \leq 4 * M$.

### Constraints and notes

$1 \leq N, M \leq 10^5$ $1 \leq  a, b \leq N$ $c \in \{0, 1\}$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 13 14<br>1 2 1<br>2 3 1<br>3 4 1<br>2 4 1<br>1 4 0<br>4 6 1<br>4 10 0<br>2 5 1<br>2 7 0<br>7 8 1<br>8 9 1<br>9 7 1<br>11 12 1<br>11 13 1 | 3<br>5 1 2 3 4 6<br>8 4 2 7 8 9 7 2 5<br>3 12 11 13 | 1111010101111110678921313451112 |
