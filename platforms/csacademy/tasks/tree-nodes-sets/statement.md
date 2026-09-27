# Tree Nodes Sets

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/tree-nodes-sets/](https://csacademy.com/contest/archive/task/tree-nodes-sets/)  

---

You are given a rooted tree with $N$ nodes, where node $1$ is the root. In each node there is a set of numbers, that is initially empty. Then, starting from the root and moving down to the leaves, we have operations of the type:

For all the sets of the nodes in the subtree of the current node, including the node itself, insert/erase a certain value.

Find the size of each set at the end of the process.

### Standard input

The first line contains a single integer $N$.

The second line contains $N-1$ integers, the $i^{th}$ value being the father of node $i+1$.

Each of the next $N$ lines contains the description of the operations for the nodes, in order. The first value $K$ on each line represents the number of operations for the current node, and it's followed by exactly $K$ integers describing the operations themselves. If a number $x$ is positive then you should insert $x$, otherwise if $x$ is negative you should erase $|x|$.

### Standard output

Print $N$ lines, each containing the size of the set associated with a node, in order.

### Constraints and notes

$1 \leq N \leq 10^5$ $0 \leq\sum K_i \leq 10^5$ $-10^5 \leq x \leq 10^5$, $x \neq 0$ All the operations for the ancestors of a node $i$ are performed before the operations for $i$ Inserting a value $x$ in a set that already contains it does nothingTrying to erase a value $x$ from a set that doesn't contain it does nothingFor a node $i$, $x$ and $-x$ cannot both be in its list of operationsFor a node $i$, a value $x$ can only occur once

| Input | Output |
| --- | --- |
| 1<br><br>5 1 -2 3 -4 5 | 3 |
| 5<br>1 1 5 2<br>3 1 -2 5<br>2 -2 3<br>2 -5 3<br>2 2 3<br>2 2 3 | 2<br>3<br>2<br>4<br>4 |
