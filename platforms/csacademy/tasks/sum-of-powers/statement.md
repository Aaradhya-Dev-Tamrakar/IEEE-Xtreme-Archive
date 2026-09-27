# Sum of Powers

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/sum-of-powers/](https://csacademy.com/contest/archive/task/sum-of-powers/)  

---

Given three integer values $N$, $M$ and $K$, consider all the multisets of positive integers $\{a_1, a_2, ..., a_K\}$ such that $a_1 + a_2 + ... + a_K = N$. For each multiset compute $a_1^M + a_2^M + ... + a_K^M$ and output the sum of all these values.

### Standard input

The first line contains the three integers $N$, $K$ and $M$.

### Standard output

Output a single number representing the wanted sum modulo $10^9+7$.

### Constraints and notes

$1 \leq N, M \leq 4096$$1 \leq K \leq N$

| Input | Output |
| --- | --- |
| 5 2 3 | 100 |
| 7 3 1 | 28 |
