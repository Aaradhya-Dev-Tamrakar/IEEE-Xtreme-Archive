# Count BST

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/count-bst/](https://csacademy.com/contest/archive/task/count-bst/)  

---

A binary search tree is a binary tree in which every node has an associated value which is strictly greater than all values in his left subtree and strictly less than all values in his right subtree.

You are given $N$, $K$ and an array of $K$ distinct integers, $A$.

Count the number of binary search trees of $N$ nodes, over the values $\{1, 2, .., N\}$, which contain the ordered sequence $A_1, A_2, .., A_K$ as a path.

Print this value modulo $10^9 + 7$.

### Standard input

The first line contains $T$, the number of tests.

Each of the following $T$ tests will be described by at most $2$ lines:

The first line contains two integers separated by space, $N$ and $K$.If $K \neq 0$, then second line contains $K$ distinct integers, the array $A$.If $K = 0$, then there will NOT be a second (blank) line in the input. 

### Standard output

Print $T$ lines, each containing the answer for one test.

### Constraints and notes

$1 \leq T \leq 2*10^5$ $1 \leq N \leq 3*10^6$ $0 \leq K \leq N$ and $\sum K \leq 2*10^5$  over all $T$ tests$1 \leq A_i \leq N$ $A_i \neq A_j$ for $i \neq j$

| Input | Output |
| --- | --- |
| 2<br>10 3<br>2 7 5<br>10 5<br>1 7 4 6 2 | 84<br>0 |
