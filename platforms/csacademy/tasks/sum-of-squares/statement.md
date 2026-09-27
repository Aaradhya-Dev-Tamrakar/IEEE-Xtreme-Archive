# Sum of Squares

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/sum-of-squares/](https://csacademy.com/contest/archive/task/sum-of-squares/)  

---

Given two integer values $N$ and $K$, consider all the sets of positive integers $\{a_1, a_2, ..., a_K\}$ such that $a_1 + a_2 + ... + a_K = N$. For each set compute $a_1^2 + a_2^2 + ... + a_K^2$ and output the sum of all these values.

### Standard input

The first line contains the two integers $N$ and $K$.

### Standard output

Output a single number representing the wanted sum modulo $10^9+7$.

### Constraints and notes

$1 \leq N \leq 10000$$1 \leq K \leq N$

| Input | Output | Explanation |
| --- | --- | --- |
| 5 1 | 25 | The only valid set is $\{5\}$ |
| 5 3 | 20 | There are 2 valid sets:$\{1, 1, 3\}$ and $\{1, 2, 2\}$, having the sum of squares equal to $1^2 + 1^2+3^2=11$ and $1^2 + 2^2 + 2^2 = 9$, respectively. |
| 5 5 | 5 | The only valid set is $\{1, 1, 1, 1, 1\}$. |
