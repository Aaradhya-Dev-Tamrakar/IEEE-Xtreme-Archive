# Monotone Subarray

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/monotone-subarray/](https://csacademy.com/contest/archive/task/monotone-subarray/)  

---

You are given an array $A$ of size $N$. Consider the following definitions:

An array is non-increasing if for every $i$, $A_i \geq A_{i+1}$. Similarly, it is non-decreasing if for every $i$, $A_i \leq A_{i+1}$.An array is monotone if it is non-increasing or non-decreasing.

Find the longest monotone subarray.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers represent the elements of $A$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq A_i \leq 2 * 10^5$

| Input | Output | Explanation |
| --- | --- | --- |
| 7<br>1 2 3 4 3 2 1 | 4 | The longest monotone array is $1\ 2\ 3\ 4$ |
| 5<br>3 2 1 1 2 | 4 | $3\ 2\ 1\ 1$ |
| 7<br>1 2 2 2 3 3 4 | 7 | The whole array is non-decreasing |
| 9<br>3 4 2 1 1 4 5 6 3 | 5 | $1\ 1\ 4\ 5\ 6$ |
