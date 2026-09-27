# Tree Nodes Destruction

**Time Limit:** `1000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/tree-nodes-destruction/](https://csacademy.com/contest/archive/task/tree-nodes-destruction/)  

---

You are given a tree with $N$nodes and $M$ paths in this tree. You should destroy a subset of nodes such that each of the $M$ paths will contain at least one destroyed node. Compute the minimum possible size of such a subset.

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $N-1$ lines contains two integer values, representing two nodes that share an edge.

Each of the next $M$ lines contains two integer values, representing the two ends of a path.

### Standard output

The output should contain a single integer representing the minimum possible number of destroyed nodes.

### Constraints and notes

$1$ ≤ $N$, $M$ ≤ $10^5$

| Input | Output |
| --- | --- |
| 5 2<br>1 2<br>2 3<br>2 4<br>2 5<br>1 5<br>3 4 | 1 |
| 5 2<br>1 2<br>2 3<br>2 4<br>1 5<br>3 5<br>2 4 | 1 |
| 8 4<br>1 2<br>1 3<br>3 4<br>3 5<br>5 6<br>5 7<br>4 8<br>5 6<br>8 3<br>3 7<br>1 4 | 2 |
