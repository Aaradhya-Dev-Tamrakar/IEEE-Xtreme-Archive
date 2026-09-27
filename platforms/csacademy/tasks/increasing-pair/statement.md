# Increasing Pair

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/increasing-pair/](https://csacademy.com/contest/archive/task/increasing-pair/)  

---

You are given an array $A$ of length $N$ representing a permutation. Find two indices $i$ and $j$ such that:

$i<j$ $A_i < A_j$ $j - i$ is maximized

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the permutation.

### Standard output

If there is no solution print $-1$.

Otherwise, output a single integer representing the maximum difference $j-i$ between a valid pair of indices.

### Constraints and notes

$2\leq N \leq 10^5$ 

| Input | Output |
| --- | --- |
| 4<br>1 3 4 2 | 3 |
| 5<br>3 5 1 4 2 | 3 |
