# Simple Paths

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/simple-paths/](https://csacademy.com/contest/archive/task/simple-paths/)  

---

You are given an simple undirected graph with $N$ nodes and $M$ edges and $Q$ queries. For each query, you are given two nodes, $x$ and $y$, and you must answer if there is only one simple path between $x$ and $y$.

### Standard input

The first line contains $N$, $M$ and $Q$.

Each of the next $M$ lines contains two integers, $x$ and $y$, meaning that there is an edge between node $x$ and node $y$.

Each of the next $Q$ lines contains two integers, $x$ and $y$, representing a query.

### Standard output

You will have to print $Q$ lines. The $i$-th line of the output will contain $1$ if the answer for the $i$-th query is yes and $0$ otherwise.

### Constraints and notes

$1 \leq N, M, Q \leq 1000$ $1 \leq x, y \leq N$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 7 7 4<br>1 2<br>2 3<br>3 4<br>4 5<br>5 6<br>1 3<br>2 7<br>6 3<br>7 4<br>1 2<br>2 4 | 1<br>0<br>0<br>0 | 1234567 |
| 7 7 5<br>2 3<br>3 4<br>4 5<br>7 6<br>1 3<br>2 7<br>1 7<br>4 2<br>2 3<br>6 7<br>3 7<br>5 2 | 0<br>0<br>1<br>0<br>0 | 1234567 |
