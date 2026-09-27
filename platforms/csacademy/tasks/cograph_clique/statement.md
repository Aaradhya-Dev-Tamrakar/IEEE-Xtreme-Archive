# Cograph Clique

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/cograph_clique/](https://csacademy.com/contest/archive/task/cograph_clique/)  

---

A cograph is an undirected graph that respects one of the following properties:

It's a graph with 1 node and no edges.It's the graph union of two or more cographs.It's the complement graph of a cograph.

You are given a cograph where each node has an associated weight. Find a clique of maximum weight, i.e. the sum of the weights of the nodes in the clique should be maximum.

### Standard input

The first line contains two integer values $N$ and $M$, representing the number of nodes and the number of edges in the graph.

The second line contains $N$ integer values corresponding to the weights of the nodes.

Each of the next $M$ lines contains two integer values, representing two nodes that share an edge.

### Standard output

The first line of the output should consist of a single integer representing the maximum weight of a clique.

The second line should consist of a single integer $K$ representing the number of nodes in the chosen clique.

The third line should consist of $K$ values representing the indices of the chosen nodes.

### Constraints and notes

$1$ ≤ $N$ ≤ $300$$1$ ≤ $M$ ≤ $N * (N-1) / 2$The weights of the nodes are integers between $1$ and $10^6$If there are more solutions you can output any of them

| Input | Output |
| --- | --- |
| 4 3<br>7 1 2 3<br>2 3<br>2 4<br>3 4 | 7<br>1<br>1 |
| 5 1<br>3 2 1 2 1 <br>3 4 | 3<br>1<br>1 |
| 8 8<br>3 2 3 1 1 3 2 1 <br>1 3<br>2 3<br>4 5<br>4 6<br>4 7<br>4 8<br>5 6<br>7 8 | 6<br>2<br>1 3 |
| 5 6<br>1 3 5 9 4 <br>1 3<br>1 5<br>2 3<br>2 5<br>3 5<br>4 5 | 13<br>2<br>4 5 |
