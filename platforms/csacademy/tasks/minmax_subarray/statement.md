# MinMax Subarray

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/minmax_subarray/](https://csacademy.com/contest/archive/task/minmax_subarray/)  

---

You are given an array of size $N$. The elements of the array are not necessarily distinct. Find the shortest subarray that contains at least one of the minimum and one of the maximum values.

### Standard input

The first line contains a single integer value $N$.

The second line contains $N$ integer values representing the elements of the array.

### Standard output

The output should contain a single integer representing the length of the wanted subarray.

### Constraints and notes

$1 \leq N \leq 5 000$The values of the array will be between $0$ and $10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 7<br>1 5 9 7 1 9 4 | 2 | Choose the subarray $(1, 9)$ starting at position $5$. |
| 4<br>5 5 5 5 | 1 |  |
| 11<br>55 23 99 10 23 55 7 99 5 1 2 | 3 | $(99, 5, 1)$ at position $8$. |
