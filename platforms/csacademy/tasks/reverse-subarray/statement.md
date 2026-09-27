# Reverse Subarray

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/reverse-subarray/](https://csacademy.com/contest/archive/task/reverse-subarray/)  

---

You are given an array $A$ of $N$ integers. You should choose exactly one subarray and reverse it. After this operation, $A$ should be non-decreasing.

Find the number of subarrays you can choose and print one possible solution.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the elements of $A$.

### Standard output

If there is no solution, output a single integer $0$.

Otherwise, print on the first line a single integer representing the number of subarrays you can reverse to get a non-decreasing $A$.

On the second line print two integers representing the leftmost and rightmost indices of the subarray. If the solution is not unique print the one with the smallest left index. If the solution is still not unique, print the one with the smallest right index.

### Constraints and notes

$1 \leq N \leq 10^5$ $0 \leq A_i \leq 10^5$ 

| Input | Output |
| --- | --- |
| 5<br>2 2 3 3 2 | 1<br>3 5 |
| 4<br>3 6 4 5 | 0 |
| 3<br>1 2 3 | 3<br>1 1 |
