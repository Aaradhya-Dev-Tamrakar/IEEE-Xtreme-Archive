# Subarray Medians

**Time Limit:** `1250 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/subarray-medians/](https://csacademy.com/contest/archive/task/subarray-medians/)  

---

You are given a permutation of size $N$. For every odd length subarray compute its median value.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the elements of the array.

### Standard output

For every pair $(i, j)$, such that $1 \leq i \leq j \leq N$ and $j-i \equiv 0\ mod\ 2$, compute $i * j * median$. You should output the sum of all these values.

### Constraints and notes

$1 \leq N \leq 10^4$You don't need to use the formula $(i * j * median)$ to solve the problem, it's meant to reduce output.The result fits in a 64 bit integer.

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>1 5 2 4 3 | 276 | There are 9 valid subarrays:$[1, 1]$: the median is $1$ and the cost $1 * 1 * 1 = 1$$[1, 3]$: the median is $2$ and the cost $1 * 3 * 2 = 6$$[1, 5]$: the median is $3$ and the cost $1 * 5 * 3 = 15$$[2, 2]$: the median is $5$ and the cost $2 * 2 * 5 = 20$$[2, 4$: the median is $4$ and the cost $2 * 4 * 4 = 32$$[3, 3]$: the median is $2$ and the cost $3 * 3 * 2 = 18$$[3, 5]$: the median is $3$ and the cost $3 * 5 * 3 = 45$$[4, 4]$: the median is $4$ and the cost $4 * 4 * 4 = 64$$[5, 5]$: the median is $3$ and the cost $5 * 5 * 3 = 75$The sum is $1 + 6 + 15 + 20 + 32 + 18 + 45 + 64 + 75 = 276$ |
| 5<br>1 5 4 3 2 | 259 |  |
| 6<br>1 2 3 4 5 6 | 714 |  |
