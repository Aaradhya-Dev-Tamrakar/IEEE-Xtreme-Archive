# Connecting the Graph

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/connecting-the-graph/](https://csacademy.com/contest/archive/task/connecting-the-graph/)  

---

You are given a graph with $N$ Vertices and $M$ edges. Each node $i$ has attached a number $A_i$. You can add a new edge to the graph between vertices $i$ and $j$ with the cost $(A_i-A_j)^2$.

You are allowed to add as many edges as you wish to the graph. What is the minimum cost required to make the graph connected? (i.e. there exists a path between any two nodes)

### Standard input

The first line contains the numbers $N$ and $M$. On the next line there are $N$ integers: $A_1, A_2, ..., A_N$.

In each of the next $M$ lines there are two numbers $x$ and $y$, representing an edge of the graph between the nodes $x$ and $y$.

### Standard output

The first line of the output should contain a single integer, the answer to the problem.

### Constraints and notes

$1 \leq N \leq 10^5$ $0 \leq M \leq 2 * 10^5$ $0 \leq A_i \leq 10^7$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 5 3<br>1 2 3 6 5<br>1 3<br>1 2<br>2 3 | 5 | The edges that must be added are (3, 5) with cost 4 and (4, 5) with cost 1 |
