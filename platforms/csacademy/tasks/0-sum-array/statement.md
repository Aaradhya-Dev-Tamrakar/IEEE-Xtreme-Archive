# 0-Sum Array

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/0-sum-array/](https://csacademy.com/contest/archive/task/0-sum-array/)  

---

You are given an array of $N$ integers. Find the smallest index of an element such that if you multiply it by $-1$ the sum of the whole array becomes $0$.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the elements of the array.

### Standard output

Print the index of the element or $-1$ if there is no solution.

### Constraints and notes

$1 \leq N \leq 1000$ for each element $X$ from the array, $-1000 \leq X \leq 1000$,

| Input | Output |
| --- | --- |
| 5<br>1 3 -5 3 4 | 2 |
| 4<br>1 2 4 8 | -1 |
| 5<br>5 3 6 -7 -4 | -1 |
