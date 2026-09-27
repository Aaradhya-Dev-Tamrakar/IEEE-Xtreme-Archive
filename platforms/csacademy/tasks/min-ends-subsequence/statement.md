# Min Ends Subsequence

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/min-ends-subsequence/](https://csacademy.com/contest/archive/task/min-ends-subsequence/)  

---

You are given a permutation of size $N$. Find the longest subsequence having the property that the first and the last elements are greater than all the other subsequence elements.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the permutation.

### Standard output

Print a single integer representing the length of the longest valid subsequence.

### Constraints and notes

$1 \leq N \leq 10^5$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>1 2 3 4 5 | 2 | 1, 2 |
| 5<br>3 1 5 2 4 | 4 | 3, 1, 2, 4 |
| 6<br>4 2 6 5 3 1 | 3 | 4, 2, 3 |
