# Uniform Trees

**Time Limit:** `4000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/uniform-trees/](https://csacademy.com/contest/archive/task/uniform-trees/)  

---

You are given a rooted tree with $N$ nodes, conveniently labeled from $1$ to $N$. Node $1$ is the root of the tree. For each node $i \geq 2$, the parent of the node is $p_i$.

Each node in this tree also has value $v_i$.

Define a rooted tree to be uniform, if for each node, all of its direct children have the same value.

Define a subset of nodes $S$ of the given tree to be uniform if the following holds:

There is exactly one node in $S$ which does not have any proper ancestor which is also in $S$.Construct a temporary tree from the nodes in $S$, where the parent of a node is its closest proper ancestor in $S$. There will be exactly one node that is denoted as the root. This resulting tree must be uniform.

Given a tree, count the number of uniform subsets of nodes, modulo $10^9+7$.

### Standard input

The first line contains an integer $N$.

The next $N$ lines of input will contain two integers each, $p_i, v_i$.

### Standard output

Print out a single integer, the number of uniform subsets, modulo $10^9+7$.

### Constraints and notes

$1 \leq N \leq 200\,000$ $1 \leq p_i < i$ for $2 \leq i \leq N$ $p_1$ will be equal to $-1$.$1 \leq v_i \leq N$

| Input | Output | Explanation |
| --- | --- | --- |
| 6<br>-1 3<br>1 2<br>1 2<br>1 2<br>1 5<br>1 5 | 16 | In this case, the good subsets are {1}, {2}, {3}, {4}, {5}, {6}, {1,2}, {1,3}, {1,4}, {1,2,3}, {1,2,4}, {1,3,4}, {1,2,3,4}, {1,5}, {1,6}, {1,5,6} |
