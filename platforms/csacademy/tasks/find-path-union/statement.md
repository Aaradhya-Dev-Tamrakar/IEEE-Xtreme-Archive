# Find Path Union

**Time Limit:** `1250 ms`  
**Memory Limit:** `64 MB`  
**Source:** [https://csacademy.com/contest/archive/task/find-path-union/](https://csacademy.com/contest/archive/task/find-path-union/)  

---

Consider a full binary tree with an infinite number of levels. The vertices are labeled with positive integers, starting from the root and moving down the tree, from left to right on each level. In the example below you can see the first $4$ levels of the tree:

123456789101112131415

You are given $N$ nodes. Count the number of edges that lie on at least one path from one of the given nodes to the root.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the given nodes.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 5 * 10^5$ The numbers representing the nodes are distinct integers between $1$ and $10^{18}$ Please check the memory limit, it might be tighter than you think.

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>6 7 | 3 | 1234567 |
| 1<br>10 | 3 |  |
| 3<br>3 4 5 | 4 | 1234567 |
| 4<br>10 6 2 15 | 7 |  |
