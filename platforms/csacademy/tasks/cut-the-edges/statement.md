# Cut the Edges

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/cut-the-edges/](https://csacademy.com/contest/archive/task/cut-the-edges/)  

---

You are given an undirected connected graph with $N$ nodes and $N$ edges. For each edge print:

$-1$ if deleting the edge disconnects the graphThe diameter of the resulting tree otherwise

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines contains two integers representing two nodes that share an edge.

### Standard output

Print $N$ lines, each corresponding to an edge, in the order given in the input. On each line print either $-1$, or the size of the diameter of the associated tree.

### Constraints and notes

$3 \leq N \leq 10^5$

| Input | Output |
| --- | --- |
| 8<br>1 2<br>2 4<br>4 7<br>7 1<br>1 3<br>7 5<br>4 6<br>6 8 | 5<br>5<br>6<br>5<br>-1<br>-1<br>-1<br>-1 |
| 8<br>1 2<br>2 8<br>8 6<br>6 5<br>5 1<br>1 4<br>4 3<br>5 7 | 6<br>5<br>4<br>5<br>7<br>-1<br>-1<br>-1 |
