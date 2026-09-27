# Consecutive Sum

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/consecutive-sum/](https://csacademy.com/contest/archive/task/consecutive-sum/)  

---

You are given a number $N$. Write $N$ as a sum of at least $2$ positive consecutive integers.

### Standard input

The first line contains a single integer $N$.

### Standard output

Print two integers $A$ and $B$, representing the smallest and the largest terms. Basically, $N$ should be equal to $A + (A + 1) + ... + B$. If there are multiple solutions you can output any of them.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq A < B$

| Input | Output | Explanation |
| --- | --- | --- |
| 7 | 3 4 | $3+4=7$ |
| 15 | 1 5 | $1+2+3+4+5=15$ |
| 4 | -1 |  |
