# Flip the Edges

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/flip-the-edges/](https://csacademy.com/contest/archive/task/flip-the-edges/)  

---

You are given a tree with $N$ nodes. Each edge is either red or blue. You can choose any simple path in the tree and flip the colours of the edges: from red to blue and from blue to red.

For some of the edges you know whether you want their final state to be red or blue. The rest of the edges don't have any restrictions.

You should find the minimum number of paths you need to choose. Also, from all the solutions with minimum number of paths you want one with minimum sum of lengths.

### Standard input

The first line contains a single integer $N$.

Each of the next $N-1$ lines contains four integers $a$, $b$, $c$, $d$, representing an edge between nodes $(a, b)$ with initial colour $c$, where $c$ is $0$ if the edge is red, or $1$ if it's blue. The fourth number, $d$, is $0$ if the final colour of the edge should be red, $1$ if it should be blue, or $2$ if there are no restrictions concerning the edge.

### Standard output

Print two integers, the first one should be the minimum number of paths, the second one should be the minimum sum of lengths of the paths.

### Constraints and notes

$2 \leq N \leq 10^5$

| Input | Output |
| --- | --- |
| 5<br>2 1 1 0<br>1 3 0 1<br>2 4 1 2<br>5 2 1 1 | 1 2 |
| 3<br>1 3 1 2<br>2 1 0 0 | 0 0 |
| 6<br>1 3 0 1<br>1 2 0 2<br>2 4 1 0<br>4 5 1 0<br>5 6 0 2 | 1 4 |
