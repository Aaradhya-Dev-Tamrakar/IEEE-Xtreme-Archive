# Increasing Subarrays

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/increasing_subarrays/](https://csacademy.com/contest/archive/task/increasing_subarrays/)  

---

You are given an array of $N$ integers. On each element of the array you can apply the following operation: increment its value by $1$. You are allowed to apply multiple operations on the same element.

You should count the number of subarrays respecting the following property: they can be made monotonic increasing using at most $M$ operations.

### Standard input

The first line contains two integer values $N$ and $M$.

The second line contains $N$ integer values representing the elements of the array.

### Standard output

The output should consist of a single integer representing the number of wanted subarrays.

### Constraints and notes

$1$ ≤ $N$ ≤ $10^6$$1$ ≤ $M$ ≤ $10^{15}$The elments of the array are integers between $1$ and $10^9$For 25% of the test cases, $N \leq 1000$For 50% of the test cases, $N \leq 10^5$

| Input | Output |
| --- | --- |
| 6 6<br>5 4 1 1 5 5 | 18 |
| 5 3<br>5 4 3 2 1 | 12 |
| 10 35<br>6 1 10 2 7 3 9 4 8 5 | 54 |
