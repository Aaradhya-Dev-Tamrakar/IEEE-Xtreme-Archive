# Max Wave Array

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/max-wave-array/](https://csacademy.com/contest/archive/task/max-wave-array/)  

---

An array $A$ is called wave array if $A_1 > A_2 < A_3 > A_4 < ...$

Given an array $A$, permute its elements such that it becomes a wave array. If the solution is not unique, find the largest lexicographical one.

### Standard input

The first line contains a single integer $N$ representing the size of $A$.

The second line contains $N$ integeres, the elements of $A$.

### Standard output

Print a single line containing the $N$ elements of the new array.

### Constraints and notes

$1 \leq N \leq 10^5$The elements of $A$ are distinct integers between $0$ and $10^9$.

| Input | Output |
| --- | --- |
| 3<br>1 2 3 | 3 1 2 |
| 2<br>1 2 | 2 1 |
| 1<br>1 | 1 |
