# Consecutive Digits Signs

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/consecutive-digit-signs/](https://csacademy.com/contest/archive/task/consecutive-digit-signs/)  

---

You are asked to find a number with $N$ digits. Let's denote by $d_i$ the $i$-th digit of the number. You are given an array $A$ of $N-1$ integers:

$A_i = -1$ if $d_i < d_{i+1}$ $A_i = 0$ if $d_i = d_{i+1}$ $A_i = 1$ if $d_i > d_{i+1}$ 

If the solution is not unique, you should find the largest number that respects the restrictions.

### Standard input

The first line contains a single integer $N$.

The second line contains $N-1$ integers representing the elements of $A$.

### Standard output

If there is no solution output $-1$.

Otherwise, print the largest valid number.

### Constraints and notes

$2 \leq N \leq 10^5$

| Input | Output |
| --- | --- |
| 8<br>1 1 1 0 1 1 1 | 98766543 |
| 10<br>1 1 0 -1 -1 -1 0 1 1 | 9866789987 |
| 11<br>-1 -1 0 1 1 0 0 1 -1 -1 | 78998777689 |
