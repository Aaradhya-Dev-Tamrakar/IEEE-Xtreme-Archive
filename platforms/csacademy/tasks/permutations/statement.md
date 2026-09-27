# Permutations

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/permutations/](https://csacademy.com/contest/archive/task/permutations/)  

---

You are given an integer $N$ and $Q$ queries. Each query consists of two integers $x$ and $y$. For each query compute the number of permutations $P$ of length $N$ that satisfy the conditions below:

$P_y\ =\ max_{i=1}^{y}\  P_{i}$ $2 \times P_x < P_y$ 

### Standard input

The first line contains two integers $N$ and $Q$.

Each of the following $Q$ lines contains two integers $x$ and $y$.

### Standard output

You should output $Q$ lines, each containing the answer for a query, modulo $998244353$.

### Constraints and notes

$2 \leq N \leq 10^5$ $1 \leq Q \leq 10^5$ For each query $1 \leq x < y \leq N$

| Input | Output |
| --- | --- |
| 4 1<br>2 4 | 2 |
