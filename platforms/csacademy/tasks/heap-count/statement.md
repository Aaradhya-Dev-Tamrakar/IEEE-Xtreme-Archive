# Heap Count

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/heap-count/](https://csacademy.com/contest/archive/task/heap-count/)  

---

A min-heap can be represented as a 1-indexed array $A$. The value of the root is in $A_1$, the left son of $i$ is $2*i$ and the right son is $2*i+1$. The value of a node should be less than the values of its (at most) two sons.

Count the number of arrays $A$ of $N$ elements that:

Contain all the numbers from $1$ to $N$ Are valid heaps$A_x = y$, for two given values $x$ and $y$ 

### Standard input

The first line contains three integers $N$, $x$ and $y$.

### Standard output

Print the answer modulo $10^9+7$.

### Constraints and notes

$1\leq N \leq 10^5$ $1\leq x,y \leq N$

| Input | Output | Explanation |
| --- | --- | --- |
| 5 5 3 | 2 | The 2 solutions are 1 2 5 4 31 2 4 5 3Represented as trees, the solutions look like12543 12453 |
| 5 3 3 | 2 | 1 2 3 4 5 1 2 3 5 4 |
| 5 1 1 | 8 | 1 2 3 4 51 2 3 5 41 2 4 3 51 2 5 3 41 2 4 5 31 2 5 4 31 3 2 4 5 1 3 2 5 4 |
| 6 3 4 | 4 | 1 2 4 3 5 61 2 4 3 6 51 2 4 5 3 61 2 4 6 3 5 |
| 6 3 3 | 6 | 1 2 3 4 5 61 2 3 4 6 51 2 3 5 4 61 2 3 6 4 51 2 3 5 6 41 2 3 6 5 4 |
