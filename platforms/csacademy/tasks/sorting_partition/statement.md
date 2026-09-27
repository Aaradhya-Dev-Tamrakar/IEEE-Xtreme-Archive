# Sorting Partition

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/sorting_partition/](https://csacademy.com/contest/archive/task/sorting_partition/)  

---

You are given an array of $N$ integers. You should partition this array into subarrays and sort each subarray independently. If performing these sorting operations leads to the entire array being sorted, we call the partition valid. You need to find a valid partition with maximum number of subarrays.

### Standard input

The first line contains a single integer $N$, the length of the array.

The second line contains the $N$ values of the array.

### Standard output

The output should contain a single number representing the maximum number of subarrays of a valid partition.

### Constraints and notes

$1 \leq N \leq 10^5$The values of the array are between $0$ and $10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 7<br>3 1 2 4 100 7 9 | 3 | You should partition the array into the following subarrays: $(3, 1, 2)$, $(4)$ and $(100, 7, 9)$. |
| 7<br>2 1 2 3 3 4 3 | 5 | Notice the array doesn't contain unique numbers: $(2, 1)$, $(2)$, $(3)$, $(3)$ and $(4, 3)$. |
