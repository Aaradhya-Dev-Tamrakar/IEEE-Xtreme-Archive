# Best Array Cut

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/best-array-cut/](https://csacademy.com/contest/archive/task/best-array-cut/)  

---

You are given an array $v$ of $N$ integers. Split the array in two nonempty subarrays such that the absolute difference between the sum of elements of the two parts is as small as possible.

Splitting the array means choosing an index $i$ ($1\leq i < N$). The first subarray consists of elements $v_1, v_2,...v_i$, the second subarray consists of $v_{i+1}, v_{i+2},...v_N$.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the elements of the array.

### Standard output

Print a single integer representing the smallest possible absolute difference between the sum of elements of the two subarrays.

### Constraints and notes

$2 \leq N \leq 10^5$ The elements of the array are integers between $-100$ and $100$.

| Input | Output |
| --- | --- |
| 3<br>2 3 1 | 2 |
| 5<br>3 -2 5 -1 3 | 2 |
| 8<br>3 1 -2 7 -4 2 -3 1 | 1 |
