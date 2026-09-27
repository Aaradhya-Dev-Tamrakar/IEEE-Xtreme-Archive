# Path Union

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/path-union/](https://csacademy.com/contest/archive/task/path-union/)  

---

Consider a full binary tree of height $N$. You are allowed to select some of the tree's nodes. For each $i$, $1 \leq i \leq N$, you can select at most $A_i$ nodes at depth $i$.

For each selected node $v$, we take the path from $v$ to the root and mark all of its edges. Maximize the number of marked edges. An edge can be marked multiple times, but it should only be counted once.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the elements of $A$.

### Standard output

We consider the label of the root to be $1$. For each node $i$ that is not a leaf, its left son has label $2*i$ and its right son has label $2*i+1$.

Print the distinct labels of the selected nodes, each on a different line.

### Constraints and notes

$1 \leq N \leq 60$ $0 \leq A_i \leq 2^i$ $1 \leq \sum_{i=1}^{N}A_i \leq 10^5$

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>1 1 | 2<br>7 | The number of marked edges is $3$ |
| 3<br>1 2 4 | 2<br>5<br>6<br>9<br>11<br>12<br>14 | The number of visited edges is $10$ |
| 5<br>1 2 1 2 1 | 3<br>7<br>5<br>14<br>20<br>24<br>32 | The number of marked edges is $14$ |
