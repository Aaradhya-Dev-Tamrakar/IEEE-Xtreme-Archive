# Swap Pairing

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/swap_pairing/](https://csacademy.com/contest/archive/task/swap_pairing/)  

---

You are given an array of $N$ values. It is guaranteed that $N$ is even and that each distinct value appears in the array exactly twice.

On this array, you can perform the following operation: choose two adjacent numbers and swap them. Compute the minimum number of operations needed such that each pair of equal numbers will be adjacent.

### Standard input

The first line contains a single integer $N$, the length of the array.

The second line contains the $N$ values of the array.

### Standard output

The output should contain a single integer representing the minimum number of operations needed.

### Constraints and notes

$1 \leq N \leq 10^5$The values of the array are between $0$ and $10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 8<br>7 3 5 3 7 6 5 6 | 5 | The swaps are as follows:$7\ 3\ 5\ \underline3\ \underline7\ 6\ 5\ 6$$7\ 3\ \underline5\ \underline7\ 3\ 6\ 5\ 6$$7\ \underline3\ \underline7\ 5\ 3\ 6\ 5\ 6$$7\ 7\ 3\ \underline5\ \underline3\ 6\ 5\ 6$$7\ 7\ 3\ 3\ 5\ \underline6\ \underline5\ 6$$7\ 7\ 3\ 3\ 5\ 5\ 6\ 6$ |
