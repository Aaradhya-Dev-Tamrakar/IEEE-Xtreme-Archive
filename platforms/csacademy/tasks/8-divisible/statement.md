# 8 Divisible

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/8-divisible/](https://csacademy.com/contest/archive/task/8-divisible/)  

---

You are given a large number $N$. Can you permute its digits such that the new number is divisible by $8$?

If the solution is not unique, print the smallest one. Leading $0$s are not allowed.

### Standard input

The first line contains a single large number $N$.

### Standard output

If there is no solution output $-1$.

Otherwise, print the answer on the first line.

### Constraints and notes

The number of digits of $N$ is between $1$ and $1\,000$ $1 \leq N$

| Input | Output | Explanation |
| --- | --- | --- |
| 625 | 256 | $256$ is the only number divisible by $8$ we can obtain |
| 173 | -1 | There is no permutation of digits that creates a number divisible by $8$. |
| 2048 | 2048 | $0248$ is smaller, but leading $0$s are not allowed. |
