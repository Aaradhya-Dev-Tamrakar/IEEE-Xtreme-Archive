# Subarrays Xor Sum

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/subarrays-xor-sum/](https://csacademy.com/contest/archive/task/subarrays-xor-sum/)  

---

You are given an array of $N$ integers. For each subarray with a length between $A$ and $B$ compute the xor sum of its elements. Output the sum of all these xor values modulo $10^9+7$.

### Standard input

The first line contains three integers $N$, $A$ and $B$.

The second line contains $N$ integers representing the elements of the array.

### Standard output

Output a single integer representing the result modulo $10^9+7$.

### Constraints and notes

$1 \leq A \leq B \leq N \leq 10^5$The elements of the array are integers between $0$ and $10^9$.

| Input | Output |
| --- | --- |
| 4 2 3<br>1 2 3 4 | 16 |
| 5 1 1<br>3 7 100 21 1 | 132 |
