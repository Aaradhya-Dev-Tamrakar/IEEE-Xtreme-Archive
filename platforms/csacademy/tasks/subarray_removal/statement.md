# Subarray Removal

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/subarray_removal/](https://csacademy.com/contest/archive/task/subarray_removal/)  

---

You are given an array of $N$ integers. You should remove a non-empty subarray of size at most $N-1$. Then you should compute the maximum sum subarray in the resulting array. Find out the maximum value you can get.

### Standard input

The first line contains a single integer value $N$.

The second line contains $N$ integers representing the elements of the array.

### Standard output

The output should contain a single integer, the wanted answer.

### Constraints and notes

$2 \leq N \leq 10^5$The elements of the array will be between $-10^9$ and $10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>10 -2 3 -10 5 | 16 | We eliminate ${-10}$, and the remaining array is the maximum sum subarray: $10\ {-2} \ 3\ 5$. |
| 7<br>-3 2 -1 5 -7 9 -10 | 15 | We eliminate ${-7}$. The resulting array is: ${-3}\ 2\ {-1}\ 5\ 9\ {-10}$. The maximum sum subarray is: $2\ {-1}\ 5\ 9$. |
