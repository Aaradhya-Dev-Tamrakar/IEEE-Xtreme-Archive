# Decreasing Subarrays

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/decreasing-subarrays/](https://csacademy.com/contest/archive/task/decreasing-subarrays/)  

---

You are given an array $A$ of $N$ integers. For each index $i$, find the size of the longest decreasing subarray that contains $A_i$.

### Standard input

The first line contains a single integer $N$.

The second line contains the $N$ elements of $A$.

### Standard output

Print $N$ values on the first line, representing the answers for each index $i$, $1 \leq i \leq N$.

### Constraints and notes

$1 \leq N \leq 10^5$ $0 \leq A_i \leq 10^5$

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>3 2 1 1 4 | 3 3 3 1 1 | Note that $3\ 2\ 1\ 1$ is not decreasing . |
| 5<br>1 2 3 2 1 | 1 1 3 3 3 |  |
