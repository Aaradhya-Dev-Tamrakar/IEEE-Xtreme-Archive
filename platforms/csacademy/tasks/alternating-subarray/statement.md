# Alternating Subarray

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/alternating-subarray/](https://csacademy.com/contest/archive/task/alternating-subarray/)  

---

You are given an array of $N$ integers. We call a subarray between indices $i$ and $j$ alternating if $v_i < v_{i+1} > v_{i+2} < ... v_j$ or $v_i > v_{i+1} < v_{i+2} > ... v_j$. Find the length of the longest alternating subarray.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the elements of the array.

### Standard output

Output a single integer representing the length of the longest alternating subarray.

### Constraints and notes

$1 \leq N \leq 10^5$The values of the array are integers between $1$ and $10^6$A subarray of length $1$ is considered alternating

| Input | Output |
| --- | --- |
| 5<br>1 3 1 1 2 | 3 |
| 3<br>1 1 1 | 1 |
