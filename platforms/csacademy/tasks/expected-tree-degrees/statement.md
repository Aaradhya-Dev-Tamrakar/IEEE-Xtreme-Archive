# Expected Tree Degrees

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/expected-tree-degrees/](https://csacademy.com/contest/archive/task/expected-tree-degrees/)  

---

We consider trees with $N$ nodes, 0-indexed, randomly generated using the following algorithm:

Start with a single node, labeled with $0$.Subsequently add the rest of the nodes, labeled from $1$ to $N-1$ by creating an edge between each node $x$ and $rand()\ mod\ x$.

We define the cost of a tree as $\sum_{i=0}^{N-1} degree_{i}^2$.

Compute the expected cost of such a tree.

### Standard input

The first line contains a single integer $N$.

### Standard output

Output a single real number representing the expected cost.

### Constraints and notes

$1 \leq N \leq 10^6$Your result should differ from the official one by less than $10^{-6}$ with absolute precision.

| Input | Output | Explanation |
| --- | --- | --- |
| 1 | 0.000000000000000 | The only graph is0 |
| 2 | 2.000000000000000 | The only graph is01 |
| 3 | 6.000000000000000 | There are 2 posible graphs012012 |
| 6 | 20.866666666666666 |  |
