# Sort All

**Time Limit:** `2000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/sortall/](https://csacademy.com/contest/archive/task/sortall/)  

---

Let $f$ be a function which maps an arbitrary array of integers $A$ to the integer value $1 * S_1 + 2 * S_2 + 3 * S_3 + \ldots + K * S_K = \sum_{i=1}^{K} i * S_i$, where $S_1, S_2, \ldots, S_K$ are the distinct values of $A$, sorted increasingly.

Given an array of integer $V$, compute the sum of $f$ applied to all subarrays of $V$, i.e. $\sum_{1 \leq i \leq j \leq N} f(V[i \ldots j])$.

Print this value modulo $10^9 + 7$.

### Standard input

The first line contains an integer, $N$.

The next line contains $N$ values, denoting $V$.

### Standard output

Print the answer modulo $10^9 + 7$ on the first line.

### Constraints and notes

$1 \leq N \leq 5 * 10^4$ $1 \leq V_i \leq N$ for $1 \leq i \leq N$

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>1 3 3 | 24 | $f([1, 3, 3]) = 1 * 1 + 2 * 3 = 7$ $f([1, 3]) \ \ \  \ = 1 *  1 + 2 * 3 = 7$ $f([1]) \ \ \  \ \ \  \ \ = 1 * 1 = 1$ $f([3, 3]) \ \ \ \ = 1 * 3 = 3$   $f([3]) \ \ \ \  \ \ \ \ = 1 * 3 = 3$   $f([3]) \ \ \ \ \ \ \ \ = 1 * 3 = 3$  The answer being $7 + 7 + 1 + 3 + 3 + 3 = 24$ |
| 8<br>4 3 4 4 7 1 2 1 | 861 |  |
